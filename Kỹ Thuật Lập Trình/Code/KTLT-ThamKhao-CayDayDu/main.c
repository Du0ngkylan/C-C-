/*
 * cayDayDu.c
 *
 *  Created on: Oct 30, 2012
 *      Author: Student
 */
/*
 * cay_day_du.c
 *
 *  Created on: Oct 30, 2012
 *      Author: Student
 */

#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include "FullTree.h"
//KIEM TRA XEM CAY DO CO PHAI LA CAY DAY DU HAY KO?

int main(int argc, char **argv) {
	setbuf(stdout, NULL);
	typedef struct Node *Tree;
	int a[] = {3, 1, 8, 0, 2, 6, 9, 5, 4};
	Tree root = NULL;
	int i;
	for (i = 0; i < 8; i++) {
		root = addNode(root, a[i]);
	}
	if (isFull(root) == 0)
	printf("cay da cho la cay day du");
	else {
		printf("cay da cho ko la cay day du");
	}
	return 0;
}

