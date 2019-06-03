#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>
#include "define.h"
using namespace std;

int main(){
	int readfd, writefd;
	char buf[250];
	if (access(P2C_FIFO, F_OK) == -1){
		if (mkfifo(P2C_FIFO, 0666) < 0){
			perror("Can't create P2C fifo");
			return 1;
		}
	}
	if (access(C2P_FIFO, F_OK) == -1){
		if (mkfifo(C2P_FIFO, 0666) < 0){
			perror("Can't create C2P fifo");
			return 1;
		}
	}
	
	if ((readfd = open(P2C_FIFO, O_RDONLY)) < 0){
		perror("Can't open p2c fifo");
		return 1;
	}
	
	if ((writefd = open(C2P_FIFO, O_WRONLY)) < 0){
		perror("Can't open c2p fifo");
		return 1;
	}
	
	while(1){
		memset(buf, 0, 250);
		if (read(readfd, buf, 250) <= 0){
			perror("Can't read data from producer");
			break;
		}

		int i = 0;
		while(buf[i]){
			buf[i] = toupper(buf[i]);
			i++;
		}

		if (write(writefd, buf, 250) <= 0){
			perror("Can't write data to producer");
			break;
		}
	}
	close(writefd);
	close(readfd);
	return 1;
}


