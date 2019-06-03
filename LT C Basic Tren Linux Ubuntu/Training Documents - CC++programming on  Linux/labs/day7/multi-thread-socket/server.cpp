#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <string.h>
#include <pthread.h>
#include "sock_defs.h"

void *do_client(void* arg){
	int client_fd = int(arg);
	char buf[250];
    memset(buf, 0, 250);
	if (read(client_fd, buf, 250) <= 0){
		perror("Can't read data from client, client closed");
		close(client_fd);
		return NULL;
	}
	printf("Text received from client: ");
	puts(buf);
	int i = 0;
	while(buf[i]){
		buf[i] = toupper(buf[i]);
		i++;
	}
	if (write(client_fd, buf, strlen(buf) + 1) <= 0){
		perror("Can't write data to client");
		return NULL;
	}
	close(client_fd);
}

int main(int argc, char* argv[]){
    int server_fd;
    socklen_t server_len, client_len;
    struct sockaddr_in server_addr, client_addr;
    int res;
    int newpid;
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1){
        perror("Can't creat a new server socket");
        exit(1);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    server_len = sizeof(server_addr);
    
    res = bind(server_fd, (sockaddr*)&server_addr, server_len);
    if (res == -1){
        perror("Can't bind server socket");
        exit(1);
    }
    
    res = listen(server_fd, 5);
    if (res == -1){
        perror("Can't listen server socket");
        exit(1);
    }
    
    client_len = sizeof(client_addr);
    signal(SIGCHLD, SIG_IGN);
    while(1){
        printf("Sever is waiting\n");
        int client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_len);
        if (client_fd == -1){
            perror("Can't accept a new connection");
            exit(1);
        }
        char hostbuf[255];
        char portbuf[255];
        res = getnameinfo((sockaddr*)&client_addr, client_len, hostbuf, 255, portbuf, 255, NI_NUMERICHOST | NI_NUMERICSERV);
        if (res == 0){
            printf("Accepted connection on descriptor %d "
                   "(host=%s, port=%s)\n", client_fd, hostbuf, portbuf);
        }
        pthread_t newthread;
        if (pthread_create(&newthread, 0, do_client, (void*)client_fd) == -1){
        	perror("pthread_create");
        	exit(1);
        }
    }
    exit(0);
}

