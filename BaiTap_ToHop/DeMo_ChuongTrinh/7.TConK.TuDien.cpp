/*
	6.Thuat toan Tu Dien: sinh tat ca cac tap con k phan tu cua tap n phan tu
	
		Input: 	Hai so nguyen n,k
		Output: Day cac tap con k phan tu cua tap n phan tu {1..n}
		----------------------------------------------------------
		Gia su X = {1, 2, ..., n}
		Tap A la tap con k phan tu cua X, A = {i1, i2, i3, ..., ik}
		De dam bao tinh duy nhat ta sap cac phan tu cua A theo thu tu tang dan
		nghia la: i1 < i2 < ... < ik
		Khi do day so <i1, i2, ... , ik> thoa : 1 <= <i1, i2, ... , ik> <= n co
			+ Day be nhat: 	1, 2, ... , k
			+ Day lon nhat:	n-k+1, n-k+2, ... , n
		-----------------------------------------------------------
		Thuat toan: 
			B1: Chon day tap con dau tien {1, 2, ... , k}
			B2: Vong lap
				+ Tim vi tri thay doi(vi tri ma tu do tro ve sau thay doi)
				+ Thay doi sao cho hop li
			B3: Ket thuc vong lap khi khong con vi tri thay doi
		-----------------------------------------------------------
		Dung mang a[1..k] de chua tap con k phan tu
		p: vi tri ma tu do tro ve sau se thay doi
		B1: Khoi tao day ban dau 1, 2, ... , k
		B2: Vong lap
				+ Neu a[k] = n thi p = p -1
				+ Nguoc lai p = k
			Thay doi: for(i=k; i>=p; i--)
					a[i] = a[p] + i + 1 - p;
		B3: Neu p >=1 Quay lai B2
			Nguoc lai: Dung
*/
#include <stdio.h>
#include <conio.h>
#define max 100
int n,k,a[max];

void Nhap(){
	printf("\nNhap n,k: ");	
	scanf("%d%d",&n,&k);
}

void Khoitao(){
	for(int i=1; i<=k; i++)
		a[i] = i;
}

void InTapcon(){
	for(int i=1; i<=k; i++)
		printf("%3d",a[i]);
	printf("\n");
}

void TD(){
	int p = k; //Vi tri ma tu do tro ve sau se thay doi
	while(p >= 1){
		InTapcon();
		//Tim vi tri thay doi
		if(a[k] == n)
			p = p - 1;
		else
			p = k;
		//Thay doi
		for(int i=k; i>=p; i--)
			a[i] = a[p] + i + 1 - p;
	}
}

int main(){
	Nhap();
	Khoitao();
	TD();	
	getch();
	return 0;
}
