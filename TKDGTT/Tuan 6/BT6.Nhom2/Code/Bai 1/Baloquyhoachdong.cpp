#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct object
{
	int p;//price
	int w;//weight
}object;
//init for array C
int **init_for_C(int **C, int n, int P)
{
	int i, j;
	C=(int **)malloc((n+1)*sizeof(int*));
	for(i=0; i<=n; i++)
	{
		C[i]=(int*)malloc((P+1)*sizeof(int));
	}
	for(i=0; i<=n; i++)
	{
		for(j=0; j<=P; j++)
		{
			C[i][j]= 0;
		}
	}
	return C;
}
//init for array Objects
object *init_for_Objects(object *Objects, int n)
{
	Objects=(object*)malloc((n+1)*sizeof(object));
	return Objects;
}
//input data
void input(object *Objects, int n)
{
	int i;
	for(i=1; i<=n; i++)
	{
		printf("\nNhap vao do vat thu %d", i);
		printf("\nPrice of do vat %d =", i); scanf("%d", &Objects[i].p);
		printf("\nWeight of do vat %d = ", i); scanf("%d", &Objects[i].w);
	}
}
//return maximum of two element
int max(int a, int b)
{
	return a>b?a:b;
}
//sort balo
void sortbalo(int **C, object *Objects, int n, int P)
{
	int i, j, k;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=P; j++)
		{
			k=0;
			if(Objects[i].w<=j)
			{
				k=C[i-1][j-Objects[i].w] + Objects[i].p;
			}
			C[i][j] = max(C[i-1][j], k);
		}
	}
}
//print C
void printC(int **C, int n, int P)
{
	int i, j;
	for(i=0; i<=n; i++)
	{
		printf("\n");
		for(j=0; j<=P; j++)
		{
			printf("%5d", C[i][j]);
		}
	}
}

int main()
{
	int P, n, **C;
	object *Objects;
	printf("\nNhap vao trong luong toi da ba lo co the chua P= "); scanf("%d", &P);
	printf("Nhap vao so luong do vat n="); scanf("%d", &n);
	Objects = init_for_Objects(Objects, n);
	C = init_for_C(C, n, P);
	input(Objects, n);
	sortbalo(C, Objects, n, P);
	printC(C, n, P);
	printf("\nGia tri lon nhat co the xep vao balo la %d", C[n][P]);
	getch();
}
