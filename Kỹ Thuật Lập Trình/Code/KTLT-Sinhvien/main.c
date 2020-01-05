/*
 * main.c
 *
 *  Created on: Oct 6, 2012
 *      Author: MSS THUY
 */
#include<stdio.h>
#include"queue.h"
#include<stdlib.h>
#include <conio.h>

int main(int argc, char **argv) {
	setvbuf(stdout,NULL,_IONBF,0);
	char x[20],s[30];
	node *head=NULL;
	head=doctep(head);
	in(head);
		printf("mang sau khi sap xep la:\n");
	head=sapxep(head);
	printQueue(head);
	puts("nhap ten can chen:\t");
	gets(s);
	head=chen(head,s);
	in(head);
	printQueue(head);
	//strcpy(s,deQueue(head));
	printf("%s\n",s);
	in(head);
	printf("nhap phan tu can xoa:\t");
	gets(x);
	printf("mang sau khi xoa la:\n");
	head=xoa(head,x);
	in(head);

	return 0;
}

