#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100
int n;
int a[max][max];
int daxet[max];
int pa[max];
int chiphi;


void nhap()
{
     int i,j;
     printf("___________Bai toan nguoi dua hang____________________\n");
     printf("nhap so thanh pho:"); scanf("%d",&n);
     while (n<1)
           {printf("nhap lai so thanh pho:"); scanf("%d",&n);}
     printf("nhap vao duong di giua cac thanh pho\n"
     "Neu co duong nhap chi phi la so bat ki.\nKhong co nhap 0.\n");
     for(i=1;i<=n;i++)
     {
                      a[i][i]=0;
        for(j=i+1;j<=n;j++)
         {
                      printf("a[%d][%d]=",i,j);scanf("%d",&a[i][j]);
                      while(a[i][j]<0)
                      {
                       printf("nhap lai a[%d][%d]=",i,j);scanf("%d",&a[i][j]);
                      }
                      a[j][i]=a[i][j];
         }
     }
}
void khoitao()
{
      int j;
      for(j=1;j<=n;j++)
      daxet[j]=1;
}
void inmatran()
{
     int i,j;
     printf("\n_______So do thanh pho da nhap nhu sau________\n");
     for(i=1;i<=n;i++)
     {
     for(j=1;j<=n;j++)
     printf("| %d\t|",a[i][j]);
     printf("\n");
     }
}
void in()
{
     int j;
     printf(" \nKet qua cua bai toan giai bang phuong phap nhanh can la:\n");
     if(chiphi==1000)
     printf("Khong co duong di");
     else
     {
         printf("Duong di la:\n");
     for(j=1; j<=n; j++)
              printf("%d -> ", pa[j]);
              
     printf("%d\n Tong chi phi quang duong di la: %d", pa[n+1], chiphi);
     }
}

void Try(int i, int c)
{
     int j;
     int c1;
     for(j=2; j<=n; j++)
     {
              if(daxet[j]==1 && a[pa[i-1]][j]!=0)
              {
               c1 = c + a[pa[i-1]][j];
               if(c1<chiphi)
                 {
                           pa[i] = j;
                           daxet[j] = 0;
                           c = c1;
                           if(i==n)
                           {
                           if(a[pa[n]][1]!=0 && (c+ a[pa[n]][1]) < chiphi)
                                          {
                                               pa[n+1] = 1;
                                               chiphi = c+ a[pa[n]][1];
                                          }
                           }
                           else
                                               Try(i+1, c);
                                               daxet[j] = 0;
                 daxet[j]=0;
                 }
               }
     }
}


int main()
{
    nhap();
    inmatran();
    khoitao();
    pa[1] = 1;
    chiphi = 1000;
    Try(2, 0);
    in();
    getch();
    exit(0);
}


