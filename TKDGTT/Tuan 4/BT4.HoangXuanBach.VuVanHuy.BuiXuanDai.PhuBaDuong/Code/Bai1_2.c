/*
	Bai toan nguoi ban hang:
	Mot nguoi ban hang tren he thong n thanh pho. Giua cac thanh pho co the co hoac
	khong cac duong noi co chi phi xac dinh tu truoc. Nguoi ban hang xuat phat tu
	mot thanh pho, di toi tat ca cac thanh pho khac va moi thanh pho di qua mot lan
	va quay tro lai thanh pho ban dau. Hay xac dinh mot hanh trinh sao cho chi phi
	tren duong di la nho nhat.

	Coi moi thanh pho la mot dinh cua do thi, moi duong di la mot cung

	input: file BANHANG.INP co cau truc: dong 1 ghi so dinh n, so cung m, dinh xuat phat xp
		m dong tiep theo ghi cac cung va trong so tren tung cung
	output: file BANHANG.OUT ghi hanh trinh co chi phi nho nhat.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define INPUT "BANHANG.INP"
#define OUTPUT "BANHANG.OUT"

int M[50][50], v[50], dd[50], kq[50], best, n, m, xp;

void khoitao();
void readFile();
void writeFile();
void Try(int , int );

void main()
{
	best = 32000;
	readFile();
	v[1] = xp;
	dd[xp] = 1;
	Try(2, 0);
	writeFile();
	printf("\nComplete!\n");
}

void khoitao()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		dd[i] = 0;
		for (j = 1; j <= n; j++)
			M[i][j] = -1;
	}
}

void readFile()
{
	FILE *f;
	int i, j, k, t;
	if (!(f = fopen(INPUT, "r")))
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	fscanf(f, "%d %d %d", &n, &m, &xp);
	khoitao();
	for (k = 1; k <= m; k++)
	{
		fscanf(f, "%d %d %d", &i, &j, &t);
		M[i][j] = t;
		M[j][i] = t;
	}
	fclose(f);
}

void Try(int k, int C)
{
	int i, j, c1;
	if (k > n)
		return;
	for (i = 1; i <= n; i++)
	{
		if (dd[i] == 0 && M[v[k-1]][i] != -1)
		{
			c1 = C+M[v[k-1]][i];
			if (c1 < best)
			{
				v[k] = i;
				dd[i] = 1;
				if (k == n && M[v[k]][xp] != -1 && c1+M[v[k]][xp] < best)
				{
					for (j = 1; j <= n; j++)
						kq[j] = v[j];
					best = c1;
				}
				else
					Try(k+1, c1);
				dd[i] = 0;
			}
		}
	}
}

void writeFile()
{
	int i;
	FILE *f;
	if (!(f = fopen(OUTPUT, "w")))
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	for (i = 1; i < n; i++)
		fprintf(f, "%d --> ", kq[i]);
	fprintf(f, "%d\n", kq[n]);
	fprintf(f, "Chi phi thap nhat: %d", best);
	fclose(f);
}

