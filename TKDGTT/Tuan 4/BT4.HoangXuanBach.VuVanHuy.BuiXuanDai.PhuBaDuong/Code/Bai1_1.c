/*
	Tim duong di tu A den B trong me cung
	Su dung bieu dien do thi
	input: file MECUNG.INP: Dong dau ghi cac thong so: so dinh n cua do thi,
		so cung m cua do thi, dinh xuat phat xp, dinh ket thuc kt. m dong tiep
		theo ghi m cung cua do thi.
	output: file MECUNG.OUT: ghi duong di tu xp den kt.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define INPUT "MECUNG.INP"
#define OUTPUT "MECUNG.OUT"

int M[50][50],	// Ma tran ke
	v[50],		// Mang chua cac dinh da di qua
	dd[50],	// Mang danh dau dinh da di qua hay chua
	n,		// So dinh cua do thi
	m,		// So cung cua do thi
	xp,		// Dinh vao cua me cung
	kt,		// Dinh ket thuc me cung
	co;		// Danh dau co duong di hay khong

void khoitao();
void readFile();
void Try(int );
void writeFile();

void main()
{
	FILE *f;
	readFile();
	co = 0;
	v[0] = xp;
	dd[xp] = 1;
	remove(OUTPUT);
	Try(0);
	if (co == 0)
	{
		f = fopen(OUTPUT, "w");
		fprintf(f, "%s", "Khong co duong di");
		fclose(f);
	}
	printf("\nComplete!\n");
}

void Try(int k)
{
	int i;
	if (k > n)
		return;
	if (v[k] == kt)
	{
		writeFile(k);
		return;
	}
	for (i = 1; i <= n; i++)
	{
		if (M[v[k]][i] == 1 && dd[i] == 0)
		{
			v[k+1] = i;
			dd[i] = 1;
			Try(k+1);
			dd[i] = 0;
		}
	}
}

void writeFile(int k)
{
	int i;
	FILE *f;
	if (!(f = fopen(OUTPUT, "a")))
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	for (i = 0; i < k; i++)
		fprintf(f, " %d -->", v[i]);
	fprintf(f, " %d\n", v[k]);
	fclose(f);
	co = 1;
}

void readFile()
{
	FILE *f;
	int i, j, k;
	if (!(f = fopen(INPUT, "r")))
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	fscanf(f, "%d %d %d %d", &n, &m, &xp, &kt);
	khoitao();
	for (k = 1; k <= m; k++)
	{
		fscanf(f, "%d %d", &i, &j);
		M[i][j] = 1;
		M[j][i] = 1;
	}
	fclose(f);
}

void khoitao()
{
	int i, j;
	// khoi tao gia tri dau cho ma tran
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			M[i][j] = 0;
	// khoi tao cho mang dd
	for (i = 1; i <= n; i++)
		dd[i] = 0;
}
