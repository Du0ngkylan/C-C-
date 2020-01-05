#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *a, * b,n;
int t=0;
// khoi day cho mang a[i]
int start (int *a, int n){
    int i;
     for(i=0;i<=n;i++)
     a[i]=1;
     return 0;
}
int in(int b[] , int n, int x ){
   printf("\nHoan vi thu %d ", x);
   for(int i=0;i<n;i++)
   printf("%d   ", b[i]);
   return 0;

}
int hoanvi(int i , int t){
    for(int j=1;j<=n;j++)
    if(a[j]){
              b[i]=j;
              a[j]=0;
            if(i==n){
                       t++;
                       in(b ,n,t);
                }
             else hoanvi(i+1,t);
             a[j]=1;
        }
    return 0;
}
int main(){
   printf("Nhap vao so phan tu cua tap hop N= ");
   scanf("%d",&n);
   a=new int[n+1];
   b=new int[n+1];
  int t=0;
   start(a,n);
   hoanvi(1,t);
   getch();
   return 0;}
