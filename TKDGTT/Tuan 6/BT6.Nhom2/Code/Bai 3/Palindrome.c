#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define INPUT	"PALIN.INP"

int F[100][100], n, a[100];
char s[100];

void init(int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i > j)
				F[i][j] = 0;
			if (i == j)
				F[i][j] = 1;
		}
}

void readFile()
{
	FILE *f;
	f = fopen(INPUT, "r");
	if (!f)
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	fscanf(f, "%d", &n);
	init(n);
	fscanf(f, "%s", s);
	fclose(f);
}

int max2(int a, int b)
{
	int m = a;
	if (b < m)
		m = b;
	return m;
}

void palindrome()
{
	int i, j;
	for (j = 1; j < n; j++)
	{
		for (i = j-1; i >= 0; i--)
		{
			if (s[i] == s[j])
			{
				F[i][j] = F[i+1][j-1] + 2;
			}
			else
			{
				F[i][j] = max(F[i+1][j], F[i][j-1]);
			}
		}
	}
}

void truyVet()
{
	int i, j;
	for (i = 0; i < n; i++)
		a[i] = 0;
	i = 0;	j = n-1;
	while (!(F[i][j] == 1 && F[i+1][j] == 0 && F[i][j-1] == 0))
	{
		if (F[i][j] == F[i+1][j-1] + 2)
		{
			i = i+1;
			j = j-1;
		}
		else if (F[i][j] == F[i][j-1])
		{
			a[j] = 1;
			j = j-1;
		}
		else if (F[i][j] == F[i+1][j])
		{
			a[i] = 1;
			i = i+1;
		}
	}
}

int main()
{
	int i, j;
	readFile();
	printf("\nXau ban dau: %s\n", s);
	palindrome();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%4d", F[i][j]);
		printf("\n");
	}
	printf("\nSo ki tu can xoa it nhat la: %d", n - F[0][n-1]);
	truyVet();
	printf("\nXau ket thuc: ");
	for (i = 0; i < n; i++)
		if (a[i] == 0)
			printf("%c", s[i]);
	getch();
	return 0;
}