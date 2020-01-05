/*
	DE BAI: Cho n goi keo
			Moi goi keo co mot so cai keo la a[i]
			Y/C: Hay chia n goi keo lam 2 phan sao cho chenh lech jua 2 phan la it nhat
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100


int n,a[MAX];
int S = 0;
int L[MAX][MAX];
int P[MAX];

void NhapDuLieu(){
	FILE *f;
	f = fopen("CHIAKEO.INP","r");
	
	if(f != NULL){
		fscanf(f,"%d",&n);
		int i;
		for(i = 1; i <= n; i++){
			fscanf(f,"%d",&a[i]);
			S += a[i];
		}
		S = S/2;
		fclose(f);
	}else{
		printf("\nLoi Mo Tep!");
		getch();
		exit(0);
	}
		
}

void In(){
	printf("\n");
	for(int i=1; i<=n; i++){
		for(int j=1; j<=S; j++)
			printf("%5d",L[i][j]);
		printf("\n\n");
	}
}

void CoSoQHD(){
	int i,j;
	for(j = 1; j <= S; j++)
		L[0][j] = 0;
	for(i = 1; i <= n; i++)
		L[i][0] = 1;
}

void QHD(){
	int i,j;
	for(i = 1; i<= n; i++)
		for(j = 1; j<= S; j++)
			if(L[i-1][j] == 1)
				L[i][j] = 1;
			else
				if(j >= a[i])
					if(L[i-1][j-a[i]] == 1)
						L[i][j] = 1;
					else
						L[i][j] = 0;
	//In();			
}

void TruyVet(){
	//Tim tong so keo lon nhat ma co the duoc lay ra tu 1 so goi keo
	int j = S,vt = -1;
	int i;
	printf("\nj = %d",j);
	while(j > 0 && vt == -1){
		for(i = n; i >=1; i--)
			if(L[i][j] == 1){
				vt = j;
				break;
			}
		j--;
	}
	j = vt;
	printf("\ni = %d, j =%d",i,j);
	//Xac dinh cac goi keo trong phan 1
	while(i >0 && j>0){
		if(j >= a[i])
			if(L[i-1][j-a[i]] == 1){
				P[i] = 1;
				j =j - a[i];
			}
		i--;
	}
	
}

void KetQua(){
	int i;
	printf("\nCach chia keo nhu sau: ");
	printf("\n\tPhan 1: ");
	for(i = 1; i <= n; i++)
		if(P[i] == 1)
			printf("%5d",a[i]);
	printf("\n\tPhan 2: ");
	for(i = 1; i <= n; i++)
		if(P[i] == 0)
			printf("%5d",a[i]);
}

int main(){
	NhapDuLieu();
	CoSoQHD();
	QHD();
	TruyVet();
	KetQua();
    getch();
    return 0;
}
