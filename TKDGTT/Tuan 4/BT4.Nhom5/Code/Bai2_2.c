/*
	Liet ke cac to hop chap k cua n phan tu
	input: file TOHOP.INP, dong 1 ghi so phan tu n va so k
		n dong tiep theo ghi n phan tu
	output: file TOHOP.OUT ghi tat ca cac to hop chap k cua n phan tu
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define IN "TOHOP.INP"
#define OUT "TOHOP.OUT"

int a[50], v[50], dd[50], n, k;

void readFile();
void writeFile();
void khoitao();
void Try(int );

void main()
{
	readFile();
	khoitao();
	remove(OUT);
	Try(1);
	printf("\nComplete!\n");
	getch();
}

void readFile()
{
	FILE *f;
	int i;
	if (!(f = fopen(IN, "r")))
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	fscanf(f, "%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
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
	for (i = 1; i <= k; i++)
		fprintf(f, "%4d", v[i]);
	fprintf(f, "%c", '\n');
	fclose(f);
}

void khoitao()
{
	int i;
	for (i = 1; i <= n; i++)
		dd[i] = 0;
}

void Try(int t)
{
	int i;
	for (i = 1; i <= n; i++)
		if (dd[i] == 0)
		{
			v[t] = a[i];
			if (t == k)
			{
				writeFile();
				return;
			}
			else
			{
				dd[i] = 1;
				Try(t+1);
				dd[i] = 0;
			}
		}
}