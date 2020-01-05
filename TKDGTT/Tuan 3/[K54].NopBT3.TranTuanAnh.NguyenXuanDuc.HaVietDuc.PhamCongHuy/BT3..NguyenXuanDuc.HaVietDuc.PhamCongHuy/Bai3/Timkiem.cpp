#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void swap(int a[],int n)
{
     int i,j,temp;
     for(i=0;i<n-1;i++)
      for(int j=i+1;j<n;j++)
     {
        if(a[i]>a[j])
        {
          temp=a[j];
          a[j]=a[i];
          a[i]=temp;             
        }                             
     }     
}

void in(int a[], int n)
{
     int i;
     for(i=0;i<n;i++)
     {
      printf(" %d ",a[i]);                
     }     
}

void timkiem(int a[],int dau,int cuoi, int m)
{
     
     if(dau==cuoi)
     {
          if(m==a[dau])
          {        
          printf("\nPhan tu %d da co trong mang.",m);
          }
          else printf("\nPhan tu %d khong co trong mang.",m);
     }
     else
     {
         int temp=(dau+cuoi)/2;
         if(a[temp]<m)
         {
           timkiem(a,temp+1,cuoi,m);         
         }
         else timkiem(a,dau,temp,m);           
       }   
}

int main() 
{ 
    int a[10]={2, 7, 1, 5, 3, 8, 6, 4, 9, 10};
    int i; 
    swap(a,10);
    printf("Mang sau khi da sap xep la: ");
    in(a,10);
    timkiem(a,0,9,5);
    getch(); 
    return 0 ; 
}  
