#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>
#include <iostream>
using namespace std;

struct request{
	int number;
	request* next_req;
};

request *head,*tail;
static int num = 0;
volatile int thread_true = 1;

pthread_mutex_t mutex;
pthread_cond_t cond;

void *getReq(void *arg){
	int i = (int)arg;
	while(thread_true){
		pthread_mutex_lock(&mutex);
		if (head == NULL){
			cout << "thread "<<i<<": head is NULL, wait for new request\n";
			pthread_cond_wait(&cond, &mutex);
		}
		if (head == NULL)
		{
			cout << "thread "<<i<<": head still is NULL\n";
			pthread_mutex_unlock(&mutex);
			continue;
		}
		cout << "thread "<<i<<":Get request out from list: \n";
		cout << "thread "<<i<<":	number: " << head->number << endl;
		request* tmp = head;
		head = head->next_req;
		free(tmp); 
		if (head == NULL){
			tail = NULL;
		}
		pthread_mutex_unlock(&mutex);
	}
}

void addReq(){
	pthread_mutex_lock(&mutex);
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
		pthread_cond_signal(&cond);
	}
	cout << "Add request to list: \n";
	cout << "	number: " << tail->number << endl;
	pthread_mutex_unlock(&mutex);
	sleep(1);
}

int main(){
	mutex = PTHREAD_MUTEX_INITIALIZER;
	cond = PTHREAD_COND_INITIALIZER;
	pthread_t thread[3];
	head = NULL;
	tail = NULL;
	for (int i = 0; i < 3; i++){
		pthread_create(&thread[i], 0, getReq, (void*)i);
	}
	for (int i = 0; i < 60; i++){
		addReq();
	}
	thread_true = 0;
	sleep(1);
	return 0;
}	
