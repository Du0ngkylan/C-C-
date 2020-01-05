/*
	9.Thuat toan sinh tat ca cac phan hoach
	
		Input:	So nguyen n
		Output:	Tat ca cac phan hoach cua tap {1..n}
		--------------------------------------------
		* Tu tuong thuat toan: Xay dung phan hoach P = {A1, A2, ..., Ak}
			+ Qui uoc: 
				- Sap cac khoi theo thu tu tang dan cua phan tu be nhat nam trong khoi
				- Danh dau cac khoi theo thu tu: 1 2 ... k
				- A[i] : chi so cua khoi chua phan tu i (i=1,..,n)
					1 <= A[i] <= max(A[1], A[2], ..., A[i-1]) + 1		(*)
				- Sap xep cac day chi so tang dan theo thu tu tu dien
					+ Day be nhat: 	1 1 ... 1 <==> {1, 2, ..., n}
					+ Day lon nhat:	1 2 ... n <==> {{1}, {2}, ... {n}}
				- Mang Max[1..n] thoa: 
					+ Max[1] = 0;
					+ Max[i] = max(Max[i-1],A[i-1])		(**)
		--------------------------------------------------------------
		* Thuat toan: Sinh cac phan hoach
			B1: Chon day dau tien 1 1 ... 1
			B2:	Vong lap
				- Xay dung mang Max[1..n] (dua vao (**))
				- Tim day ke tiep cua day tren
					+ Tim vi tri thay doi p: p = max{i|A[i] <= Max[i]}
					+ Neu p>=2 thi thay doi:
						# A[i] = A[i] 		neu i<p
						# A[p] = A[p] + 1 	neu i=p
						# A[i] = 1 			neu i>p
			B3: Lap cho den khi A[n] = n;
				
*/
#include<stdio.h>
#include<conio.h>
#define Size 100
int n,A[Size],Max[Size];

void Nhap(){
	printf("\nNhap n: ");
	scanf("%d",&n);
}

void Khoitao(){
	int i;
	for(i=1; i<=n; i++)
		A[i] = 1;
	Max[1] = 0;
}

void InPhanHoach(){
	printf("\n{");
	for(int i=1; i<=n; i++){
		printf("{");
		for(int j=1;j<=n;j++)
			if(A[j] == i)
				printf("%3d,",j);
		printf("} ");
	}
	printf("}");
}

int max(int a,int b){
	if(a > b)
		return a;
	return b;
}

void PhanHoach(){
	//B1: Chon day dau tien 1 1 ... 1
	Khoitao();
	InPhanHoach();
	//B2: Vong lap
	
	while(A[n] != n){
		//Xay dung cac mang Max[1..n]
		for(int i=2; i<=n; i++)
			Max[i] = max(Max[i-1],A[i-1]);
		
		//Tim day ke tiep cua day tren
		int p = n;		//Tim vi tri thay doi p : p = max{i | A[i] <= Max[i]}
		while(A[p] >= Max[p] + 1)
		 	p--;
		 	
		A[p] = A[p] + 1;			//Thay doi
		
		int k;
		if(p < n)
			for(k=p+1; k<=n; k++)
				A[k] = 1;	
		InPhanHoach();
		//InMang();
	}
	
}

int main(){
	Nhap();
	PhanHoach();
	getch();
	return 0;
}
