#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define hs 100

int dau[hs],cuoi[hs],v[hs],d[hs],w[hs];
int n,m,i,j,k,min;  
void nhap(){
	FILE *f;
	f = fopen("dt.dat","r");
	if(!f){
		printf("Loi mo tep\n");
		getch();
		exit(0);
		}
	fscanf(f,"%d %d",&n,&m);
	for(k=1;k<=m;k++){
		w[k] = 0;
		fscanf(f,"%d %d %d",&dau[k],&cuoi[k],&w[k]);
		}
	fclose(f);
	}
	
void khoitao(){
	int i;
	for( i=1; i<=n; i++){
		d[i] = 0;
		v[i] = 0;
	    }
	}	
void baotrum(){
	int tiep = 1;
	v[1] = 1;
	d[dau[1]] = 1;
	d[cuoi[1]] = 1;
	while(tiep){
		tiep = 0;
		min = 100;
		for( i=1; i<=m; i++){
			if( (v[i]==0) && ( d[dau[i]] + d[cuoi[i]] == 1) ){
				if ( w[i] < min) min = w[i];
				}
			}
		for(i=1; i<=m; i++){
			if( (v[i]==0) && (d[dau[i]] + d[cuoi[i]] == 1) )
				if( w[i]==min){
					v[i] = 1;
				    d[dau[i]] = 1;
				    d[cuoi[i]] = 1;
				    tiep = 1;
				}
			}
		}
	}
	
void incay(){
	int i;
	for( i=1; i<=n; i++){
		if( d[i] == 0){
			printf("Do thi khong co cay bao trum \n");
			getch();
			exit(0);
			}
	for( i=1; i<=m; i++){
		if( v[i] == 1)
			printf("%d -> %d\n",dau[i],cuoi[i]);
		}
	}
}
	
int main(){
	nhap();
	khoitao();
	baotrum();
	printf("Cay bao trum toi thieu cua do thi da cho la: \n");
	incay();
	getch();
	exit(0);
	}
