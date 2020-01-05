/*
 * duong_halminton.c
 *
 *  Created on: Dec 21, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>

#define hs 100

int a[hs][hs], v[hs], b[hs];
int n, m;

void doctep()
{
	int i, j, k;
	FILE *f;
	f = fopen("dulieu.txt", "r");
	if (!f)
	{
		printf("Loi mo tep");
		exit(0);
	}
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

void khoidau()
{
	int i;
	for (i=1; i<=n; i++)
		b[i] = 1;
}

int cung(int i, int j)
{
	return a[i][j] > 0;
}

void inkq()
{
	int i;
	for (i=1; i<=n; i++)
	{
		printf("%5d", v[i]);
	}
}

void dequy(int k)
{
	int i;
	if (k > n)
		return;
	if (k == n)
	{
		printf("\nduong haminlton la:\n");
		inkq();
		exit(0);
	}
	for (i=1; i<=n; i++)
	{
		if ((b[i] == 1 && cung(v[k], i)) || k==0 )
		{
			v[k+1] = i;
			b[i] = 0;
			dequy(k+1);
			b[i] = 1;
		}
	}
}

int main()
{
	setbuf(stdout, NULL);
	doctep();
	khoidau();
	v[0] = 0;
	dequy(0);
	puts("\nDo thi khong co chu trinh halminton!!!");
	return 0;
}

