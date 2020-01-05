#include <stdio.h>
#include <conio.h>

// To hop chap k
long giaithua(int n)
{
	long gt = 1;
	int i;
	for (i=2; i<=n; i++)
    {
		gt *= i;
    }
	return gt;
}

long to_hop_chap(int k, int n)
{
	return giaithua(n) / (giaithua(k) * giaithua(n-k));
}

void print(int k,int n)
{
	for(int i = 1;i<n;i++)
	{
		printf("\n(%d,%d)%lu",k,i,to_hop_chap(k,i));
	}
}

void Try(int i,int n,int k)
{
	if(i==n) print(k,n);
	else Try(i+1,n,k);
}

int main()
{
	int n, k;
	printf("\nNhap n =  ");
	scanf("%d", &n);
	printf("\nNhap k =  ");
	scanf("%d",&k);
	//printf("\nTo hop chap %d cua %d = %lu", k, n, to_hop_chap(k, n));
	Try(1,n,k);
	getch();
}
