/*
 * main.c
 *
 *  Created on: Nov 7, 2012
 *      Author: student
 */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "tree.h"

int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	typedef struct Node *Tree;
	int a[] = {3, 1, 8, 0, 2, 6, 9, 5, 7};
	Tree root = NULL;

	int i, tong_la;
	int tong_nut_rong, tong_nut;
	int tong_nut_day_du;
	for (i = 0; i < 9; i++) {
		addNode(&root, a[i]);
	}
	printf("Visit preOrder: \n");
	preOrder(root);
	printf("\nVisit inOrder: \n");
	inOrder(root);
	printf("\nVisit postOrder: \n");
	postOrder(root);
	printf("\nNRL: \n");
	NRL(root);
	printf("\nRNL: \n");
	RNL(root);
	printf("\nRLN: \n");
	RLN(root);
	/*NLR(root);
	 printf("\n");
	 LNR(root);
	 printf("\n");
	 LRN(root);
	 printf("\n");*/

	tong_la = dem_nut_la(root);
	printf("\nTong so nut la     = %d \n", tong_la);

	printf("\nSo nut trung gian cua cay = %d \n", dem_nut_tg(NULL, root));

	tong_nut = dem_nut(root);
	printf("\nTong so nut cua cay = %d \n", tong_nut);

	tong_nut_rong = dem_nut_rong(root);
	printf("\nTong so nut rong    = %d \n", tong_nut_rong);

	tong_nut_day_du = dem_nut_day_du(root);
	printf("\nTong so nut day du = %d \n", tong_nut_day_du);

	printf("\nChieu cao cua cay = %d \n", chieucao(root, 0));
	ancestor(root,5,3);

	printf("\nKich thuoc cua mot nut la: %d \n", sizeOfTree(root));
	return 0;
}

