#include <stdio.h>
#include <conio.h>

#define MAX 100

void Result(int B[MAX], int k)
{
	static int count=0;
	printf("\nTap con thu %d: ", ++count);
	for(int i=1; i <= k; i++)
		printf("%3d", B[i]);
}

void Try(int i, int B[MAX], int k, int n)
{
	int j;
	for(j = B[i-1] + 1; j <= (n-k+i); j++)
	{
		B[i] = j;
		if (i == k)  Result(B,k);
		else
			Try(i+1, B, k, n);
    }
}


int main()
{
	int  n, k, B[MAX];
	printf("Nhap n: ");
	scanf("%d",&n);
	printf("Nhap k: ");
	scanf("%d", &k);
	B[0] = 0;
	Try(1, B, k, n);
	getch();
	return 0;
}
