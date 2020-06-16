 //chu trinh hammilton  _ phuong phap quay lui

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n,m,dau[50],cuoi[50],v[50],w[50];
int co,d[50];
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
		fscanf(f,"%d %d %d",dau+k,cuoi+k,w+k);
		fgets(s,100,f);
	}
	fclose (f);
}
void induong(int k) {
     int i;
     printf("\nChu trinh Hamilton:\n");
     for(i=1;i<=k;i++)
     printf("%d--->",v[i]);
     printf("%d",v[1]);
     printf("\n");
     co=1;
     }
int cung(int i,int j) {
    int k;
    for(k=1;k<=m;k++)
    if(dau[k]==i && cuoi[k]==j)  return 1;
    return 0;
}
void tim(int k) {
     int i;
     if(k>n) return;
     if(k==n && cung(v[k],v[1])) {
             induong(n);
             getch();
             exit(0);
             }
       for(i=1;i<=n;i++)
       if(d[i]==0 && cung(v[k],i)) {
                   d[i] =1;
                   v[k+1]=i;
                   tim(k+1);
                   d[i]=0;
                   }
     }
int main() {
    Nhap();
    co=0;
    for(int i=1;i<=n;i++) d[i]=0;
    v[1]=1;
    tim(1);
    if(!co) printf("\nDo thi khong co chu trinh Hamilton");
    getch();
    return 0;
    }
