/*
 * kt_sacto_2.c
 *
 *  Created on: Dec 6, 2012
 *      Author: NgoHuong
 */
#include <stdio.h>
#include <stdlib.h>

#define hs 100

int dau[hs], cuoi[hs], v[hs];
int n, m;

void khoidau()
{
	int i;
	for (i=1; i<=n; i++)
		v[i] = 0;
}

void doctep()
{
	int i, j, k;
	FILE *f;
	f = fopen("dulieu.txt", "r");
	if (!f)
	{
		printf("Loi mo tep!");
		exit(0);
	}
	fscanf(f, "%d%d", &n, &m);
	for (k=1; k<=m; k++)
	{
		dau[k] = 0;
		cuoi[k] = 0;
	}
	for (k=1; k<=m; k++)
	{
		fscanf(f, "%d%d", &i, &j);
		dau[k] = i;
		cuoi[k] = j;
	}
	fclose(f);
}

void inmt()
{
	int k;
	printf("\nDau =  ");
	for (k=1; k<=m; k++)
		printf("%5d", dau[k]);
	puts(" ");
	printf("\ncuoi =  ");
	for (k=1; k<=m; k++)
		printf("%5d", cuoi[k]);
	puts(" ");

}
void sacso2()
{
	int tiep, k;
	khoidau();
	v[1] = 1;
	tiep = 1;
	while (tiep)
	{
		tiep = 0;
		for (k=1; k<=m; k++)
		{
			if (v[dau[k]] != 0)
			{
				if (v[cuoi[k]] == v[dau[k]])
				{
					printf("\nDo thi khong co sac so");
					exit(0);
				}
				if (v[cuoi[k]] == 0)
				{
					v[cuoi[k]] = 3 - v[dau[k]];
					tiep = 1;
				}
			}
			if (v[cuoi[k]] != 0)
			{
				if (v[dau[k]] == v[cuoi[k]])
				{
					printf("\ndo thi khong co sac so bang 2");
					exit(0);
				}
				if (v[dau[k]] == 0)
				{
					v[dau[k]] = 3- v[cuoi[k]];
					tiep = 1;
				}
			}
			if (v[dau[k]] + v[cuoi[k]] == 0)
			{
				v[dau[k]] = 1;
				tiep = 1;
			}
		}
	}
	int i;
	printf("\nCac dinh co mau bang 1 la:\n");
	for (i=1; i<=n; i++)
		if (v[i] == 1)
			printf("%5d", i);
	printf("\nCac dinh co mau bang 2 la:\n");
	for (i=1; i<=n; i++)
		if (v[i] == 2)
			printf("%5d", i);
}

/*void tomau_quyen()
{
	int i;
	if (sacso2() == 0)
		printf("\nKhong co ss = 2");
	else
	{
		printf("1");
		for (i=1; i<=n; i++)
		{
			if (v[i] == 1)
				printf("%d", v[i]);
		}
		printf("\nCac dinh co mau = 2 la:\n");
		for (i=1; i<=n; i++)
		{
			if (v[i] == 2)
				printf("%d", v[i]);
		}
	}
}*/

int main()
{
	setbuf (stdout, NULL);
	doctep();
	inmt();
	sacso2();
	return 0;
}
