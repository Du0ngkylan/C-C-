/*
	DE BAI: Co n laoi tien xu : x[1] x[2] ... x[n]
		Y/C: Hay chi ra mot cach de doi so tien M can dung it dong xu nhat
			hoac chi ra la khong co cach doi.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define VOCUNG 32767
#define MAX 100

int n,M,x[MAX];
int L[MAX][MAX];

void NhapDuLieu(){
	FILE *f;
	f = fopen("DOITIEN.INP","r");
	
	if(f != NULL){
		fscanf(f,"%d%d",&n,&M);
		int i;
		for(i = 1; i <= n; i++)
			fscanf(f,"%d",&x[i]);
		fclose(f);
	}else{
		printf("\nLoi Mo Tep!");
		getch();
		exit(0);
	}
		
}

void CoSoQHD(){
	int i,j;
	for(j = 0; j <= M; j++)
		L[0][j] = VOCUNG;			//Bieu dien tong j ma khong dung dong xu nay
	for(i = 0; i <= n; i++)
		L[i][0] = 0;			//Bieu dien 0 xu bang mot so dong xu
}
void In(){
	printf("\n");
	for(int i=0; i<=n; i++){
		for(int j=0 ; j<=M; j++)
			printf("%7d",L[i][j]);
		printf("\n\n");
	}
}

int min(int a,int b){
	if(a < b)
		return a;
	return b;
}

void QHD(){
	int i,j;
	for(i = 1; i <= n; i++)
		for(j = 1; j<= M; j++)
			
				L[i][j] = min(L[i-1][j] , L[i][j-x[i]] + 1);

}

void TruyVet(){
	int i = n, j =M;
	printf("\nSo dong xu it nhat can dung la: %d",L[i][j]);
	printf("\nCac dong xu su dung de doi la: \n");
	while(i>0 && j>0){
		if(L[i][j] == L[i-1][j])
			i--;
		else
			if(L[i][j] = L[i][j-x[i]] + 1){
					printf("%5d",x[i]);
					j = j - x[i];
			}
	}
}

int main(){
	NhapDuLieu();
	CoSoQHD();
	QHD();
	TruyVet();
    getch();
    return 0;
}
