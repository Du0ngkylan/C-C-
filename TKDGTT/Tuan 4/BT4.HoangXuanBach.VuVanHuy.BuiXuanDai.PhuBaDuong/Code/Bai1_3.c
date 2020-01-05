/*
	Liet ke day nhi phan do dai n
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define OUTPUT "NHIPHAN.OUT"

int *v, n;

void writeFile();
void Try(int );

void main()
{
	printf("\nNhap do dai: ");
	scanf("%d", &n);
	v = (int *)malloc(n*sizeof(int));
	remove(OUTPUT);
	Try(0);
	printf("\nComplete!\n");
}

void Try(int k)
{
	int i;
	for (i = 0; i <= 1; i++)
	{
		if (k >= n)
			return;
		v[k] = i;
		if (k == n-1)
		{
			writeFile();
		}
		else
		{
			Try(k+1);
		}
	}
}

void writeFile()
{
	int i;
	FILE *f;
	if (!(f = fopen(OUTPUT, "a")))
	{
		printf("\nKhong mo duoc file");
		getch();
		exit(0);
	}
	for (i = 0; i < n; i++)
	{
		fprintf(f, "%d", v[i]);
	}
	fprintf(f, "%c", '\n');
	fclose(f);
}
