#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define hs 50

int C[hs][hs];
char x[hs],y[hs];
int n,m;

void nhap(){
	printf("Nhap vao xau x:  ");
	gets(x);
	printf("Nhap vao xau y:  ");
	gets(y);
	n = strlen(x)-1;
	m = strlen(y)-1;
	}
	
void in(){
	printf("Xau x: ");
	puts(x);
	printf("Xau y: ");
	puts(y);
	}
	
void khoitao(){
	int i,j;
	for( i=0; i<=n; i++){
		for( j=0; j<=m; j++){
			C[i][j] = 0;
			}
		}
	}

int min(int p, int q, int r){
	int min1;
	if( p<q ) min1 = p;
	else min1 = q;
	if( r<min1 ) min1 = r;
	return min1;
	}	
	
void quyhoach(){
	int i,j;
	for(i=0; i<=n; i++){
		C[i][0] = i;
		}
	for( j=0; j<=m; j++){
		C[0][j] = j;
		}
	for( i=1; i<=n; i++){
		for( j=1; j<=m; j++){
			if( x[i]==y[j] ){
				C[i][j] = C[i-1][j-1];
				}
			else{
				C[i][j] = min(C[i][j-1]+1,C[i-1][j-1]+1,C[i-1][j]+1);
				}
			}
		}
	}
	
void truyvet(){
	int i,j;
	i=n;
	j=m;
	while( (i>0) && (j>0) ){
		if(C[i][j] == C[i-1][j-1] ){
			printf("Giu nguyen %c.\n",x[i]);
			i--;
			j--;
			}
		if(C[i][j] == (C[i][j-1]+1) ){
			printf("Chen %c vao sau %c.\n",y[j],x[i]);
			j--;
			}
		if(C[i][j] == (C[i-1][j-1]+1)){
			printf("Thay the %c bang %c.\n",x[i],y[j]);
			i--;
			j--;
			}
		if(C[i][j] == (C[i-1][j]+1)){
			printf("Xoa %c.\n",x[i]);
			i--;
			}
		}
	}
	
int main(){
	nhap();
	printf("\nHai xau da nhap: \n");
	in();
	khoitao();
	quyhoach();
	printf("\nCach bien doi x ve y di tu cuoi xau x len: \n");
	truyvet();
	getch();
	exit(0);
	}
