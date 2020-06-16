#include "conio.h"
#include "stdio.h"

void swap(int *a, int *b)
{
int tam =*a;
*a= *b;
*b= tam;
return;
}
int main()
{

  int x[30], n,i,k,l,r, dem;

  printf("\Nhap vao so phan tu: ");
  scanf("%d",&n);
  // Khoi gan gia tri cua day
  for (i=0; i<n; i++)
        x[i] = i+1;
  dem=0;
  while (i>=0)
  {
    for (i=0; i<n; i++)
        printf("%d  ",x[i]);
    printf("\n");
    dem++;

    i= n-2;

    while((i>=0) &&(x[i]> x[i+1])) i--;

    k=n-1;


    while (x[k]<x[i]) k--;

    swap(&x[k], &x[i]);

    l= i+1;
    r= n-1;
     while(l<r)
     {
            swap(&x[l], &x[r]);
         l++;
         r--;
     }

  }

  printf("%d",dem);
  getch();
}
