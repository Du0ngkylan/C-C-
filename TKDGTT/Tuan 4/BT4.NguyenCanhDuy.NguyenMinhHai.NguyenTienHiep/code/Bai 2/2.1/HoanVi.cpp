// Liet ke cac hoan vi cua n phan tu
/*
   Thuat toan:
        - Dung mang flag de danh dau cac phan tu y[] da duoc chon.
        - Dien cac phan tu y[] vao x[] lan luot voi dieu kien flag != 0
        - Dien den phan tu thu n thi quay lui lai va thay the phan tu thu n-1 bang cac phan tu
          khac co the
        - Du lieu nhap tu file gom: 
             + Dong 1: n = so phan tu
             + n dong tiep theo: n phan tu nhap vao.
*/

#include<stdio.h>
#include<conio.h>
void write();
void try1(int i);
int x[30],y[30],flag[30];
int n;

void write()
{
     int i;
     FILE *f2;
     f2=fopen("hoanvin.out","a");
     for(i=1;i<=n;i++)
     {
                      fprintf(f2,"%d",x[i]);
     }
     fprintf(f2,"\n");
     fclose(f2);
}
void try1(int i)
{
              int j;
              if(i==n+1)
              {
                   write();
                   printf("%d %d %d %d\n",x[1],x[2],x[3],x[4]);
              }
              else
              {
                  for(j=1;j<=n;j++)
                  {
                                   if(flag[j]==0)
                                   {
                                                 flag[j]=1;    //danh dau phan tu da co
                                                 x[i]=y[j];    //gan vao chuoi nghiem.
                                                 try1(i+1);    
                                                 flag[j]=0;    //khoi phuc trang thai cua vi tri j
                                   }
                                   
                  }
              }
}
int main()
{
    FILE *f1;
    int i=0;
    f1=fopen("hoanvin.txt","r");
    fscanf(f1,"%d",&n);
    for(i=1;i<=n;i++)
    {
            fscanf(f1,"%d\n",&y[i]);
            flag[i]=0;
    }
    try1(1);
    fclose(f1);
    getch();
    return 0;
}
