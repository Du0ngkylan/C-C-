/*
Phuong phap quay lui:
       tim duong di tu A den B trong me cung
       */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define hs 50
int n, m,co, dau[hs], cuoi[hs], dd[hs], xp, dich, b[hs], q[hs],M[hs][hs],v[hs];

void Nhap() {
    int i,j,k;
    FILE *f;
    f = fopen("dl1.txt","r");
    if(!f) {
        printf("Loi mo tep");
        getch();
        exit(0);
    }
    fscanf(f,"%d %d",&n,&m);
	for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            M[i][j] = 0;
    for(k=1;k<=m;k++) {
        fscanf(f,"%d %d",&i,&j);
        M[i][j] = 1;
    }
     fclose(f);
}	

void KhoiTao() {
	int i;
	for(i=1;i<=n;i++) b[i] = 1;
}

int cung(int i, int j) {
	return M[i][j]==1;
}

void Induong(int k) {
	int i;
	for (i=1;i<k;i++)
		printf("%d ---> ", v[i]);
	printf("%d\n",dich);
	co = 1;
}

void LietKe(int k) {
	int i; 
	if (k>n) return;
	if (v[k]==dich)  {
		Induong(k); 
        return;
	}
	for (i=1;i<=n;i++)
		if (b[i]==1)
			if (cung(v[k],i)) {
				v[k+1]=i; 
				b[i]=0; 
				LietKe(k+1);
				b[i]=1;
			}		
   }

int main()
{
	Nhap();
	co = 0; 
	KhoiTao();
	printf("\nNhap dinh xp =  ");
	scanf("%d",&xp);
	printf("\nNhap dinh dich =  ");
	scanf("%d",&dich);
	v[1]=xp;
	b[xp]=0;
	LietKe(1);
	if (!co) printf("Khong co duong");
	getch();

}
