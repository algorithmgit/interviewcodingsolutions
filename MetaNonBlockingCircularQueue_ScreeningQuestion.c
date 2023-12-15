#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    char array[MAX_SIZE];
    int front; 
    int rear; 
    int size;
} NonBlockingCircularQueue;

void initQueue(NonBlockingCircularQueue *queue){
    queue->front = 0; 
    queue->rear = 0; 
    queue->size = 0;
    return;
}

int availableSpace(NonBlockingCircularQueue *queue){
    return MAX_SIZE - queue->size; 
}

int usedSpace(NonBlockingCircularQueue *queue){
    return queue->size;
}

int writeData(NonBlockingCircularQueue *queue, const char *data, int length){
    int available = availableSpace(queue);
    int toWrite = (length < available) ? length : available;
    
    for(int i = 0; i < toWrite; i++){
        queue->array[queue->rear] = data[i];
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    
    queue->size += toWrite;
    return toWrite;
}

int readData(NonBlockingCircularQueue *queue, char *output, int length){
    int used = usedSpace(queue); 
    int toRead = (length < used)? length : used;
    
    for(int i = 0; i < toRead; i++){
        output[i] = queue->array[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    
    queue->size -= toRead;
    
    return toRead;
}

int main() {
    NonBlockingCircularQueue queue; 
    initQueue(&queue);
    
    char dataToWrite[] = "Hello, Circular Queue"; 
    char dataToRead[MAX_SIZE];
    
    int bytesWritten = writeData(&queue, dataToWrite, strlen(dataToWrite));
    printf("Bytes Written: %d\n", bytesWritten);
    
    int bytesRead = readData(&queue, dataToRead, sizeof(dataToRead));
    printf("Bytes read: %d\n", bytesRead);
    printf("Data read: %.*s\n", bytesRead, dataToRead);
    
    return 0;
}

/*
Output:
Bytes Written: 10
Bytes read: 10
Data read: Hello, Cir
*/





