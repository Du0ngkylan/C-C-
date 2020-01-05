#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// In mang
void in(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}

// Doi cho 2 phan tu trong mang
void swap(int *a,int *b)
{
	int tg;
	tg = *a;
	*a = *b;
	*b = tg;
}

//Sap xep mang theo thu tu giam dan
void Quick(int *a,int l,int r)
{
	int i,j,m;
	m =(l+r)/2;
	i = l;
	j = r;
	while(i<j)
	{
		while(a[i]>a[m]) i++;
		while(a[j]<a[m]) j--;
		if(i<=j)
		{
			swap(a+i,a+j);
			i++;
			j--;
		}
		if(l<j) Quick(a,l,j);
		if(i<r) Quick(a,i,r);
	}
}

// Thuat toan doi tien
int *ChangeMoney(int *a, int n, int q)
{
	int *k;
	k = (int *)malloc(100*sizeof(int));
	for(int i=0;i<n;i++)
	{
		k[i] = 0;
	}
	int i = 0;
	while(i<=n && q > 0)
	{
		k[i] = q/a[i];
		q = q - k[i]*a[i];
		i = i + 1;
	}
	if(q>0) return NULL;
	else return k;
}

int main()
{
	int a[] = {50,5,10,2};
	int n = 4;
    int *b = (int *)malloc(100*sizeof(int));
    printf("\nCac menh gia tien:\n");
	Quick(a,0,n-1);
	in(a,n);
	
	int q;
	printf("\n\nNhap so tien can doi:\n");
	scanf("%d",&q);
	b = ChangeMoney(a,n,q);
    if(b!= NULL)
	{
		for(int i=0;i<n;i++)
		{
			printf("\n\nCo %d to %d\t",b[i],a[i]);
		}
	}
	else
	{
		printf("\nKhong co loi giai\n");
	}
	getch();
	return 0;
}
