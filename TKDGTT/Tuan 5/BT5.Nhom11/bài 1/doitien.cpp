#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int a[100],n,T,k[100],min;
void nhap()
{
     int i,j,temp;
     printf("co may loai tien");
     scanf("%d",&n);
     printf("nhap cac loai tien hien co:\n");
     for(i=1;i<=n;i++)
     {
                      
                      printf("loai %d:",i);
                      scanf("%d",&a[i]);
     }
     for (i=1;i<n;i++)
           for (j=i+1;j<=n;j++){
                               if (a[i]<a[j]){
                                              temp = a[i];
                                              a[i] = a[j];
                                              a[j] = temp;
                                              }
                               }
     
}
  
void in()
{
     int i,j;
     printf("ket qua doi tien la:\n");
     for(i=1;i<=n;i++)
     {
                      printf("loai %d lay %d dong\n",a[i],k[i]);
     }
}                
void changeMoney(int *a,int T)
{
     int i;
     for(i=1;i<=n;i++)
      k[i]=0;
      i=1;
     while (i<=n&&T>0)
     {
           k[i]=T/a[i];
           T-=k[i]*a[i];
           i++;
     }     
     if(T>0) printf("khong co loi giai"); //Khong co loi giai
     else in();
}
int main()
{
    int i;
    printf("nhap so tien can doi\n");
    scanf("%d",&T);
    nhap();
    changeMoney(a,T);
getch();
}
      



