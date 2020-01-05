#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define hs 50

int a[hs][hs],C[hs][hs],d[hs][hs];
int m,n;

void nhap(){
	int i,j;
	for( i=1; i<=m; i++)
		for ( j=1; j<=n; j++){
			printf("Nhap a[%d][%d] =  ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	
void in(int k[hs][hs]){
	int i,j;
	for ( i=1; i<=m; i++){
		for ( j=1; j<=n; j++)
			printf("%4d",k[i][j]);
		printf("\n");
		}
	printf("\n");
	}
	
void khoi_tao(){
	int i,j;
	for ( i=1; i<=m; i++) 
		for ( j=1; j<=n; j++)
			d[i][j] = 0;
	}
	
int max( int x, int y){
	if( x>=y ) return x;
	return y;
	}
	
void quyhoachdong(){
	int i,j;
	for( i=0; i<=m; i++)
		C[i][0] = 0;
	for( i=0; i<=n; i++)
		C[0][i] = 0;
	for( i=1; i<=m; i++)
		for ( j=1; j<=n; j++){
			C[i][j] = max(max(C[i-1][j-1],C[i][j-1]),max(C[i][j-1],C[i+1][j-1]))+a[i][j];
			}
	}

void truyvet(){
	int i,j,k;
	i = m; 
	j = n;
	d[i][j] = 1;
	while( j>0 ){
		k = C[i][j] - a[i][j];
		if(C[i-1][j-1]==k){
			d[i-1][j-1] = 1;
			i--;
			j--;
			}
		if(C[i][j-1]==k){
			d[i][j-1] = 1;
			j--;
			}
		if(C[i+1][j-1]==k){
			d[i+1][j-1] = 1;
			i++;
			j--;
			}
		}
	}

int main(){
	int i,j;
	printf("Nhap bang so: \n");
	printf("Nhap so hang m =  ");
	scanf("%d",&m);
	printf("Nhap so cot n =  ");
	scanf("%d",&n);
	nhap();
	printf("Bang so da nhap: \n");
	in(a);
	khoi_tao();
	quyhoachdong();
	in(C);
	printf("Duong di lon nhat la %d:\n",C[m][n]);
	d[m][n] = 1;
	truyvet();
	for( i=1; i<=m; i++)
		for ( j=1; j<=n; j++)
			if ( d[i][j]==1 ) printf("%4d",a[i][j]);
	getch();
	exit(0);
	}
