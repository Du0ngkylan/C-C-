#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_MSG_SIZE 250
int main(){
	key_t key = ftok("key.txt", 'a');
	int msgid = msgget(key, 0666 | IPC_CREAT);
	char msg[MAX_MSG_SIZE + 1];
	for (int i = 0; i < 100; i++){
		memset(msg, 0, 50);
		sprintf(msg, "Hello world - %d", i);
		msgbuf* buf = (msgbuf*)malloc(strlen(msg)+sizeof(msgbuf));
		strcpy(buf->mtext, msg);
		buf->mtype = rand() % 3 + 1;
		if (msgsnd(msgid, buf, strlen(msg)+1, 0) == -1){
			perror("Can't send message to queue");
			return 1;
		}
	}
	return 0;
}
