/* Liet ke cac hoan vi cua n phan tu */

#include <stdio.h>
#include <conio.h>
int n,count=0,a[100],dd[100];

void Nhap() {
     int i;
     printf("Nhap n =");  scanf("%d",&n);
     for(i=1;i<=n;i++) dd[i]=1;
      }

void KetQua() {
     int i;
     count+=1; 
     printf("\n% d:  ",count);
     for(i=1;i<=n;i++)
                      printf("%d ",a[i]);
      }

void Try(int i) {
     int j;
     for(j=1;j<=n;j++)
     if(dd[j]) {
               a[i]=j;
               dd[j]=0;
               if(i==n)  KetQua();
               else Try(i+1);
               dd[j]=1;
            }
      }

int main() {
       Nhap();
       Try(1);
       getch();
       return 0;
      }
