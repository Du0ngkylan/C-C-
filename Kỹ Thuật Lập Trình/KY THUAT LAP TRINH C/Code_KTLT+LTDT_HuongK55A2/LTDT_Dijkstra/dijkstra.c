/*
 * dijkstra.c
 *
 *  Created on: Oct 22, 2012
 *      Author: NgoHuong
 */
// da go lai, bai nay thieu may ham..........
#include <stdlib.h>
#include <stdio.h>

enum {hs = 50};

int x, y, n, m;

float w[hs][hs], v[hs];

int pred[hs];

void doctep

void induong()
{
	int i;
	i = y;
	while (i>0 && i != x)
	{
		printf("%d<---", i);
		i = pred[i];
	}
	printf("%d", x);
}

void gannan()
{
	int i, j, k;
	int tiep;
	for (i=1; i<=n; i++)
	{
		w[i][j] = -1;
		v[i] = -1;
	}
	v[x] = 0;
	pred[x] = 0;
	tiep = 1;
	while (1)
	{
		tep = 0;
		for (i=1; i<=n; i++)
		{
			if (v[i]>=0)
			{
				for (j=1; j<=n; j++)
				{
					if (w[i][j] >=0)
					{
						if (v[j] == -1 || (v[j] >= 0 && v[j] > v[i] + w[i][j]))
						{
							v[j] = v[i] + w[i][j];
							pred[j] = i;
						}
					}
				}
			}
		}
	}
	if (v[y] < 0)
		printf("\nKhong co duong di tu %d toi %d", x, y);
	else
	{
		printf("\nCo duong di tu %d toi %d", x, y);
		induong();
	}
}
