/*
 * main_songuyento.c
 *
 *  Created on: Oct 12, 2012
 *      Author: NgoHuong
 */

#include "songuyento.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	setbuf(stdout, NULL);
	struct Node *list;
	list = NULL;
	int n, i;
	printf("\nNhap n= ");scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		if (kt_primeNumber(i))
		{
			list = addNode(list, i);
		}
	}
	printf("\nDanh sach so nguyen to:\n");
	in_ds(list);
	struct Node *q;
	q = doiCho(list);
	printf("\nDanh sach da doic ho la:\n");
	in_ds(q);
	return 0;

}
