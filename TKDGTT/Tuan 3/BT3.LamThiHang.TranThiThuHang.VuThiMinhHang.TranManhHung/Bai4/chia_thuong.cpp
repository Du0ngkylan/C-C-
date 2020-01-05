#include<stdio.h>
#include<conio.h>

int chia_thuong(int m, int n){
	if(m==0) return 1;
	if(n==0) return 0;
	if(m<n) return (chia_thuong(m,m));
	else return (chia_thuong(m,n-1) + chia_thuong(m-n,n));
	}
	
int main(){
	int n,m;
	printf("Nhap vao so hoc sinh:  ");
	scanf("%d", &n);
	printf("Nhap vao so phan thuong:  ");
	scanf("%d", &m);
	printf("So cach chia %d phan thuong cho %d hoc sinh: %d.\n",m,n,chia_thuong(m,n));
	getch();
	return 0;
	}
