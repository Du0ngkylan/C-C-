/*
 * main_linklist_student.c
 *
 *  Created on: Oct 17, 2012
 *      Author: ADMIN
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "linklist_student.h"

int main(int argc, char **argv) {
	setvbuf(stdout,NULL,_IONBF,0);
	student*a;
	a=doctep("sv.txt");
	a=(struct student*)malloc(n*sizeof(struct student));
	printf("%d",n);
	printList(a);
	return 0;
}


