// Liet ke to hop chap k cua n phan tu
/*
  Thuat toan:
        - Liet ke lan luot tu 1 - k.
        - Quay lui ve vi tri k-1 roi thay bang cac gia tri co the co cua vi tri nay.
        - Du lieu nhap vao:
                + Dong 1: n
                + Dong 2: k
        
*/
#include<stdio.h>
#include<conio.h>
void write();
void try1(int i);
int x[30];
int n,k;

void write()
{
    int i;
    FILE *f2;
    f2=fopen("nchapk.out","a");
    for(i=1;i<=k;i++)
    {
          fprintf(f2,"%d",x[i]);
    }
    fprintf(f2,"\n");
    fclose(f2);
}
void try1(int i)
{
    int j;
    for(j=0;j<=n;j++)
    {
        x[i]=j;
        if(i==k)
        write();
        else try1(i+1);
    }
}
int main()
{
    FILE *f1;
    f1=fopen("nchapk.txt","r");
    fscanf(f1,"%d %d",&n,&k);
    try1(1);
    fclose(f1);
    getch();
    return 0;
}
