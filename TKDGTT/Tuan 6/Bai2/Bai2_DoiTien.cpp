/*
	Bai toan: Co n loai tien xu : x[1] x[2] ... x[n] 
	           Hay chi ra mot cach de doi so tien M can dung it dong xu nhat
			hoac chi ra la khong co cach doi.			
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define VOCUNG 32767
#define MAX 100

int n,M,x[MAX];// n: so luong dong xu, M: so tien can doi
int L[MAX][MAX];

void DocTep(){
    int i;
	FILE *f;
	f = fopen("DOITIEN.txt","r");
	
	if(!f){
        printf("\nLoi Mo Tep!");
		getch();
		exit(0);
	}
	else{
		fscanf(f,"%d%d",&n,&M);
		for(i = 1; i <= n; i++)
			fscanf(f,"%d",&x[i]);		
	}
	fclose(f);		
}

void CoSoQHD(){
	int i,j;
	for(j=0;j<=M;j++)
		L[0][j] = VOCUNG;			
	for(i=0;i<=n;i++)
		L[i][0] = 0;			
}
void In(){
    int i,j;
	printf("\nSo tien can doi: %d ",M);
	printf("\nCac menh gia: ");
    for(i=1;i<=n;i++)
	   printf("%d ",x[i]);
}


int min(int a,int b){
	if(a < b)
		return a;
	return b;
}

void BPA(){
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=M;j++)
			if(x[i]>j)
				L[i][j] = L[i-1][j];
			else
				L[i][j] = min(L[i-1][j] , L[i][j-x[i]] + 1);
}

void TruyVet(){
	if(L[n][M] == VOCUNG)
		printf("\nKhong co phuong an!");
	else{
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
}

int main(){
	DocTep();
	In();
	CoSoQHD();
	BPA();	
	TruyVet();
    getch();
    return 0;
}
