#include<stdio.h>
#include<stdlib.h>
void bangphanhoach(int a[][100], int n){
     int i,j;
     a[0][0]=1;
     for(i=1;i<n;i++)
     {
         a[i][0]=0;
         for(j=0;j<=i;j++)
         {
             a[i][j]=a[i-1][j-1]+a[i-j][j];
         }
         
     }
}
void partition(int a[], int i, int v){
     if(v==0){
              int j;
              for(j=0;j<i;j++)
              {
                   printf("%d", a[j]);
              }
              printf("\n");
     }
     else{
          int min= a[i-1] < v ? a[i-1] :v ;
          int j;
          for(j=min;j>=1;j--)
          {
              a[i]=j;
              partition(a,i+1, v-j);
          }
     }
}
void in(int a[][100], int n){
     int i,j;
     for(i=1;i<n;i++)
     {    
         for(j=0;j<=i;j++)
         {
              printf("%5d", a[i][j]);
         }
         printf("\n");
     }
}
int main(){
    int a[100][100], b[100], n,i,j;
    
    printf("nhap n:");
    scanf("%d", &n);
    
    printf("bang phan hoach la:\n");
    
    bangphanhoach(a,n);
    in(a,n);
    
    printf("cac phan hoach nguyen la:\n");
    
    partition(b,0,n);
    getch();
    return 0;
}
