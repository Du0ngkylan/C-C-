#include<stdio.h>
#include<conio.h>
#define hs 50

int a[hs],aBest[hs],danh_dau[hs],n,m,best_cost,xp,dich;
int M[hs][hs];
FILE *f;

int doc_tep(){
     int i,j,k,l;
     f=fopen("dt1.dat","r");
     if(f==NULL){
          puts("Loi mo tep.");
          getch();
          return 0;
          }
     fscanf(f,"%d%d",&n,&m);
     for(i=1;i<=n;i++)
          for(j=1;j<=m;j++){
              M[i][j]=0;
		  }
     for(k=1;k<=m;k++){
         fscanf(f,"%d%d%d",&i,&j,&l);
         M[i][j]=l;
         M[j][i]=l;
         }
     fclose(f);
}

void in(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		    printf("%4d",M[i][j]);
		printf("\n");
	}
}

void khoi_tao(){
	int i;
	best_cost = 526;
	for(i=1;i<=n;i++)
		danh_dau[i] = 0;
	}
	
void in_duong(int k){
	int i;
	for(i=1;i<=k;i++)
		printf("%d --> ",a[i]);
	printf("%d\n",dich);
	}
	
void up_date(int c){
	int i;
	c = c + M[a[n]][a[1]];
	if(c < best_cost){
		for(i=1;i<=n;i++)
			aBest[i] = a[i];
		best_cost = c;
		}
	}
	
void Try(int i, int c){
	int j;
	for(j=1;j<=n;j++){
		if((M[a[i-1]][j]<526)&(danh_dau[j] == 0)){
			c = c + M[a[i-1]][j];
			if(c<best_cost){
				a[i] = j;
				danh_dau[j] = 1;
				if((i==n+1)&(a[i]=xp)){
					up_date(c);
					}
				else Try(i+1,c);
				danh_dau[j] = 0;
				c = c - M[a[i-1]][j];
				}
			}
			
		}
	}
	
int main(){
	doc_tep();
	khoi_tao();
	printf("Ma tran ke: \n");
	in();
	xp = dich = 1;
	a[1] = xp;
	danh_dau[xp] = 1;
	Try(1,0);
	printf("Tong chi phi nho nhat:  %d tren duong di: \n",best_cost);
	in_duong(n);
	getch();
	return 0;
	}
