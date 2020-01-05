#include<stdio.h>
#include<stdlib.h>
void nhap(int a[], int n){
     int i;
     for(i=0;i<n;i++)
     {
         printf("a[%d]= ", i);
         scanf("%d", &a[i]);
     }
}
void chutrinh(int a[], int n){
     int b[100], i,j;
     for(i=0;i<n;i++)
     {
          b[i]=0;
     }do{
          int t=-1;
          for(i=0;i<n;i++)
          {
               if(b[i]==0)
               {
                    t=i;
                    break;
               }
               if(t==-1)
               {
                    break;
               }
               else
               {
                    b[t]=1;
                    printf("(");
                    printf("%d", t+1);
                    j=a[t]-1;
                    while(j!=t){
                          printf("%d",j+1);
                          b[j]=1;
                          j=a[j]-1;
                    }
                    printf(")");
               }
          }
     }
     while(1);
     
}
int main(){
    int a[100], n;
    printf("nhap n:");
    scanf("%d",&n);
    nhap(a,n);
    printf("chu trinh la:\n");
    chutrinh(a,n);
    getch();
    return 0;
}
