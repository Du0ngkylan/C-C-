#include <stdio.h>
#include <conio.h>

int ptnt( int n)
{
    if(n>1)
	{
	   int i = 2;
	   while(n%i != 0)
	       i++;
	   ptnt(n/i);
	   printf("%d*", i);
    }
}

main()
{
    int n;
    printf("\n Nhap so can phan tich thanh tich cac so nguyen to n = ");
    scanf("%d", &n);
    printf("\n => %d = ", n);
    ptnt(n);
    getch();
}
