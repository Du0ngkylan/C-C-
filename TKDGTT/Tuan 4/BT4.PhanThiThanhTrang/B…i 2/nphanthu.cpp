#include <stdio.h>
#include <conio.h>
#define MAX 10
int mang[MAX];
int n;

void swap (int *x, int *y)
{
     int temp;
     temp = *x;
     *x = *y;
     *y = temp;
     }
     void hoanvi(int k)
     {
          int j;
     if (k==1)
     {
          printf("\n");
          for (j=0; j<n; j++)
          printf("%d ", mang[j]);
          }
          else
          for (j=k-1; j>=0; j--)
          {
                  
                  swap(&mang[k-1], &mang[j]);
                  hoanvi(k-1);
                  swap(&mang[j], &mang[k-1]);
                  }
                  }
                  int  main()
                  {
                       int i;
                       printf("\nCho biet so phan tu (n < 10) : ");
                       scanf("%d", &n);
                       for (i=0; i<n; i++)
 
        mang[i] = i;
        hoanvi(n);
        getch();}

