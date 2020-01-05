#include<stdio.h>
#include<conio.h>
int GT(int n)
{
	    int s=1,i;
	    for(i=1; i<=n; i++)
		  s=s*i;
		  return s;
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d",&n);
    printf("\n%d! = %d",n,GT(n));
    getch();
}
