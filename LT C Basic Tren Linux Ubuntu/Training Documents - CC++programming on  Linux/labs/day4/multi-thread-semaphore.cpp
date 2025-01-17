#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <iostream>
using namespace std;

struct request{
	int number;
	request* next_req;
};

request *head,*tail;
static int num = 0;
volatile int thread_true = 1;

sem_t hasRq;

void *getReq(void *arg){
	int i = (int)arg;
	while(thread_true){
		sem_wait(&hasRq);
		cout << "thread "<<i<<":Get request out from list: \n";
		cout << "thread "<<i<<":	number: " << head->number << endl;
		request* tmp = head;
		head = head->next_req;
		free(tmp); 
		if (head == NULL){
			tail = NULL;
		}
		sleep(2);
	}
}

void addReq(){
	request* tmp = (request*)malloc(sizeof(request));
	tmp->number = num++;
	tmp->next_req = NULL;
	if (tail != NULL){
		tail->next_req = tmp;
		tail = tmp;
	}
	else {
		head = tmp;
		tail = tmp;
	}
	cout << "Add request to list: \n";
	cout << "	number: " << tail->number << endl;
	sem_post(&hasRq);
	sleep(1);
}

int main(){
	sem_init(&hasRq, 0, 0);
	pthread_t thread[3];
	head = NULL;
	tail = NULL;
	for (int i = 0; i < 3; i++){
		pthread_create(&thread[i], 0, getReq, (void*)i);
	}
	for (int i = 0; i < 15; i++){
		addReq();
	}
	thread_true = 0;
	sleep(1);
	return 0;
}	
