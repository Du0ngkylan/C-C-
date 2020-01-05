/*
	3.Thuat toan Doi Cho: Sinh tat ca cac hoan vi cua tap n phan tu
	
		Input:	So nguyen n
		Output:	Day cac hoan vi cua tap n phan tu {1..n}
		------------------------------------------------
*/

#include <conio.h>
#include <stdio.h>
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
	for(int i=1;i<=n;i++)
		printf("%3d",P[i]);
	printf("\n");
}

int B(int m,int i){
	if(m%2 == 0 && m>2 && i<=m-2)
		return i;
	if(m%2 == 0 && m>2 && i == m-1)
		return m-2;
	return m-1;
}

void DoiCho(int m){
	if(m == 1)
		InHoanVi();
	else{
		for(int i=1; i<=m; i++){
			DoiCho(m-1);
			if(i < m){
				int temp = P[B(m,i)];
				P[B(m,i)] = P[m];
				P[m] = temp;
			}
		}
	}
}

int main(){
	Nhap();
	Khoitao();
	DoiCho(n);
	getch();
	return 0;
}
