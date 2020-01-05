/*
	6.Thuat toan Them Bot: Sinh tat ca cac tap con cua tap n phan tu
	
		Input:	So nguyen n
		Otput:	Day cac tap con cua tap n phan tu
		-----------------------------------------
		*Thuat toan: Phuong phap lap
			B1:	Chon day n chu so 0 (Bieu dien bang mang B[1..n])
			B2: Vong lap
				- Tim vi tri thay doi k.
				- Thay doi cho hop li(B[k] = 1 - B[k])
			B3: Lap cho den khi het vi tri thay doi	(k > n)
*/

#include <stdio.h>
#include <conio.h>
#define max 100
int n,B[max];

void Nhap(){
	printf("\nNhap n: ");
	scanf("%d",&n);
}

void Khoitao(){
	for(int i=1; i<=n ; i++)
		B[i] = 0;
}

void InTapCon(){
	printf("\n{");
	for(int i=1; i<=n ; i++)
		if(B[i] != 0)
			printf("%3d,",i);
	printf("}");
}

void ThemBot(){
	Khoitao();
	int i=1,k=1;
	while(k <= n){
		InTapCon();
		int dem = 0,j=i;
		while(j % 2 == 0){
			dem++;
			j = j/2;
		}
		k = dem + 1;		//k:so lan chia het cho 2
		B[k] = 1 - B[k];
		i++;
	}
}

int main(){
	Nhap();
	ThemBot();
	getch();
	return 0;
}
