/*
 * in_out.c
 *
 *  Created on: Sep 25, 2012
 *      Author: NgoHuong
 */
#include "in_out.h"
#include <stdio.h>
#include <stdlib.h>
int *nhap_mang(int n)
{
	int i;
	int *a;
	a = (int*)malloc(n*sizeof(int));
	for (i=0; i<n; i++)
	{
		printf("\nNhap a[%d]= ", (i+1));
		scanf("%d", (a+i));
	}
	return a;
}

void in_mang(int *a, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%5d", *(a+i));
	}
}
