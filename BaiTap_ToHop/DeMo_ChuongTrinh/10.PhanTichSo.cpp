/*
	10.Thuat toan Tim tat ca cac phan tich cua mot so
	
		Input: So nguyen n
		Output: Day cac phan tich cua so n.
		-----------------------------------
		* Thuat toan:
			B1: Chon so dau tien n
			B2: Vong lap
				- Tim vi tri thay doi
				- Thay doi
			B3: Vong lap dung khi S[1] = 1
		-----------------------------------
		- Mang S[1..d]: mang chua cac thanh phan khac nhau tung doi cua phan tich
		S[1] > S[2] > ... > S[d]
		- Mang R[1..d]: chua thong tin ve thanh phan cua S[i]
			R[i]: chua thong xem co bao nhieu thanh phan S[i] tham gia trong phan tich
		
*/	
#include <stdio.h>
#include <conio.h>
#define max 100
int n,d,S[max],R[max];

void Nhap(){
	printf("\nNhap n: ");
	scanf("%d",&n);
}

void Khoitao(){
	//Xuat phat tu so n
	S[1] = n;		//Co 1 thanh phan n tham gia trong phan tich
	R[1] = 1;		//So luong la 1
	d = 1;
}

void InPhanTich(){
	for(int i=1; i<=d; i++)
		for(int j=1; j<=R[i]; j++)
			printf("%3d",S[i]);
	printf("\n");
}

void PhanTich(){
	Khoitao();
	InPhanTich();	//Luc nay co mot phan tich a1 ... sk
	//Tim phan tich tiep theo
	while(S[1] > 1){
		int sum = 0;
		if(S[d] == 1){
			sum = sum + R[d];
			R[d] = 0;
			d = d - 1;
		}
		sum = sum + S[d];
		R[d] = R[d] - 1;
		int temp = S[d] - 1;
		if(R[d] > 0)
			d = d + 1;
		S[d] = temp;
		R[d] = sum/temp;
		temp = sum % temp;
		if(temp != 0){
			d = d + 1;
			S[d] = temp;
			R[d] = 1;
		}
		InPhanTich();
	}
}


int main(){
	Nhap();
	PhanTich();
	getch();
	return 0;
}
