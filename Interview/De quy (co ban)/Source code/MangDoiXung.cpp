/* Nhap mang roi kiem tra xem co doi xung hay khong */
#include<stdio.h>
bool kiemtra(int a[],int n,int m)
{
	if(n>=m) return 1;
	else
	{
		
		if(a[n]!=a[m])
				return 0;
		kiemtra(a,n+1,m-1);
	}
	
}


void main(){
	int a[100],n;
	printf("Nhap n");
	scanf("%d",&n);
	for(int i=0; i < n ; i++)
		scanf("%d",&a[i]);
	if(kiemtra(a,0,n-1)) printf("DOI XUNG");
	else printf("KO");
}