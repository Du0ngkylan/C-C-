/*
	1.Thuat toan tim kieu va dau cua hoan vi
	
		Input: 	Hoan vi f bat ki duoi dang mang f[1..n]
		Output:	- Mang Lamda[1..n] la kieu cua hoan vi f
				- sgnF la dau cua hoan vi f
*/

#include <stdio.h>
#include <conio.h>
#define max 100
int n,sgnF,f[max],F[max],Lamda[max],Moi[max];

void Nhap(){
	printf("\nNhap n: ");
	scanf("%d",&n);
	printf("\nNhap hoan vi f: ");
	for(int i=1;i<=n;i++){
		printf("\nf[%d] = ",i);
		scanf("%d",&f[i]);
	}
}

void Khoitao(){
	for(int i=1;i<=n;i++){
		F[i] = f[i];
		Lamda[i] = 0;
		Moi[i] = 0;
	}
	sgnF = 1;
}

void KetQua(){
	printf("\nKieu cua f: ");
	for(int i=1; i<=n; i++)
		printf("%3d",Lamda[i]);
	printf("\nDau cua f: %3d", sgnF);
}

void KieuVaDau(){
	int j,k;
	for(int i=1; i<=n; i++){
		if(Moi[i] == 0){
			j = F[i];
			k = 1;
			while(j != i){
				Moi[j] = 1;
				j = F[j];
				k++;
				sgnF = -sgnF;
			}
			Lamda[k] = Lamda[k] + 1;
		}
	}
}

int main(){
	Nhap();
	Khoitao();
	KieuVaDau();
	KetQua();
	getch();
	return 0;
}
