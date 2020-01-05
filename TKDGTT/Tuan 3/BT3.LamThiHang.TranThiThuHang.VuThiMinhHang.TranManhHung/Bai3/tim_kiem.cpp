#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void nhap_mang(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("Nhap a[%d] =  ",i+1);
		scanf("%d", &a[i]);
		}
	}
	
void in_mang(int a[], int n){
	int i;
	for(i=0;i<n;i++)
		printf("%4d", a[i]);
	printf("\n");
	}
	
int tim_kiem(int a[], int l, int r, int x){
	int m,d;
	m = (l+r)/2;
	if(a[m]==x){
		printf("So can tim o vi tri thu %d.\n",m+1);
		return m;
		}
	if(x<a[m])
		tim_kiem(a,l,m,x);
	else
		tim_kiem(a,m+1,r,x);
	}
	
int main(){
	int a[100];
	int n,x;
	int m;
	printf("Nhap vao so phan tu cua day: ");
	scanf("%d", &n);
	nhap_mang(a,n);
	printf("Day so vua nhap la: \n");
	in_mang(a,n);
	printf("Nhap vao so can tim:  ");
	scanf("%d", &x);
	m = tim_kiem(a,0,n-1,x);
	getch();
	return 0;
	}
