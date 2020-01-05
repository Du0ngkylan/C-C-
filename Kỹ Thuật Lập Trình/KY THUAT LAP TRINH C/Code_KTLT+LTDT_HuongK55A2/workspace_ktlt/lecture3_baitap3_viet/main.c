/*
 * main.c
 *
 *  Created on: Mar 6, 2012
 *      Author: MrThai
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"

int main(int argc, char **argv) {
	if (argc !=2)	{
		printf("re-enter data");
		exit(0);
	}
	char filename[30];
	strcpy(filename,argv[1]);
	node *list;
	list=createList (filename);
	printf("display list of word and its frequency....\n");
	printList(list);

	node *newList=reverse(list);
	printf("\n\nlist after reverse.....\n");
	printList(newList);
	printf("\n\nlist after sorted....\n");
	selectionSort(newList);
	printList(newList);
	return 0;
}

