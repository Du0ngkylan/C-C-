/*
 * bai5.c
 *
 *  Created on: Oct 30, 2012
 *      Author: Student
 */

//tinh kich thuoc cua mot cay la so cac nut
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "SizeOfNode.h"

int main(int argc, char **argv) {
	setbuf(stdout, NULL);
	int a[] = {3, 1, 8, 0, 2, 6, 9, 5};
	Tree root = NULL;
	int i;
	for (i = 0; i < 8; i++) {
		root = addNode(root, a[i]);
	}
	int size;
	size= sizeOfNode(root,3);
	printf("kich thuoc cua mot nut la: %d", size);
	return 0;
}
