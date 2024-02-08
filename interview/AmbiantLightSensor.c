#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define VALID 1
#define MAX_TIMESTAMPS 600  // One entry for each second in the last 10 minutes

struct SensorReading {
    int status;
    float lux;
    uint64_t timestamp;  // time of reading
};

struct AmbientLightSensor {
    struct SensorReading latestReading;
    struct SensorReading latestValidReading;
    struct SensorReading* readings;
    size_t numReadings;
    pthread_mutex_t mutex;
    pthread_cond_t condition;
};

void initAmbientLightSensor(struct AmbientLightSensor* als) {
    als->numReadings = 0;
    als->readings = NULL;
    pthread_mutex_init(&als->mutex, NULL);
    pthread_cond_init(&als->condition, NULL);
}

void updateReading(struct AmbientLightSensor* als, struct SensorReading reading) {
    pthread_mutex_lock(&als->mutex);

    als->latestReading = reading;

    if (reading.status == VALID) {
        als->latestValidReading = reading;

        // Add the reading to the array
        als->numReadings++;
        als->readings = realloc(als->readings, als->numReadings * sizeof(struct SensorReading));
        als->readings[als->numReadings - 1] = reading;

        // Remove readings older than 10 minutes
        time_t tenMinutesAgo = time(NULL) - 600;

        size_t numValidReadings = 0;
        for (size_t i = 0; i < als->numReadings; ++i) {
            if (als->readings[i].timestamp >= tenMinutesAgo) {
                als->readings[numValidReadings++] = als->readings[i];
            }
        }

        // Update the count of valid readings
        als->numReadings = numValidReadings;
    }

    pthread_cond_broadcast(&als->condition);
    pthread_mutex_unlock(&als->mutex);
}

void destroyAmbientLightSensor(struct AmbientLightSensor* als) {
    pthread_mutex_lock(&als->mutex);
    free(als->readings);
    als->numReadings = 0;
    pthread_mutex_unlock(&als->mutex);

    pthread_mutex_destroy(&als->mutex);
    pthread_cond_destroy(&als->condition);
}

float getMostRecentLux(struct AmbientLightSensor* als) {
    pthread_mutex_lock(&als->mutex);
    float lux = als->latestValidReading.lux;
    pthread_mutex_unlock(&als->mutex);
    return lux;
}

float getLuxAt(struct AmbientLightSensor* als, uint64_t timestamp) {
    pthread_mutex_lock(&als->mutex);

    while (als->numReadings == 0) {
        // Wait for valid readings
        pthread_cond_wait(&als->condition, &als->mutex);
    }

    float lux = -1.0f; // Indicates that lux value at the given timestamp is not available.

    // Iterate over the array to find the timestamp
    for (size_t i = 0; i < als->numReadings; ++i) {
        if (als->readings[i].timestamp == timestamp) {
            lux = als->readings[i].lux;
            break;
        }
    }

    pthread_mutex_unlock(&als->mutex);
    return lux;
}

// Function to simulate ALS readings (replace this with read_next_sample)
struct SensorReading read_next_sample() {
    // Simulate ALS readings
    struct SensorReading reading = {VALID, (float)rand() / RAND_MAX * 100.0f, time(NULL)};
    return reading;
}

void* simulateALSReadings(void* arg) {
    struct AmbientLightSensor* als = (struct AmbientLightSensor*)arg;

    while (1) {
        // Call read_next_sample to obtain ALS readings
        struct SensorReading reading = read_next_sample();

        // Update the ALS with the obtained reading
        updateReading(als, reading);

        // Sleep for a random time between 0 and 1 second
        usleep((rand() % 1000) * 1000);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    struct AmbientLightSensor als;
    initAmbientLightSensor(&als);

    // Create a thread for simulating ALS readings
    pthread_t alsThread;
    pthread_create(&alsThread, NULL, simulateALSReadings, (void*)&als);

    // Example usage in the main thread
    while (1) {
        // Use the ALS data in the main thread
        printf("Most recent Lux: %.2f\n", getMostRecentLux(&als));

        uint64_t timestampToQuery = als.latestReading.timestamp;  // Use the latest timestamp for testing
        printf("Lux at timestamp %" PRIu64 ": %.2f\n", timestampToQuery, getLuxAt(&als, timestampToQuery));

        // Sleep for a short time before the next iteration
        usleep(500000);  // Sleep for 0.5 seconds
    }

    // Clean up and join the ALS thread
    pthread_join(alsThread, NULL);
    destroyAmbientLightSensor(&als);

    return 0;
}
