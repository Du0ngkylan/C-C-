#include<stdio.h>
#include<stdlib.h>
void nhap(int a[], int b[], int n){
     int i;
     for(i=0;i<n;i++)
     {
         a[i]=i+1;
         b[i]=0;
     }
}
void printSubset(int a[], int b[], int n){
     int i;
     printf("{");
     for(i=0;i<n;i++)
     {
         if(b[i]==1)
         {
              printf("%d", a[i]);
         }
     }
     printf("}\n");
}
void nextSubset(int a[], int n){
     int j=n-1;
     while(j>=0){
           if(a[j]==1)
           {
                a[j]=0;
           }else{
                 a[j]=1;
                 break;
           }
           j--;
     }
}
void enumerate(int a[], int b[], int n){
     int i,j;
     unsigned long max = pow( 2,n);
     
     for(j=0;j<n;j++)
     {
         b[j]=0;
     }
     
     for(i=0;i<max;i++)
     {
         printSubset(a,b,n);
         nextSubset(b,n);
     }
}
int main(){
    int a[100], b[100], n;
    printf("nhap n:");
    scanf("%d", &n);
    
    nhap(a,b,n);
    printf("cac tap con sinh ra la:\n");
    enumerate(a,b,n);
    
    getch();
    return 0;
}
