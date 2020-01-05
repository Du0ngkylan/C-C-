#include<stdio.h>
#include<conio.h>

int mang[100],n;

void swap(int *x, int *y)
{
     int tmp;
     tmp = *x;
     *x = *y;
     *y = tmp;
}
void hoan_vi(int k)
{
     int j;
     if (k == 1)
     {
           printf("\n");
           for (j=0; j<n; j++)
               printf("%d ", mang[j]);
     }
     else
         for (j=k-1; j>=0; j--)
         {
             swap(&mang[k-1], &mang[j]);
             hoan_vi(k-1);
             swap(&mang[j], &mang[k-1]);
         }
}
int main()
{
     int i;
     printf("nhap so phan tu n= ");
     scanf("%d", &n);
     for (i=0; i<n; i++)
              mang[i] = i;
     printf("cac hoan vi cua %d phan tu la: ",n);
     hoan_vi(n);
     getch();
}
