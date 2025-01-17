#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shared_defs.h"

int main(){
	key_t key = ftok(KEY_FILE, ID);
	int shmid = shmget(key, SHARED_SIZE, IPC_CREAT | 0666);
	if (shmid == -1){
		shmid = shmget(key, SHARED_SIZE, 0);
		if (shmid == -1){
			perror("Can't get shared memory");
			return 1;
		}
	}
	char* addr = (char*)shmat(shmid, 0, 0);
	if (addr == NULL){
		perror("Can't attach shared memory to process");
		return 1;
	}
	int* stop = (int*)addr;
	country *con = (country*)((char*)addr+sizeof(int));
	printf("Write Vietnam to shared memory\n");
	con->pop = 96000000;
	strcpy(con->name, "Vietnam");
	strcpy(con->cap, "Hanoi");
	strcpy(con->cur, "Dong");
	*stop = 1;
	while(*stop == 1){};
	printf("Write America to shared memory\n");
	(con+1)->pop = 1000000000;
	strcpy((con+1)->name, "America");
	strcpy((con+1)->cap, "Wasinton DC");
	strcpy((con+1)->cur, "USD");
	*stop = 1;
	while(*stop == 1){};
	if (shmdt(addr) == -1){
		perror("Can't detach shared memory");
		return 1;
	}
	return 0;
}
