/*
 * lietkecacdinhcotheditu_x.c
 *
 *  Created on: Oct 25, 2012
 *      Author: NgoHuong
 */


#include <stdlib.h>
#include <stdio.h>

enum {hs = 50};

int x, y, n, m;
int a[hs][hs], b[hs], q[hs];

char *fi="dulieu.txt";

void tb(char *s)
{
	puts(s);
	exit(0);
}

void doctep()
{
	int i, j, k;
	FILE *f;
	f = fopen(fi, "r");
	if (!f)
		tb("Loi mo tep");
	fscanf(f, "%d%d", &n, &m);
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			a[i][j] = 0;
	for (k=0; k<m; k++)
	{
		fscanf(f, "%d%d", &i, &j);
		a[i][j] = 1;
	}
	fclose(f);
}

int cung(int i, int j)
{
	return a[i][j] > 0;
}

void lietke(int x)
{
	int i, d, c;
	for (i=1; i<=n; i++)
		b[i] = 0;
	d = c = 1;
	q[1] = x;
	b[x] = 1;
	while (d <= c)
	{
		y=q[d];;
		d++;
		for (i=1; i<=n; i++)
		{
			if (b[i]==0 && cung(y, i))
			{
				++c;
				q[c] = i;
				b[i] = 1;
			}
		}
	}
	printf("\nCac di dinh co the di toi %d la:\n", x);
	for (i=2; i<=c; i++)
	{
		printf("%5d", q[i]);
	}
	puts(" ");

}

int main()
{
	setbuf(stdout, NULL);
	doctep();
	printf("x = ");scanf("%d", &x);
	lietke(x);
	//printf("\nKhong co dinh nao di tu %d", x);
	return 0;
}
