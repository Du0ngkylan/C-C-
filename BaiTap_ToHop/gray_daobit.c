#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void khoitao(int a[], int n){
     int i;
     for(i=0;i<n;i++)
     {
          a[i]=0;
     }
}
void in(int a[], int n){
     int i;
     for(i=0;i<n;i++)
     {
          printf("%d", a[i]);
     }
     printf("\n");
}
int chan_le(int a[], int n){
    int i, dem=0;
    for(i=0;i<n;i++)
    {
         if(a[i]==1){
             dem++;
         }
    }
    if(dem%2==0)
         return 1;
    else
         return -1;
}
int dao(int x){
    if(x==0)
         x=1;
    else
         x=0;
    return x;
}
int tim(int a[], int n){
    int i;
    for(i=n-1;i>=0;i--)
    {
        if(a[i]==1)
        {
            return i;
        }
    
    }
}
int gray_daobit(int a[], int n){
    int i;
    for(i=0;i<pow(2,n)-1;i++)
    {
         if(chan_le(a,n)==1)
         {
               a[n-1]=dao(a[n-1]);
         }else{
               int k=tim(a,n);
               a[k-1]=dao(a[k-1]);
         }
         in(a,n);
    }
}
         
int main(){
    int a[100], n;
    printf("nhap n:");
    scanf("%d", &n);
    khoitao(a,n);
    in(a,n);
    gray_daobit(a,n);
    getch();
    return 0;
}
    
