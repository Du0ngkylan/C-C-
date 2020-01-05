/*
	Tim cach dat 8 con Hau tren ban co Vua sao cho chung khong an lan nhau
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define OUT "HAU.OUT"

int v[9], a[9], b[17], c[15];

void writeFile();
void khoitao();
void Try(int );

void main()
{
	khoitao();
	remove(OUT);
	Try(1);
	printf("\nComplete!\n");
	getch();
}

void writeFile()
{
	FILE *f;
	int i;
	if (!(f = fopen(OUT, "a")))
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	for (i = 1; i <= 8; i++)
		fprintf(f, "(%d,%d) ", i, v[i]);
	fprintf(f, "%c", '\n');
	fclose(f);
}

void khoitao()
{
	int i;
	for (i = 1; i <= 8; i++)
		a[i] = 1;
	for (i = 2; i <= 16; i++)
		b[i] = 1;
	for (i = -7; i <= 7; i++)
		c[i] = 1;
}

void Try(int k)
{
	int i;
	for (i = 1; i <= 8; i++)
		if (a[i] && b[k+i] && c[k-i])
		{
			v[k] = i;
			if (k == 8)
			{
				writeFile();
				return;
			}
			else
			{
				a[i] = 0;	b[k+i] = 0;		c[k-i] = 0;
				Try(k+1);
				a[i] = 1;	b[k+i] = 1;		c[k-i] = 1;
			}
		}
}

