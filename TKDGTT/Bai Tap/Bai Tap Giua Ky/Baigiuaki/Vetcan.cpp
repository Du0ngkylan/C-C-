#include <stdio.h>
#include <conio.h>

int n=0;
float min,tong_kc;
int kt[20],vt[20],kq[20];
float kc[20][20]={0};

void xuli(int i)
{
          int j;
          if (i<=n)
          {
                   for (j=1;j<=n;j++)
                   if (kt[j])
                   {
                      kt[j]=0;
                      vt[i]=j;
                      xuli(i+1);
                      kt[j]=1;
                   }
          }
          else
          {
              tong_kc=0;
              for (j=1;j<n;j++)    
              tong_kc += kc[vt[j]][vt[j+1]];
              if (tong_kc<min)
              {
                 for (j=1;j<=n;j++) kq[j]=vt[j];
                 min=tong_kc;
              }
          }
}

int main()
{
    int i,j;
    printf("nhap so dinh n= ");
    scanf("%d",&n);
    printf("nhap khoang cach giua cac dinh : \n");
    for (i=1;i<n;i++)
    for (j=i+1;j<=n;j++)
    {
        printf("kc[%d][%d]= ",i,j);    
        scanf("%f",&kc[i][j]);
        kc[j][i]=kc[i][j];
    }
    for (i=1;i<=n;i++) 
    {
        kq[i]=i;
        kt[i]=1;
    }
    for (i=1;i<n;i++) min += kc[i][i+1];
    xuli(1);
    printf("thu tu di den cac dinh de tong khoang cach la nho nhat : \n");  
    for (i=1;i<=n;i++)
    printf("%d  ",kq[i]);
    printf("\n tong khoang cach la : %f \n",min);
    getch();
}
