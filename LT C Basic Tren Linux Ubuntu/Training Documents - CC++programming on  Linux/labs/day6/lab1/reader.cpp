#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_MSG_SIZE 250
int main(int argc, char* argv[])
{
	if (argc != 2){
		printf("Invalid argument\n");
		return 1;
	}
	long mtype = atoi(argv[1]);
	if ((mtype < 1) | (mtype > 3)){
		printf("Invalid argument, please choose mtype between 1 to 3\n");
		return 1;
	}
	key_t key = ftok("key.txt", 'a');
	int msgid = msgget(key, 0);
	msgbuf* buf = (msgbuf*)malloc(sizeof(msgbuf) + MAX_MSG_SIZE + 1);
	while(1){
		if (msgrcv(msgid, buf, MAX_MSG_SIZE + 1, mtype, 0) == -1){
			perror("Can't receive message from queue");
			return 1;
		}
		printf("Recevice message from queue:\n");
		printf("\tmtype: %d - message: %s\n", buf->mtype, buf->mtext);
	}	
	return 0;
}
