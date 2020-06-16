// Tim max, min cua day so
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void minmax(int a[],int dau, int cuoi,int &min, int &max)
{
     int min1,min2,max1,max2;
     if(dau==cuoi)
     {
            min=a[dau];
            max=a[dau];
     }
     else
     {   
         minmax(a,dau,(dau+cuoi)/2,min1,max1);
         minmax(a,(dau+cuoi)/2+1,cuoi,min2,max2);
         
         if(min1 < min2)
             min=min1;
         else
             min=min2;
             
         if(max1 > max2)
             max=max1;
         else
            max=max2;
     }
} 

int main()
{
    int *a,n,i,max,min;
   
    a=(int *)malloc(n* sizeof(int));
    printf("Nhap so phan tu: ");
    scanf("%d",&n);
    for (i = 0; i < n; i ++)
    {
        a[i] = rand(); 
    //  a[i] = rand()%(100+1);  //tao ngau nhiên trong khoang 0 den 100
            printf("%d ",a[i]);
    }
    min = a[0];
    max = a[n-1];
    minmax(a,0,n-1,min,max);
    printf("\n\nPhan tu nho nhat cua day so la : %d",min);
    printf("\nPhan tu lon nhat cua day so la :%d",max);
    getch();
    return 0 ; 
}
