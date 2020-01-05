/*Bai toan nguoi ban hang */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100
int n;
int matran[max][max];
int daqua[max];
int pa[max];
int chiphi;
int c;

void DocDL()
{
     FILE *f;
     f = fopen("NguoiBanHang.txt", "r");
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
     fscanf(f, "%d", &matran[i][j]);
     fclose(f);
}

void InPa()
{
     int i;
     puts("");
     for(i=1; i<=n; i++)
     printf("%d -> ", pa[i]);
     printf("%d - %d", pa[n+1], chiphi);
     puts("");
}

void Try(int i)
{
     for(int j=2; j<=n; j++)
     if(!daqua[j] && matran[pa[i-1]][j])
     {
                  pa[i] = j;
                  daqua[j] = 1;
                  c += matran[pa[i-1]][j];
                  if(i==n)
                  {
                          if(matran[pa[n]][1])
                          {
                                              chiphi = c;
                                              chiphi += matran[pa[n]][1];
                                              pa[n+1] = 1;
                                              InPa();
                          }
                  }
                  else
                  Try(i+1);
                  daqua[j] = 0;
                  c -= matran[pa[i-1]][j];
     }
}

void inmt()
{
     for(int i=1; i<=n; i++)
     {
             puts("");
             for(int j=0; j<=n; j++)
             printf("%3d", matran[i][j]);
             }
}

int main()
{
    DocDL();
    daqua[1] = 1;
    pa[1] = 1;
    c = 0;
    Try(2);
    getch();
}
