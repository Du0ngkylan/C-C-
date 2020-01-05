/*
 * main.c
 *
 *  Created on: Mar 15, 2012
 *      Author: ChiNV
 */

#include "stdio.h"
#include "linklist.h"
int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	struct Student *listStudent = NULL;
	listStudent = createList();
	printList( listStudent);
	sortList( listStudent);
	printList( listStudent);
	char name[] = "Hoang Thi Hoa";
	if(searchName(listStudent, name) != NULL)
		printf("Co");
	else
		printf("Khong co!");
	return 0;
}
