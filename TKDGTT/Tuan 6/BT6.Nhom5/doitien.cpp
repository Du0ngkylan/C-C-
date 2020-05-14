#include<stdio.h>
#include<conio.h>
#define hs 50

int C[hs][hs];
int d[hs],chon[hs];
int n,m;

void nhap(){
	int i;
	for ( i=1; i<=n; i++){
		printf("Nhap d[%d]=  ",i);
		scanf("%d",&d[i]);
		}
	}
	
void in(){
	int i;
	for ( i=1; i<=n; i++){
		printf("%4d",d[i]);
		}
	printf("\n");
	}
	
	
void doitien(){
	int i,j;
	for (i=0; i<=n; i++){
		C[i][0] = 0;
		}
	for (j=1; j<=m; j++){
		C[0][j] = hs;
		}
	for ( i=1; i<=n; i++){
		for ( j=1; j<=m; j++){
			C[i][j] = C[i-1][j];
			if( (d[i]<=j) &&((C[i][j-d[i]]+1)<C[i][j]))
			    C[i][j] = C[i][j-d[i]] + 1;
			}
		}
	}
	
void truyvet(){
	int i,j;
	i=n; 
	j = m;
	while( j>0 ){
		if( C[i][j] == C[i-1][j]){
			i = i-1;
			chon[i] = 0;
			}
		if( C[i][j] == ( C[i][j-d[i]] + 1) ){
			j = j-d[i];
			printf("%4d",d[i]);
			}
		}
	}
	
int main(){
	int i;
	printf("Nhap vso so loai menh gia: n =   ");
	scanf("%d",&n);
	printf("Nhap vao tung loai menh gia: \n");
	nhap();
	printf("Nhap vao so tien can doi: m ( m < 50 ) =   ");
	scanf("%d",&m);
	doitien();
	printf("Cach doi: ");
	truyvet();
	getch();
	return 0;
	}
