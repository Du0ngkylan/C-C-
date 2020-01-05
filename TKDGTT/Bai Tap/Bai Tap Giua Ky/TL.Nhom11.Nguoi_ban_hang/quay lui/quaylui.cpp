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
     FILE *f;
    f = fopen("nguoibanhang.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
        exit(0);
    }
    fscanf(f, "%d", &n);
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            fscanf(f, "%d", &a[i][j]);
    fclose(f);
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
     printf("\ndo thi duong di\n\n");
     for(i=1;i<=n;i++)
     {
     for(j=1;j<=n;j++)
     printf("| %d\t|",a[i][j]);
     printf("\n");
     }
}
void in()
{
     int j,i;
     FILE*f;
     f=fopen("ketqua.txt","w");
     fprintf(f,"\ndo thi duong di\n\n");
     for(i=1;i<=n;i++)
     {
     for(j=1;j<=n;j++)
     fprintf(f,"| %d\t|",a[i][j]);
     fprintf(f,"\n");
     }
     if(chiphi==1000)
     {
                     printf("Khong co duong di");
                     fprintf(f,"Khong co duong di");
     }
     else
     {
         printf("\nDuong di la:\n");
         fprintf(f,"\nduong di la:\n");
     for(j=1; j<=n; j++)
              {
                    printf("%d -> ", pa[j]);
                    fprintf(f,"%d -> ", pa[j]);
              }
     printf("%d\n Tong chi phi quang duong di la: %d", pa[n+1], chiphi);
     fprintf(f,"%d\n Tong chi phi quang duong di la: %d", pa[n+1], chiphi);
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


