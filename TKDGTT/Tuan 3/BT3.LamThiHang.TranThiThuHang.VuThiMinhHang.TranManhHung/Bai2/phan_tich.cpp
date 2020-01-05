#include<stdio.h>
#include<conio.h>

int phan_tich(int n){
	int d=2;
	if(n==1)
		return 0;
	else{
		while((n%d)!=0)
			d++;
		if(n/d == 1)
			printf("%d",d);
		else
		    printf("%d.", d);
		phan_tich(n/d);
		}
	}
	
int main(){
	int n;
	printf("Nhap vao mot so nguyen: ");
	scanf("%d", &n);
	printf(" n = ");
	phan_tich(n);
	getch();
	return 0;
	}
