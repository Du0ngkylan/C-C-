/*
 * tontaiDuongDi.c
 *
 *  Created on: Oct 22, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>

enum {hs = 50};

int a[hs][hs], b[hs];

int x, y, n, m;

void tb(char *s)
{
	puts(s);
	exit(0);
}

char *fi="tontaiDuongDi.txt";

void doctep()
{
	int i, j, k;
	FILE *f;
	f = fopen(fi, "r");
	if (!f) tb ("Loi mo tep");
	fscanf(f, "%d%d", &n, &m);
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			a[i][j] = 0;
	for (k=0; k<m ;k++)
	{
		fscanf(f, "%d%d", &i, &j);
		a[i][j] = 1;
	}
	fclose(f);
}

void khoidau()
{
	int i;
	for (i=1; i<=n; i++)
	{
		b[i] = 1;
	}
}

int cung(int i, int j)
{
	return a[i][j] > 0;
}

void inmt()
{
	int i, j;
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}

void tim(int k)
{
	int i;
	if (k==y) {tb("Co duong di ");return ;}
	for (i=1; i<=n; i++)
	{
		if( b[i]==1 && cung(k, i))
		{
			b[i] = 0;
			tim(i);
		}
	}
	//printf("Khong co duong di");
}

int main()
{
	setbuf(stdout, NULL);
	doctep();
	inmt();
	printf("\nNhap x= ");scanf("%d", &x);
	printf("\nNhap y= ");scanf("%d", &y);
	b[x] = 0;
	tim(x);
	printf("\nKhong co duong");
	return 0;
}
