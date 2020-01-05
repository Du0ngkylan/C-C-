#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int **C, **A,**DD;//C is table of number
int m, n;//m is rows number, n is colums number
int *truyvet;// mang truy vet duong di gia tri truyvet[i] la hang con i la cot

void init()
{
	int i;
	A =(int**)malloc((m+2)*sizeof(int*));
	C =(int**)malloc((m+2)*sizeof(int*));
	DD =(int**)malloc((m+2)*sizeof(int*));
	for(i=0; i<=m+1; i++)
	{
		A[i]=(int*)malloc((n+2)*sizeof(int));
		C[i]=(int*)malloc((n+2)*sizeof(int));
		DD[i]=(int*)malloc((n+2)*sizeof(int));
	}
	truyvet= (int *)malloc((n+1)*sizeof(int));
}

void input()//input data for A
{
	int i, j;
	FILE *f;
	f=fopen("data.inp", "r");
	fscanf(f, "%d %d\n", &m, &n);
	init();
	for(i=0; i<=m; i++)
	{
		A[i][0] = 0;
		C[i][0] = 0;
	}
	for(j=0; j<=n; j++)
	{
		A[0][j] = 0;
		C[0][j] = 0;
		A[m+1][j] = 0;
		C[m+1][j] = 0;
	}
	for(i=1; i<=m; i++)
	{
		for(j=1; j<n; j++)
		{
			fscanf(f, "%d", &A[i][j]);
			C[i][j] = 0;
			DD[i][j] = 0;
		}
		fscanf(f, "%d\n", &A[i][j]);
		C[i][j]=0;
		DD[i][j] = 0;
	}
}

void output(int **A)
{
	int i, j;
	for(i=1; i<=m; i++)
	{
		printf("\n");
		for(j=1; j<=n; j++)
		{
			printf("%5d", A[i][j]);
		}
	}
	printf("\n\n");
}

int max(int a, int b, int c)
{
	int temp;
	temp = a>b?a:b;
	return temp>c?temp:c;
}

void Duongdi()
{
	int i, j;
	for(j=1; j<=n; j++)
	{
		for(i=1; i<=m; i++)
		{
			C[i][j] = max(C[i-1][j-1], C[i][j-1], C[i+1][j-1]) + A[i][j];
		}
	}
}

void TruyVet()
{
	int h = m , i;
	truyvet[n]=m;
	for(i=n; i>=1; i--)
	{
		if(C[h-1][i-1] == C[h][i] - A[h][i])
		{
			h=h-1;
			truyvet[i-1] = h;
		}
		else if(C[h][i-1] == C[h][i] - A[h][i])
		{
			h=h;
			truyvet[i-1] = h;
		}
		else if(C[h+1][i-1]==C[h][i] - A[h][i])
		{
			h=h+1;
			truyvet[i-1] = h;
		}
	}
	printf("\nIn ra duong di la\n");
	for(i=1; i<n; i++)
	{
		printf("%d->", A[truyvet[i]][i]);
		DD[truyvet[i]][i] = 1;
	}
	printf("%d", A[truyvet[n]][n]);
		DD[truyvet[n]][n]=1;
}

void OutputDuongDi()
{
	int i, j, k=1, k1=0;
	for(i=1; i<=m; i++)
	{
		printf("\n");
		for(j=1; j<=n; j++)
		{
			if(DD[i][j]==1)
			{
				printf("%5d", A[i][j]);
			}
			else
				printf("%5d", k1);
		}
	}
}

int main()
{
	int m, n;//m is rows number, n is colums number
	int *truyvet;// mang truy vet duong di gia tri truyvet[i] la hang con i la cot
	input();
	output(A);
	Duongdi();
	output(C);
	TruyVet();
	OutputDuongDi();
	getch();
}
