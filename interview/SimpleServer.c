#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 6000
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char response[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to localhost
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Read the query parameters from the client
    valread = read(new_socket, buffer, BUFFER_SIZE);
    int num1, num2;
    sscanf(buffer, "GET /sum?num1=%d&num2=%d", &num1, &num2);

    // Calculate the sum
    int sum = num1 + num2;

    // Prepare the response
    sprintf(response, "HTTP/1.1 200 OK\n\nSum: %d\n", sum);

    // Send the response back to the client
    send(new_socket, response, strlen(response), 0);
    printf("Response sent: %s\n", response);
    return 0;
}

/*
cat Makefile
CC = gcc
CFLAGS = -Wall

all: http_server http_client

http_server: http_server.c
	$(CC) $(CFLAGS) -o http_server http_server.c

clean:
	rm -f http_server
*/

/* Run 
(echo 'GET /sum?num1=1&num2=12 HTTP/1.0'; echo) | nc localhost 6000 
HTTP/1.1 200 OK

Sum: 13
*/
