#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 100

int F[MAX][MAX];
int i, j, n;

void Phantich()
{
	for (i = 0; i <= n; i++)
		F[0][i] = 0;
	F[0][0] = 1;
	for (i = 1; i <= n; i++)
		for (j = 0; j <= n; j++)
			if (i <= j)
				F[i][j] = F[i-1][j] + F[i][j-i];
			else
				F[i][j] = F[i-1][j];
}

int main()
{
	printf("\nEnter n = ");		scanf("%d", &n);
	Phantich();
	printf("\nSo cach phan tich la: %d", F[n][n]);
	getch();
	return 0;
}
