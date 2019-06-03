#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/ioctl.h>
#include <iostream>
#include <string.h>
#include "sock_defs.h"

int main(int argc, char* argv[]){
    int server_fd, client_fd;
    socklen_t server_len, client_len;
    sockaddr_in server_addr, client_addr;
    int res;
    char buf[250];
    fd_set readfds, testfds;
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("Can't creat a new server socket");
        exit(1);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    
    server_len = sizeof(server_addr);
    
    if (bind(server_fd, (sockaddr*)&(server_addr), server_len) == -1){
        perror("Can't bind server socket");
        exit(1);
    }
    
    if (listen(server_fd, 5) == -1){
        perror("Can't listen connection");
        exit(1);
    }
    
    FD_ZERO(&readfds);
    
    FD_SET(server_fd, &readfds);
    
    while(1){
        int fd;
        int nread;
        
        testfds = readfds;
        
        printf("Server is waiting\n");
        
        res = select(FD_SETSIZE, &testfds, (fd_set*)0, (fd_set*)0, (timeval*)0);
        if (res < 1){
            perror("Can't select any terminator");
            exit(1);
        }
        
        for (fd = 0; fd < FD_SETSIZE; fd ++){
            if (FD_ISSET(fd, &testfds)){
                if (fd == server_fd){
                    printf("Accept a new connection\n");
                    client_len = sizeof(client_addr);
                    if ((client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_len)) == -1){
                        perror("Can't accept a new connection");
                        exit(1);
                    }
                    FD_SET(client_fd, &readfds);
                } else {
                    ioctl(fd, FIONREAD, &nread);
                    if (nread == 0){
                        perror("Don't have any data to read");
                        close(fd);
                        FD_CLR(fd, &readfds);
                        printf("Remove %d socket\n", fd);
                    } else {
                    	memset(buf, 0, 250);
                        res = read(fd, buf, 250);
                        if (res < 0){
                            perror("Can't read data from client");
                            close(fd);
                            exit(1);
                        }
                        printf("Data read from client: %s\n",buf);
						int i = 0;
						while(buf[i]){
							buf[i] = toupper(buf[i]);
							i++;
						}
                        res = write(fd, buf, strlen(buf) + 1);
                        if (res < 0){
                            perror("Can't write data to client");
                            close(fd);
                            exit(1);
                        }
                    }
                
                }
            }
        }
    }
    exit(0);
}
