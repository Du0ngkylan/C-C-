#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhap(int a[], int n){
     int i;
     for(i=0;i<n;i++)
     {
          printf("a[%d]=", i);
          scanf("%d", &a[i]);
     }
}
void convert(int a[], int n){
     int i;
     while(n!=0){
          a[i]=n%2;
          n=n/2;
          i++;
     }
}
int xor(int i, int j){
    if((i==0&&j==1)|| (i==1 && j==0)){
            return 1;
    }
    else
            return 0;
}
void khoitao(int a[], int b[],int c[], int n){
     int i;
     for(i=0;i<n;i++)
     {
          a[i]=0;
          b[i]=0;
          c[i]=0;
     }
}


    
void in(int a[], int b[], int n){
     int i;
     printf("{");
     for(i=0;i<n;i++)
     {
         if(a[i]==1)
         {
              printf("%d", b[i]);
         }
     }          
     printf("}\n");
}
void Gray(int n){
     int a[100],b[100], c[100];
     int d[100];
     nhap(d,n);
     khoitao(a,b,c,n);
     int i,j,k;
     for(i=0;i<(int)pow(2,n); i++)
     {
         convert(a,i);
         convert(b,i/2);
         k=n-1;
         for(j=0;j<n;j++)
         {
             c[j]=xor(a[k], b[k]);
             k--;
         }
         in(c,d,n);
     }
}
int main(){
    int n;
    printf("nhap n:");
    scanf("%d", &n);
    Gray(n);
    getch();
    return 0;
}
