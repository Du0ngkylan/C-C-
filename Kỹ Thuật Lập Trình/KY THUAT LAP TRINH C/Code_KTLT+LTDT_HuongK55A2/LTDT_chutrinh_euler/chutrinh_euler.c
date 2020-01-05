/*
 * chutrinh_euler.c
 *
 *  Created on: Dec 21, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>

#define hs 100

int a[hs][hs], b[hs], v[hs];
int dau[hs], cuoi[hs];
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

void khoidau()
{
	int i;
	for (i=1; i<=m; i++)
	{
		b[i] = 1;
	}
}

void inkq()
{
	int i;
	for(i=1;i<=m+1;i++)
		printf("%5d",v[i]);
	puts("");
}
void dequy(int k)
{
	int i;
	if (k > m+1)
		return ;
	if (k == m+1 && v[k] == v[1])
	{
		printf("\nChu trinh euler la:\n");
		/*for (i=1; i<=m+1; i++)
		{
			printf("%5d", v[i]);
		}*/
		inkq();
		exit(0);
	}
	for (i=1; i<=m; i++)
	{
		if (b[i] == 1 && v[k] == dau[i])
			{
				v[k+1] = cuoi[i];
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
	v[1] = 1;
	dequy(1);
	puts("\nDo thi khong co chu trinh euler");
	return 0;
}
// bai nay Dev++ co chay dc kq sao eclipse k chay dc
