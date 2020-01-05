#include <stdio.h>
#include <conio.h>
#define MAX 100

int Tmin,n;		//Tmin: so chu C xuat hien trong xau
				//n: chieu dai cua xau can sinh
int x[MAX],w[MAX];

void Nhap(){
	printf("\nNhap vao chieu dai cua xau: ");
	scanf("%d",&n);
}


int IsSame(int i,int leng){
	int k;
	for(k = 0; k < leng; k++)
		if(x[i-k] != x[i-k-leng])			//Neu ton tai 1 vi tri ma 2 xau con khac nhau thi se khac nhau
			return 1;
	return 0;
}

int Check(int i){			//i: chieu dai cua xau hien tai
	int leng;
	for(leng = 1;leng <= (i+1)/2; leng++)
		if(IsSame(i,leng) == 0)			//Khong chua hai day con giong nhau
			return 0;
	return 1;							//Khong chua hai day con giong nhau
}

void GhiNhanNghiemToiUu(){
	int k;
	for(k = 0; k < n; k++)
		w[k] = x[k];
}

void Try(int i,int s){			//i: tim ki tu i cua xau, s: chi phi hien thoi
	int v,j,T;
	for(v = 'A'; v <= 'C'; v++){		//x[i] co the nhan 1 trong 3 ki tu : 'A','B','C'
		x[i] = v;						//Cho x[i] = 1 trong 3 ki tu do
		if(Check(i) == 1)			//Khong chua 2 xau con lien nhau giong nhau
		{
			if(v == 'C')				//Neu la ki tu 'C' tang T len 1
				T = s + 1;
			else
				T = s;
			if(T + (n-i)/4 < Tmin){				//Neu chi phi tam thoi(T) van nho hon chi phi toi uu(Tmin)
				if(i == n-1){					//Sinh du cau hinh thi luu lai nghiem toi uu
					Tmin = T;
					GhiNhanNghiemToiUu();
				}
				else
					Try(i+1,T);			//Thu voi x[i+1] voi chi phi hien tai la T
			}
		}
	}
}

void XauABC(){
	int i;
	for(i=0; i<n;i++){
		x[i] = 0;		//Khoi tao mang luu nghiem tam thoi
		w[i] = 0;		//Khoi tao mang luu nghiem toi uu
	}
	x[0] = 65;			//Ki tu ban dau la A
	Tmin = n;
	Try(1,0);			//Tim ki tu tai vi tri 1 voi chi phi ban dau la 0
}

void InNghiem(){
	int i;
	printf("\nXau Thoa man La: ");
	for(i = 0; i<n; i++)
		printf("%c",w[i]);
}

int main(){
	Nhap();
	XauABC();	
	InNghiem();
	//char a[] = {'A','A'};
	//printf("\nKqua = %d",Check(1));
    getch();
    return 0;
}
