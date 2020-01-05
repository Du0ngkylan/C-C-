#include <stdio.h>
#include <conio.h>
#define max 10000
int n,a[max];
int L[max+1],T[max+1];
void nhap()
{
     printf("Nhap so phan tu cua day n = ");
     scanf("%d",&n); 
     for(int i=1;i<=n;i++){
             printf("a[%d]=",i);
             scanf("%d",&a[i]);
             }
             }     
void xuli()
{
  int i,j,jmax;

        a[0]=-32768;
        a[n+1]=32767;   
          L[n+1]=1;
          
          for(i=n;i>=0;i--){
                            jmax=n+1;
                            for(j=i+1;j<=n+1;j++)
                            if((a[j]>a[i])&&(L[j]>L[jmax]))jmax=j;
                            L[i]=L[jmax]+1;
                            T[i]=jmax;
                            }
}
int main()
{
 int i;
 nhap();
 xuli();
  printf("Day con don dieu tang dai nhat co %d phan tu",L[0]-2);
  printf("\nCac phan tu cua day do la:\n");
  i=T[0]; 
  while(i<n+1){
               printf("%d\t",a[i]);
               i=T[i];
               }                           
  getch();	
}
