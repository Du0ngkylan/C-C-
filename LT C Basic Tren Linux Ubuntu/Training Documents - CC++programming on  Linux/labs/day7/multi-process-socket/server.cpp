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
#include "sock_defs.h"

int main(int argc, char* argv[]){
    int server_fd, client_fd;
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
        client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_len);
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
        newpid = fork();
        switch(newpid){
        case -1: perror("Can't creat a child process"); exit(1); break;
        case 0: {
        	char buf[250];
        	memset(buf, 0, 250);
            res = read(client_fd, buf, 250);
            if (res <= 0){
                perror("Can't read data from client, client closed");
                close(client_fd);
                break;
            }
            printf("Text received from client: ");
            puts(buf);
            int i = 0;
            while(buf[i]){
            	buf[i] = toupper(buf[i]);
            	i++;
            }
            res = write(client_fd, buf, strlen(buf) + 1);
            if (res <= 0){
                perror("Can't write data to client");
            }
            close(client_fd);
            exit(0);
            }
            break;
        default: close(client_fd); break;
        }       
    }
    exit(0);
}

