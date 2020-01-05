/*
	8.Thuat toan Thay The : Sinh tat ca cac tap con k phan tu cua tap n phan tu
	
		Input:	Hai so nguyen n,k
		Output:	Day cac tap con k phan tu cua tap n phan tu {1..n}
		----------------------------------------------------------
		*Thuat toan: 
			Goi G(n,k): danh sach cac tap con k phan tu thoa
				+ Tap con dau tien: 	{1, 2, ... , k-1, k}
				+ Tap con cuoi cung:	{1, 2, ... , k-1, n}
				+ Tap con sau tao boi tap con truoc bang cach thay the 1 phan tu
			Dung phuong phap de qui:
				G(n,k) = G(n-1,k),G*(n-1,k-1) U {n}
				trong do tap G*(n-1,k-1) U {n} la danh sach duoc tao boi G(n-1,k-1)
				bang cach dao thu tu cua no.
*/

#include <stdio.h>
#include <conio.h>
#define max 100
int n,k,a[max];

void Nhap(){
	printf("\nNhap n,k: ");
	scanf("%d%d",&n,&k);
}

void Khoitao(int k){
	for(int i=1; i<=k; i++)
		a[i] = i;
}

void InTapcon(){
	for(int i=1; i<=k; i++)
		printf("%3d",a[i]);
	printf("\n");
}

void G(int n,int k,int dao){
	if(k == 0){
		InTapcon();
	}else if(k == n){
		Khoitao(k);
		InTapcon();
	}else{ 
		if(dao == 0){	//Khong dao thu tu
			G(n-1,k,0);
			a[k] = n;
			G(n-1,k-1,1);
		}else{			//Dao thu tu
			a[k] = n;
			G(n-1,k-1,0);
			G(n-1,k,1);
		}
	}
}

int main(){
	Nhap();
	Khoitao(k);
	G(n,k,0);
	getch();
	return 0;
}
