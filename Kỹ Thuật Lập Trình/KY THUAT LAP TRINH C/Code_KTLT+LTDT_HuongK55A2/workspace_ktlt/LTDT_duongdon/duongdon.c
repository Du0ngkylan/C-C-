/*
 * duongdon.c
 *
 *  Created on: Oct 24, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>

#define hs 50

int v[hs],b[hs],a[hs][hs];

int x, y, n,m;

void tb (char *s)
{
	puts (s);
	exit (0);
}
char *fi = "duongdon.txt";

void doctep ()
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

void khoidau()
{
	int i;
	for (i=1; i<=n; i++)
	{
		b[i] = 1;
	}
}

void lietke(int k)
{
	int i, j;
	if (k > n)
		return ;
	if (v[k] == y)
	{
		for (i=1; i<k; i++)
		{
			printf("%d--->", v[i]);
		}
		printf("%d", v[i]);
		exit(0);
	}
	for (i=1; i<=n; i++)
	{
		if (b[i] && cung(v[k], i))
		{
			v[k+1] = i;
			b[i] = 0;
			lietke(k+1);
			b[i] = 1;
		}
	}
}

int main()
{
	setbuf(stdout, NULL);
	doctep();
	khoidau();
	printf ("x=");
	scanf ("%d",&x);
	printf ("y=");
	scanf ("%d",&y);
	v[1] = x;
	b[x] = 0;
	lietke(1);
	printf("\nKhong co duong di");
	return 0;
}
