/*
	Ma di tuan
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define OUT "MA.OUT"

typedef struct point
{
	int x, y;
}point;

int dd[9][9];
int b[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int c[8] = {1, 2, 2, 1, -1, -2, -2, -1};
point a[65], xp;

void writeFile();
void khoitao();
void Try(int , point );

void main()
{
	printf("\nNhap toa do dinh xuat phat:");
	printf("\nx = ");		scanf("%d", &xp.x);
	printf("\ny = ");		scanf("%d", &xp.y);
	khoitao();
	remove(OUT);
	a[1] = xp;
	Try(2, xp);
	getch();
}

void writeFile()
{
	int i, dem;
	FILE *f;
	if (!(f = fopen(OUT, "a")))
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	dem = 0;
	for (i = 1; i <= 64; i++)
	{
		if (dem == 10)
		{
			fprintf(f, "%c", '\n');
			dem = 0;
		}
		fprintf(f, "(%d,%d) ", a[i].x, a[i].y);
		dem++;
	}
	fprintf(f, "%c", '\n');
	fclose(f);
}

void khoitao()
{
	int i, j;
	for (i = 1; i <= 8; i++)
		for (j = 1; j <= 8; j++)
			dd[i][j] = 0;
}

void Try(int k, point pre)
{
	int i;
	point cur;
	for (i = 0; i < 8; i++)
	{
		cur.x = pre.x + b[i];
		cur.y = pre.y + c[i];
		if (cur.x >= 1 && cur.x <= 8 && cur.y >= 1 && cur.y <= 8 && dd[cur.x][cur.y] == 0)
		{
			a[k] = cur;
			if (k == 64)
			{
				writeFile();
				printf("\nComplete!\n");
				exit(0);
			}
			else
			{
				dd[cur.x][cur.y] = 1;
				Try(k+1, cur);
				dd[cur.x][cur.y] = 0;
			}
		}
	}
}