/*
 * xettinhlienthong.c
 *
 *  Created on: Oct 26, 2012
 *      Author: NgoHuong
 */
#include <stdio.h>
#include <stdlib.h>

enum {hs = 50};
int a[hs][hs], b[hs];

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

int ke(int i, int j)
{
	return a[i][j]+a[j][i] > 0;
}

void khoidau()
{
	int i;
	for (i=1; i<=n; i++)
	{
		b[i] = 1;
	}
}

void mang()
{
	int d, c,i, j, k;
	int q[hs];
	k = 1;
	d = c =1;
	q[1] = 1;
	b[1] = 0;
	while (d<=c)
	{
		j = q[d];
		for (i=1; i<=n; i++)
		{
			if (b[i] == 1 && ke(j, i))
			{
				c++;
				q[c] = i;
				b[i] = 0;
			}

		}


		d++;
	}

}
