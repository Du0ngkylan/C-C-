#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
int *a,n,min,max;
void input()
{
     int i;
     printf("\n Nhap vao so phan tu cua day: ");
     scanf("%d",&n);
     a=(int*)calloc(n,sizeof(int));
     srand(time(NULL));
     printf("\n Day da cho: \n");
     for(i=0;i<n;i++)
     {
                     a[i]=rand()%100;
                     printf("%d ",a[i]);
     }
}
int minmax(int *a,int l,int r,int &min,int &max)
{
     int min1,max1;
     int min2,max2;
     if(l==r) min=max=a[l];
     else
     {
         minmax(a,l,(l+r)/2,min1,max1);
         minmax(a,(l+r)/2+1,r,min2,max2);
         if(min1<min2) min=min1;
         else min=min2;
         if(max1>max2) max=max1;
         else max=max2;
     }
}
int main()
{
    input();
    minmax(a,0,n-1,min,max);
    printf("\n min=%d    max=%d",min,max);
    getch();
}
