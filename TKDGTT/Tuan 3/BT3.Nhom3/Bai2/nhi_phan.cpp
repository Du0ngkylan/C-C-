#include<stdio.h>
#include<conio.h>

void nhi_phan(int n){
	if(n>0){
		nhi_phan(n/2);
		printf("%d",n%2);
		}
	}

int main(){
	int n;
	printf("Nhap vao mot so nguyen :  ");
	scanf("%d", &n);
	printf("Bieu dien nhi phan : \n");
	nhi_phan(n);
    getch();
	return 0;
	}
