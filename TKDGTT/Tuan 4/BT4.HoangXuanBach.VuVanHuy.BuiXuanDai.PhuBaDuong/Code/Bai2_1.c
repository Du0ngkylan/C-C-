/*
	Liet ke tat ca cac hoan vi cua n phan tu
	input: file HOANVI.INP chua n phan tu, dong dau ghi n, cac dong con lai
	moi phan tu o mot dong
	output: file HOANVI.OUT chua cac hoan vi cua n phan tu
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define INPUT "HOANVI.INP"
#define OUTPUT "HOANVI.OUT"

int n, v[50], dd[50], a[50];

void readFile();
void writeFile();
void khoitao();
void Try(int );

void main()
{
	readFile();
	khoitao();
	remove(OUTPUT);
	Try(1);
	printf("\nComplete!\n");
	getch();
}

void readFile()
{
	FILE *f;
	int i;
	if (!(f = fopen(INPUT, "r")))
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	fscanf(f, "%d", &n);
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	fclose(f);
}

void writeFile()
{
	FILE *f;
	int i;
	if (!(f = fopen(OUTPUT, "a")))
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	for (i = 1; i <= n; i++)
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

void Try(int k)
{
	int i;
	for (i = 1; i <= n; i++)
		if (dd[i] == 0)
		{
			v[k] = a[i];
			if (k == n)
			{
				writeFile();
				return;
			}
			else
			{
				dd[i] = 1;
				Try(k+1);
				dd[i] = 0;
			}
		}
}