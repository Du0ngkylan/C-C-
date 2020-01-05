#include<stdio.h>
#include<conio.h>
#define hs 50

int a[hs],danh_dau[hs],n,m,xp,dich;
int M[hs][hs];
FILE *f;


int doc_tep(){
     int i,j,k;
     f=fopen("dt2.txt","r");
     if(f==NULL){
          puts("Loi mo tep.");
          getch();
          return 0;
          }
     fscanf(f,"%d%d",&n,&m);
     for(i=1;i<=n;i++)
          for(j=1;j<=m;j++)
              M[i][j]=0;
     for(k=1;k<=m;k++){
         fscanf(f,"%d%d",&i,&j);
         M[i][j]=1;
         }
     fclose(f);
}

void khoi_tao(){
	int i;
	for(i=1;i<=n;i++)
		danh_dau[i] = 0;
	}
	
void in_duong(int k){
	int i;
	for(i=1;i<k;i++)
		printf("%d --> ",a[i]);
	printf("%d\n",dich);
	}
	
void Try(int i){
	int j;
	for(j=1;j<=n;j++){
		if((M[a[i-1]][j] == 1)&(danh_dau[j] == 0)){
			a[i] = j;
			danh_dau[j] = 1;
			if(a[i] == dich) in_duong(i);
			else Try(i+1);
			danh_dau[j] = 0;
			}
		}
	}
	
int main(){
	doc_tep();
	khoi_tao();
	printf("Nhap dinh xuat phat:\t");
	scanf("%d", &xp);
	printf("Nhap dinh dich:\t");
	scanf("%d", &dich);
	a[1] = xp;
	danh_dau[xp] = 1;
	printf("Duong di tu %d den %d la : \n", xp,dich);
	Try(2);
	getch();
	return 0;
	
	}
