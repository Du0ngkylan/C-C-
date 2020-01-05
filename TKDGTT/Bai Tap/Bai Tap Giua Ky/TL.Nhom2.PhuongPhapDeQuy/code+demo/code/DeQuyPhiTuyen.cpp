#include<stdio.h>
#include<conio.h>
int U(int n)
{	  
    int S=0;
    if(n<6) return n; 
    for(int i=5;i>0;i--) 
        S+=U(n-i);
      return S;
}
int main()
{
    int n;
    printf("nhap n: ");scanf("%d",&n);
    printf("U%d = %d",n,U(n));
    getch();
}
