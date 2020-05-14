/* Cho xau ki tu X xet 3 phep bien doi:
- Insert(i, C) la chen ki tu C vao sau vi tri i cua xau X
- Replace(i, C) la thay the vi tri i cua xau X bang ki tu C
- Delete(i) la xoa ki tu tai vi tri i cua xau X
Yeu cau cho truoc xau Y, hay tim mot so it nhat cac phep bien doi tren de bien xau X thanh xau Y 
	input: file van ban str.inp
		dong 1 chua xau X (do dai <= 100)
		dong 2 chua xau Y (do dai <= 100)
	output: file van ban str.out ghi so cac phep bien doi can thuc hien va cac phep bien doi do */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

char X[100], Y[100];
int **F, m, n;

void readFile()
{
	FILE *f;
	char s[100];
	if (!(f = fopen("bdxau.inp","r")))
	{
		printf("\nFile not found");
		getch();
		exit(0);
	}
	fscanf(f, "%s", X);
	fgets(s, 200, f);
	fscanf(f, "%s", Y);
	fgets(s, 200, f);
	fclose(f);
}

int min3(int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return min;
}

void biendoixau()
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (X[i] == Y[j])
				F[i+1][j+1] = F[i][j];
			else
				F[i+1][j+1] = min3(F[i+1][j], F[i][j], F[i][j+1]) + 1;
		}
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
			printf("%4d", F[i][j]);
		printf("\n");
	}
}

void Insert(int i, char C)
{
	int j, l;
	l = strlen(X);
	for (j = l+1; j > i+1; j--)
		X[j] = X[j-1];
	X[i+1] = C;
}

void Replace(int i, char C)
{
	X[i] = C;
}

void Delete(int i)
{
	int j, l;
	l = strlen(X);
	for (j = i; j < l; j++)
		X[j] = X[j+1];
}

void writeFile()
{
	FILE *f;
	f = fopen("bdxau.out","w");
	//m--;	n--;
	fprintf(f,"%d\n", F[m][n]);
	while ((m != 0) || (n != 0))
	{
		if (X[m-1] == Y[n-1])
		{
			m--;
			n--;
		}
		else
		{
			fprintf(f,"%s -> ", X);
			if (F[m][n] == F[m][n-1] + 1)
			{
				fprintf(f,"Insert(%d, %c) -> ", m, Y[n-1]);
				Insert(m-1, Y[n-1]);
				n--;
			}
			else if (F[m][n] == F[m-1][n-1] + 1)
			{
				fprintf(f,"Replace(%d, %c) -> ", m, Y[n-1]);
				Replace(m-1, Y[n-1]);
				m--;
				n--;
			}
			else
			{
				fprintf(f,"Delete(%d) -> ", m);
				Delete(m-1);
				m--;
			}
			fprintf(f,"%s\n", X);
		}
	}
	fclose(f);
}

void main()
{
	int i, j;
	readFile();
	m = strlen(X);
	n = strlen(Y);
	F = (int **)malloc((m+1)*sizeof(int *));
	for (i = 0; i <= m; i++)
		F[i] = (int *)malloc((n+1)*sizeof(int));
	for (i = 0; i <= m; i++)
		F[i][0] = i;
	for (j = 0; j <= n; j++)
		F[0][j] = j;
	biendoixau();
	writeFile();
	printf("\nDone");
	getch();
}