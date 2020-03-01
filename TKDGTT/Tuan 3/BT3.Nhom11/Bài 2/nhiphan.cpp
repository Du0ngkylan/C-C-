/*
 BAI 2
 phan tich mot so ve dang  nhi phan
 */
#include<stdio.h>
#include<conio.h>
void nhiphan(int n)
{
     if(n >= 0)
     {
          if(n/2 > 0)
          nhiphan(n/2);
          printf("%d",n%2);
     }
}
int main()
{
     int n;
     printf("nhap n = ");
     scanf("%d",&n);
     printf("so da nhap duoc phan tich nhi phan la:");
     nhiphan(n);
     getch();
}
