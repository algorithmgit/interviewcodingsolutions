#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_SIZE 1024

struct frame {
    void *buffer;
    int buffer_len;
    … // add if necessary
};

struct packet {
    uint32_t dest_port;
    uint32_t payload_len;
    uint8_t payload[0];
};

int read_offset;
int write_offset;
struct frame *ring_of_frames[1024];

void net_ctrl_init(... /* TODO */);

mutex_t read_lock;



void frames_written_cb(void)
{
    struct packet *tpkt = (struct packet *)ring_of_frames[read_offset];
    pthread_mutex_lock(&read_lock);
    read_offset++;
    pthread_mutex_unlock(&read_lock);

}

void init(void)
{
    // Initialize ring of frames

    pthread_mutex_init(&read_lock, NULL); 

    for (int i = 0; i < MAX_SIZE; i++)
    {
        ring_of_frames[i]->buffer = malloc(sizeof(char) * MAX_SIZE));
        ring_of_frames[i]->buffer_len = MAX_SIZE;
    }

    read_offset = -1; 
    write_offset = -1;

    net_ctrl_init(ring_of_frames, 1024, &read_offset, &write_offset, frames_written_cb);
}

// Called by client to read a packet
// dest_port: the port that the client wants to read from
// buf: buffer to receive the packet payload
// buf_len: size of buf
// return: size of the data copied to buf
int read_packet(uint32_t dest_port, void *buf, size_t buf_len)
{

}
