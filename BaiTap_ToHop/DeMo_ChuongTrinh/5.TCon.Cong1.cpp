/*
	5.Thuat toan Cong 1: Sinh cac tap con cua tap n phan tu
	
		Input:	So nguyen n
		Output:	Day cac tap con cua tap n phan tu
		---------------------------------------------------
		Thuat toan:
			B1: Khoi tao t = 1
			B2:	Doi t sang nhi phan(co n chu so)
			B3: t = t + 1
				-Neu t < 2mu n: Quay lai B2
				-Nguoc lai: Dung
		----------------------------------------------------
*/

#include <stdio.h>
#include <conio.h>
#define max 100
int n,a[max];

void Nhap(){
	printf("\nNhap n: ");
	scanf("%d",&n);
}

void Khoitao(){
	for(int i=1; i<=n ; i++)
		a[i] = 0;
}

void InTapCon(){
	printf("\n{");
	for(int i=1; i<=n ; i++)
		if(a[i] != 0)
			printf(" %d ",i);
	printf("}");
}

void Cong1(){
	int i = n;
	while(i != 0){
		InTapCon();
		i = n;
		while(a[i] == 1){
			a[i] = 0;
			i--;
		}
		if(i > 0)
			a[i] = 1;
	}
}

int main(){
	Nhap();
	Khoitao();
	Cong1();
	getch();
	return 0;
}
