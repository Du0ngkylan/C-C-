#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void nhap(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nNhap phan tu thu %d: ",i+1);
		scanf("%d",&a[i]);
	}
}

void in(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

void merge(int a[], int left, int mid, int right)
{
	int temp[right - left + 1];
	int i, j,k = left;
	i=left;
	j = mid+1;
	while((i<=mid)&&(j<=right))
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else temp[k++]=a[j++];
	}
	if (i == mid + 1)
	{
		while(j<=right) temp[k++] = a[j++];
    }
	else
    {
		while(i<=mid) temp[k++] = a[i++];
    }
	for(k=left;k<=right;k++) a[k]=temp[k];
}

void Mergesort(int a[], int left,int right)
{
	int mid;
	if(left<right)
	{
		mid=(left+right)/2;
		Mergesort(a,left,mid);
		Mergesort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}

int main()
{
	int a[1000], n,temp;
	printf("Nhap n  = ");
	scanf("%d",&n);
	nhap(a,n);
	printf("\nDay ban dau la: ");
	in(a,n);
    printf("\nDay da duoc sap xep la: ");
    Mergesort(a,0,n);
    in(a,n);
    getch();
    return 0;
}
