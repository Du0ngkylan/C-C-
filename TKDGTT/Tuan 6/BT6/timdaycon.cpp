#include <iostream.h>
#include <fstream.h>
#include<stdio.h>
#include<conio.h>
#define Max 100
//ifstream fin("BIG.INP");
//ofstream fout("BIG.OUT");

void Nhap(int a[],int n)
{
     for(int i=0;i<n;i++)
     {
            printf("\na[%d]:",i);
            scanf("%d",&a[i]);
     }
}
void XuLy(int a[],int n)
{
     int i,j,d=0,min,b[n+2];
     for(i=0;i<n;i++)
     {
                     min=a[i];
                     for(j=i+1;j<n;j++)
                     {
                                       if(a[i]>a[j])
                                       {
                                                    min=a[j];
                                       }
                     }
                     if(a[i]==min)
                     {
                                  d++;
                                  b[i]=a[i];
                     }
     }
     for(i=0;i<n;i++)
     {
                     if(b[i]==a[i])
                     {
                                printf("%d\t",b[i]);
                     }
     }
}
int main()
{
    int n,a[Max];
    printf("nhap vao so phan tu cua mang:");
    scanf("%d",&n);
   
    Nhap(a,n);
    XuLy(a,n);
    getch();
}
