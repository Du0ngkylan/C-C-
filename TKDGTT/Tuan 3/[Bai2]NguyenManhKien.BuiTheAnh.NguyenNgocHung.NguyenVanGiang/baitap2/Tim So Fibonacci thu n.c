#include <stdio.h>
#include <conio.h>
int main()
{
  int n,i;
  double f1,f2,fi;
  printf("Nhap vao so nguyen 2<=n<=47: ");
  scanf("%d",&n);
  f1=f2=1;
  if (n<=2)
        fi=1;
  else
         for(i=3;i<=n;i++)
         {
          fi=f1+f2;
          f1=f2;
          f2=fi;
        }
   printf("So Fibonacci thu %d la %.0lf \n",n,fi);
    getch();
}
