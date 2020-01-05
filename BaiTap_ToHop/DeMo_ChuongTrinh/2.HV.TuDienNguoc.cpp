/*
	2.Thuat toan Tu Dien Nguoc: Sinh tat ca cac hoan vi
		
		Input:	So nguyen n
		Output:	Day cac hoan vi vua tap n phan tu {1..n}
		------------------------------------------------
		
*/
#include <stdio.h>
#include <conio.h>
#define max 100
int n,P[max];

void Nhap(){
	printf("\nNhap n: ");
	scanf("%d",&n);
}

void Khoitao(){
	for(int i=1; i<=n; i++)
		P[i] = i;
}

void InHoanVi(){
	for(int i=1; i<=n; i++)
		printf("%3d",P[i]);
	printf("\n");
}

void Dao(int m){
	int l=1,r=m;
	while(l<r){
		int temp = P[l];
		P[l] = P[r];
		P[r] = temp;
		l++;
		r--;
	}
}

void TDN(int m){
	
	if(m == 1)
		InHoanVi();
	else{
		//printf("\nm = %d",m);
		for(int i=1; i<=m; i++){
			TDN(m-1);
			if(i < m){
				int temp = P[i];
				P[i] = P[m];
				P[m] = temp;
				Dao(m-1);
			}
		}
	}	
}

int main(){
	Nhap();
	Khoitao();
	TDN(n);
	getch();
	return 0;
}
