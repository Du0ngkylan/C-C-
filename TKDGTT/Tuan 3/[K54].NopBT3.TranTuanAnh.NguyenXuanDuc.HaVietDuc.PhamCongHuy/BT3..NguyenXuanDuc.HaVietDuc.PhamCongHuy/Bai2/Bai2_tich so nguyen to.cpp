#include<conio.h>
#include<stdio.h>
//================================
int ptnt( int n)
{
    if(n>1)
    {
    	int i=2;
	    while( n%i != 0)
     	i++;
	    ptnt(n/i);       
	    printf("*%d",i);
    }
}
//================================
main()
{
int n;
	printf("\n\n Nhap vao nguyen so can phan tich :   ");  scanf("%d", &n);
	printf("\n---------------------------------------------------------\n");
    printf("\n So %d phan tich thanh tich cac thua so nguyen to la : %d = 1", n,n);
	ptnt(n);
   printf("\n");
getch();
}
