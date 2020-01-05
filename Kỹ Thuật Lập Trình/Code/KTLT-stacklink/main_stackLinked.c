/*
 * main.c
 *
 *  Created on: Apr 4, 2012
 *      Author: hoannh
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "stacklinked.h"


int main(int argc, char **argv) {
	setvbuf(stdout,NULL,_IONBF,0);
	struct node* head = NULL;
	int size,element,counter = 0;

	/*
		 stack size is dynamic and
	  	 specified at runtime
	*/
	printf("Enter stack size:");
	scanf("%d",&size);

	printf("Push elements to stack\n");
	init(head);
	while(counter < size)
	{
		 getchar();
         element = rand();
		 printf("push element %d into stack\n",element);
         head = push(head,element);
		 counter++;
    }
	printf("Pop elements from stack\n");
	while(0 == empty(head))
	{
		head = pop(head,&element);
		printf("pop element %d from stack\n",element);
		getchar();
	}

	return 0;
}


