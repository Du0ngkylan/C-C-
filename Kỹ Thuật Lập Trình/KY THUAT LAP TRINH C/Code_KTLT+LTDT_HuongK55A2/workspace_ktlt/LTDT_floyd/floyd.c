/*
 * floyd.c
 *
 *  Created on: Oct 23, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>
enum {hs = 50};

float w[hs][hs], next[hs][hs];
int x, y, n, m;

void tb(char *s)
{
	puts(s);
	exit(0);
}
void doctep()
{
	int i, j, k;
	float t;
	FILE *f;
	f = fopen("floyd.txt", "r");
	if (!f) tb("loi mo tep");
	fscanf(f, "%d%d", &n, &m);
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			w[i][j] = -1;
	for (k=0; k<m; k++)
	{
		fscanf(f, "%d%d%f", &i, &j, &t);
		w[i][j] = t;
	}
	fclose(f);
}

void inkq()
{
	int k;
	k=x;
	while (k!=y)
	{
		printf("%d--->", k);
		k = next[k][y];
	}
	printf("%d", y);
}

void lapmt()
{
	int i, j, k;
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++)
			next[i][j] = j;
	for (k=1; k<n; k++)
	{
		for (i=1; i<=n ;i++)
		{
			for (j=1; j<=n; j++)
			{
				if (i!=j)
					if (w[i][k+1] >= 0 && w[k+1][j] >= 0)
						if (w[i][j] <0 || (w[i][j] >= 0 && w[i][j] > w[k+1][j] + w[i][k+1]))
						{
							w[i][j] = w[k+1][j] + w[i][k+1];
							next[i][j] = next[i][k+1];
						}
			}
		}
	}
	if (w[x][y] < 0)
		printf("\nKhong co duong di tu %d toi %d\n", x, y);
	else
	{
		printf("\nco duong di tu %d toi %d vs do dai min %f\n", x, y, w[x][y]);
		inkq();
	}
}
int main()
{
	setbuf(stdout, NULL);
	doctep();
	printf("\nNhap x= ");scanf("%d", &x);
	printf("\nNhap y= ");scanf("%d", &y);
	lapmt();
	return 0;
}

