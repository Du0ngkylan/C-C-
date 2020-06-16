//sac so bang 2
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int v[50] , cuoi[50],t[5];

int n,m,dau[50];

void Nhap() {
	int k;
	char s[200];
	FILE *f;
	f=fopen("dt.dat","r");
	if(!f) {
		puts("Loi mo tep");
		getch();
		exit(0);
	}
	fscanf(f,"%d %d",&n,&m);
	fgets(s,200,f);
	for(k=1;k<=m;k++) {
		fscanf(f,"%d %d",dau+k,cuoi+k);
		fgets(s,100,f);
	}
	fclose (f);
}

void khoitao() {
     int i;
     for(i=1;i<=n;i++) t[i] =1;
     }

int tim() {
    int i;
    for(i=1;i<=n;i++)
    if(t[i] == -1) return i;
    return 0;
    }
int ke(int i, int j) {
    int k;
    for(k=1;k<=m;k++)
    if((dau[k]==i && cuoi[k]==j) || (dau[k] ==j && cuoi[k]==i))
    return 1;
    return 0;
    }

void xet() {
     int x,y,tiep;
     x=tim();
     while(x>0) {
                tiep =1;
                t[x]=0;
                while(tiep) {
                            for(x=1;x<=n;x++)
                            if(t[x] >=0)
                            for(y=1;y<=n;y++)
                            if(ke(x,y)) {
                                        if(t[x] ==t[y]) {
                                                printf("Do thi khong co sac so bang 2");
                                                getch();
                                                exit(0);
                                                }
                                        if(t[y] == -1) {
                                                t[y] =1-t[x];
                                                tiep =1;
                                                }
                                        }
                          }
                x= tim();
                }
     printf("Do thi co sac so bang 2");
     }
 int main() {
     Nhap();
     khoitao();
     xet();
     getch();
     return 0;
     }
