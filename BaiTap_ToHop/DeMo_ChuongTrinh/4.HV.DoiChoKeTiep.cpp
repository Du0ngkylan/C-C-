/*
	4.Thuat toan Doi Cho Ke Tiep sinh cac hoan vi n phan tu
		
		Input:	So nguyen n
		Output:	Day tat ca cac hoan vi cua tap n phan tu {1,..,n}
		---------------------------------------------------------
		Thuat toan:
			B1; Chon hoan vi dau tien 1,2, ... ,n
			B2: Vong Lap
				+ Tim vi tri doi cho k
				+ Thuc hien doi cho ke tiep
			Lap cho den khi het phan tu di chuyen
		--------------------------------------------------------
		Goi P[1..n] : day chua hoan vi
		Truoc[1..n] : chi huong di chuyen
			Truoc[i] = 1 neu i di chuyen sang phai
				 	 = 0 neu i di chuyen sang trai
		CHO[i] : chi vi tri tuong doi cua phan tu i trong {i,i+1, ... , n}
		x	   : so luong cac phan tu nho hon i ma cham bien ben trai (CHO[i] = n - i + 1)
		k	   : vi tri doi cho;
*/
#include <stdio.h>
#include <conio.h>
#define MAX 100
int P[MAX],CHO[MAX],Truoc[MAX],n;
void Nhap(){
	printf("\nNhap n: ");
	scanf("%d",&n);
}

void InHV(){
	for(int i=1; i<=n; i++)
		printf("%3d",P[i]);
	printf("\n");
}

void Khoitao(){
	for(int i=1;i<=n;i++){
		P[i] = i;
		CHO[i] = 1;
		Truoc[i] =1 ;
	}
}

void DoiChoKeTiep(){
	Khoitao();
	InHV();			//In hoan vi dau tien 1,2,...,n
	int i=1,x,k;
	while(i<n){	//Vong lap
		i=1;
		x = 0;
		
		while(CHO[i] == n-i+1){			//Vi tri i cham bien ben trai
			Truoc[i] = 1 - Truoc[i];	//Tai vi tri i thi chi duoc di chuyen sang phai
			CHO[i] = 1;
			if(Truoc[i] == 1)
				x++;
			i++;
		}
		
		if(i<n){
			//Tim vi tri doi cho k
			if(Truoc[i] == 1)			//Neu i di chuyen sang phai
				k = CHO[i] + x;			
			else
				k = n - i + 1 - CHO[i] + x;
			int temp = P[k];			//Doi cho
			P[k] = P[k+1];
			P[k+1] = temp;
			InHV();
			CHO[i] = CHO[i] + 1;		//Sau khi doi cho thi vi tri tang len 1 do doi cho [k,k+1]
		}
	}
}

int main(){
	Nhap();
	DoiChoKeTiep();
	getch();
	return 0;
}
