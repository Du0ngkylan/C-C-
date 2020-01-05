/* Bai toan xau ABC */

#include <stdio.h>
#include <conio.h>
#define MAX 100

int min,n;		
int x[MAX],w[MAX];

int IsSame(int i,int leng) {
	int k;
	for(k = 0; k < leng; k++)
		if(x[i-k] != x[i-k-leng])			
			return 1;
	return 0;
}

int Check(int i){		
    int leng;
	for(leng = 1;leng <= (i+1)/2; leng++)
		if(IsSame(i,leng) == 0)		
			return 0;
	return 1;							
}

void GhiNhanNghiemToiUu(){
	int k;
	for(k = 0; k < n; k++)
		w[k] = x[k];
}

void Try(int i,int s){		
	int v,j,T;
	for(v = 'A'; v <= 'C'; v++){	
		x[i] = v;					
		if(Check(i) == 1)			
		{
			if(v == 'C')			
				T = s + 1;
			else
				T = s;
			if(T + (n-i)/4 < min){				
				if(i == n-1){					
					min = T;
					GhiNhanNghiemToiUu();
				}
				else
					Try(i+1,T);			
			}
		}
	}
}

void XauABC(){
	int i;
	for(i=0; i<n;i++){
		x[i] = 0;	
		w[i] = 0;		
	}
	x[0] = 65;			
	min = n;
	Try(1,0);		
}

void InKQ(){
	int i;
	printf("\nXau Thoa man La: ");
	for(i = 0; i<n; i++)
		printf("%c",w[i]);
}

int main(){
	printf("\nNhap vao chieu dai cua xau: ");
	scanf("%d",&n);
	XauABC();	
	InKQ();
    getch();
    return 0;
}
