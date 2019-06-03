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

	writefd = open(P2C_FIFO, O_WRONLY);
	if (writefd < 0){
		perror("Can't open p2c fifo");
		return 1;
	}

	if ((readfd = open(C2P_FIFO, O_RDONLY)) < 0){
		perror("Can't open c2p fifo");
		return 1;
	}

	while(1){
		memset(buf, 0, 250);
		cout << "Please type something: ";
		if (fgets(buf, 250, stdin) <= 0){
			perror("Can't read data from keyboard");
			break;
		}
		if (write(writefd, buf, 250) <= 0){
			perror("Can't write data to consumer");
			break;
		}
		memset(buf, 0, 250);
		if (read(readfd, buf, 250) <= 0){
			perror("Can't read data from consumer");
			break;
		}
		puts(buf);
	}
	close(writefd);
	close(readfd);
	return 1;
}


