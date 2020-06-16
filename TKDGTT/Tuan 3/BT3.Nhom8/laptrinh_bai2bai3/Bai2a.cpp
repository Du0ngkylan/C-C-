#include<conio.h>
#include<stdio.h>
void Int2Bin(int n)
{   
   if (n>0) 
       Int2Bin(n/2);
       printf("%d",n%2);	
}
int main()
{
	int n;
	printf("\nNhap n= ");scanf("%d",&n);
	Int2Bin(n);
	getch();
	return 0;		
}
