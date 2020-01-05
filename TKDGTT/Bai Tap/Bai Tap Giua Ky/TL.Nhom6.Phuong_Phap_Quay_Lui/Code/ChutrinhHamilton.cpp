//Thuat toan chu trinh Hammilton_la chu trinh qua moi dinh cua do thi dung 1 lan
//Do Thi Vo Huong

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define hs 50
//nhap ma tran = ds cung
int dau[hs],cuoi[hs],n,m,d[hs],v[hs],co;
void nhap() {
	FILE *f;
	int k;
	char s[100];
	f=fopen("dt.dat","r");
	if(!f){
		printf("Loi mo tep");
		getch();
		exit(0);
	}
	fscanf(f,"%d %d ",&n,&m);
	for(k=1;k<=m;k++) {
		fscanf(f,"%d%d ",dau+k,cuoi+k);
	}
	fclose(f);
} 

void in() {
	int i;
	printf("\nDanh sach cung:\n\n");
	for(i=1;i<=m;i++)
	printf("%d   %d\n",dau[i],cuoi[i]);
	printf("\n");
}

int cung(int x,int y) {
	int k;
	for(k=1;k<=m;k++)
	if(dau[k]==x && cuoi[k]==y) return 1;
	return 0;
}

void induong(int k) {
	int i;
	printf("Chu trinh Hamilton:\n\n");
	for(i=1;i<=k;i++)
	printf("%d-->",v[i]);
	printf("%d",v[1]);
	printf("\n");
	co=1;
}

void Try(int k) {
	int i;
	if(k>n) return;
	if(k==n && cung(v[k],v[1])) {
		induong(n);
		getch();
		exit(0);
	}
	for(i=1;i<=n;i++)
	if(d[i]==0 && cung(v[k],i)) {
		d[i]=1;
		v[k+1]=i;
		Try(k+1);
		d[i]=0;
	}
}

int main() {
	int i;
	nhap();
	in();
	co=0;
	
	for(i=1;i<=n;i++)  d[i]=0;
	v[1]=1;
	Try(1);
	if(!co) printf("Khong co chu trinh Hamilton");
	getch();
}
