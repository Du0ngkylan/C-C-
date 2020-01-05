/*
 * bt.c
 *
 *  Created on: Nov 8, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>

int nguyento(int k)
{
	int i;
	if (k < 2)
		return 0;
	for (i=2; i<=k/2; i++)
		if (k%i==0)
			return 0;
	return 1;
}

void nhap(int a[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("Nhap a[%d]= ", i+1);
		scanf("%d", (a+i));
	}
}

int main()
{
	setbuf(stdout, NULL);
	int  n, i;
	int a[100];
	printf("Nhap n= ");scanf("%d", &n);
	nhap(a, n);
	int s = 0;
	int dem = 0;
	for (i=0; i<n; i++)
	{
		if (nguyento(a[i]) == 1)
		{
			dem = dem +1;
			s = s+a[i];
		}
	}
	printf("co %d so nguyen to", dem);
	printf("\nTong: %d", s);
	return 0;
}
