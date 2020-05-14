#include<stdio.h>
#include<conio.h>
#define hs 50

int C[hs][hs];
int w[hs],p[hs],chon[hs];
int n;

void nhap(){
	int i;
	for ( i=1; i<=n; i++){
		printf("Nhap trong luong: w[%d] =  ",i);
		scanf("%d",&w[i]);
		printf("Nhap gia tri: p[%d] =  ",i);
		scanf("%d",&p[i]);
		}
	}
	
void in(){
	int i;
	for ( i=1; i<=n; i++)
		printf(" %d - %d\t",w[i],p[i]);
	printf("\n");
	}
	
int max(int x, int y){
	if( x>=y ) return x;
	return y;
	}
	
void quyhoachdong(){
	int i,j;
	for ( i=0; i<=n; i++){
		C[i][0] = 0;
		C[0][i] = 0;
		}
	for( i=1; i<=n; i++)
		for( j=1; j<=n; j++){
			C[i][j] = C[i-1][j];
			if(j >= w[i])
				C[i][j] = max(C[i-1][j-w[i]] + p[i],C[i-1][j]);
			}
	}
	
void truyvet(){
	int i,j,k,l;
	int max = 0;
	for ( i=1; i<=n; i++)
		for( j=1; j<=n; j++ )
			if( C[i][j] > max) max = C[i][j];
	for ( i=1; i<=n; i++)
		for ( j=1; j<=n; j++)
			if ( C[i][j] == max ){
				k = i;
				l = j;
				}
	chon[k] = 1;
	for ( i=k; i>0; i-- )
		for( j=l; j>0; j-- ){
			if ( C[i][j] == C[i-1][j] ){
				chon[i-1] = 0;
				}
			if ( C[i][j] == (C[i-1][j-w[i]] + p[i]) ){
				chon[i-1] = 1;
				}
			}
	for ( i=1; i<=n; i++)
		if ( chon[i] == 1 )
			printf("%4d",i);
	}
	
int main(){ 
	printf("Nhap vao so do vat: n=  ");
	scanf("%d",&n);
	nhap();
	printf("Do vat co trong luong va gia tri tuong ung la:\n");
	in();
	quyhoachdong();
	printf("Cach chon:\n");
	truyvet();
	getch();
	return 0;
	}
