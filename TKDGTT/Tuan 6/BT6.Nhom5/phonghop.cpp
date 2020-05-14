#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define hs 50

int a[hs],b[hs],d[hs],L[hs];
int n;

void nhap(){
	FILE *f;
	int i,j;
	f = fopen("cuoc_hop.txt","r");
	if(!f){
		printf("Loi mo tep\n");
		exit(0);
		}
	fscanf(f,"%d",&n);
	for( i=1; i<=n; i++){
		fscanf(f,"%d %d ",&a[i],&b[i]);
		}
	fclose(f);
	}

void khoitao(){
	int i;
	for( i=1; i<=n; i++){
		d[i] = 0;
		L[i] = 1;
		}
	}
	
int max( int p[], int q){
	int i,max1;
	max1 = p[1];
	for( i=2; i<=q; i++){
		if( p[i] > max1 ){
			max1 = p[i];
			}
		}
	return max1;
	}

void quyhoach(){
	int i,j;
	for( i=1; i<=n; i++){
		if( a[i+1] >= b[i] ){
			L[i+1] = max(L,i) + 1;
			}
		else{
			for( j=1; j<i; j++){
				if( (b[j]<a[i]) && ((L[j]+1)>L[i]) ){
					L[i] = L[j] + 1;
					}
				}
			}
		}
	}
	
void truyvet(){
	int i,j;
	int max1;
	max1 = max(L,n);
	printf("So cuoc hop toi da: %d.\n",max1);
	j = 1;
	while( j < max1 ){
		for(i=1; i<=n; i++){
			if(L[i]==j){
				printf(" Thu tu %d : bat dau luc %2dh  -  ket thuc luc %2dh.\n",i,a[i],b[i]);
				j++;
				}
			}
		}
	}
	
int main(){
	nhap();
	khoitao();
	quyhoach();
	truyvet();
	getch();
	exit(0);
	}
