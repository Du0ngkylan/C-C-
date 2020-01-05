//bai toan doi tien
#include<stdio.h>
#include<conio.h>
void nhap(int a[],int n)
{
     int i;
     for(i=0;i<n;i++)
     {
           printf("a[%d] =  ",i);
           scanf("%d",&a[i]);                
     }     
}
void in(int a[],int n)
{
     int i;
     for(i=0;i<n;i++)
         printf("%d  ",a[i]);     
}
void swap(int *a,int *b)
{
     int t;
     t=*a;
     *a=*b;
     *b=t;     
}
//sap xep tang
void sapxep(int a[],int n)
{
     int i,j;
     for(i=0;i<n;i++)
     for(j=n-1;j>i;j--)
     if(a[j]>a[j-1])
           swap(&a[j],&a[j-1]);     
}
void chuyendoi(int a[],int n,int m)
{
     int i,j=0,tong=0;int k[100];
     for(i=0;i<n;i++)
     {
          k[i]=0;       //k la tap nghiem cua bai toan       
     }     
     i=0;
     while(i<n && m>0)//neu kha thi
     {
          k[i]=m/a[i];//them vao tap nghiem
          m -=k[i]*a[i];
          i++;          
     }
     if(m>0) printf("\nko co loi giai.");
     else
     {
         for(j=0;j<i;j++)
         {
              tong  += k[j];              
         }    
         for(j=0;j<i;j++)
         {
              printf("\nmenh gia %d doi so to : %d",a[j],k[j]);                
         }
         printf("\ntong so to la: %d ",tong);
     }
}
int main()
{
    int n,m,a[100];
    printf("\nnhap so menh gia tien n= ");scanf("%d",&n);
    nhap(a,n);
    sapxep(a,n);
    in(a,n);
    printf("\nnhap so tien can doi m= ");scanf("%d",&m);
    chuyendoi(a,n,m);
    getch();
}
