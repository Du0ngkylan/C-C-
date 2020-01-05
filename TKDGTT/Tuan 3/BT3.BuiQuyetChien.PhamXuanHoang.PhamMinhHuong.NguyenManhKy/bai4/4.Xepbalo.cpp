#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
typedef int ai[50];
typedef int af[50];
af c,a;
ai x, xopt, ind;
int n;
int w, fopt, cost, weight;

void batdau()
{
    int i,j,tg;
    int t;
    fopt=0; weight=0;
    for (i=1; i<=n; i++)
    {
        ind[i]=i;
        x[i]=0;
        xopt[i]=0;
    }
    for (i=1; i<=n-1; i++)
        for (j=1; j<=n; j++)
            if(c[i]/a[i]<c[j]/a[j])
            {
                t=c[i]; c[i]=c[j]; c[j]=t;
                t=a[i]; a[i]=a[j]; a[j]=t;
                tg=ind[i]; ind[i]=ind[j]; ind[j]=tg;
            }
}
void nhapfile()
{
   int i; 
   FILE *f;   
	if(!(f=fopen("data.txt","r")))
	{
		puts("Loi mo file");
		getch();
		exit(0);
	}
	fscanf(f,"%d %d\n",&n,&w);
	for(i=1;i<=n;i++)
		fscanf(f,"%d %d\n",&a[i],&c[i]);
	fclose(f); 

   // in du lieu da nhap
    printf("\nTrong luong cai tui la:%d",w); 
    printf("\nVec to gia tri do vat: ");
    for (i=1; i<=n; i++) printf("%d ", c[i]);
    printf("\nVec to trong luong do vat: ");
    for (i=1; i<=n; i++) printf("%d ", a[i]);
  
}
void update()
{
    int i;
    if(cost>fopt)
    {
        for (i=1; i<=n; i++) xopt[i]=x[i];
        fopt=cost;
    }
}
void nhanhcan(int i)
{
    
    int j,t;
    t=  int ((w-weight)/a[i]);
    for (j=t; j>=0; j--)
    {
        x[i]=j;
        weight=int (weight+a[i]*x[i]);
        cost=int (cost+c[i]*x[i]);
        if (i==n) update();
        else if (cost+c[i+1]*(w-weight)/a[i+1]>fopt) nhanhcan(i+1);
        weight=int (weight-a[i]*x[i]);
        cost=int (cost-c[i]*x[i]);
    }
}
void inkq()
{
    int i;
    printf("\n\n***Ket qua tinh toan***");
    printf("\nTong gia tri cua cac do vat la: %d", fopt);
    printf("\nPhuong an toi uu la: ");
    for (i=1; i<=n; i++) printf("\nSo luong do vat %d la %d", ind[i], xopt[i]);
    printf("\n***********************\n");
    getch();
}
main()
{
    nhapfile();
    batdau();
    nhanhcan(1);
    inkq();
    getch();
} 

