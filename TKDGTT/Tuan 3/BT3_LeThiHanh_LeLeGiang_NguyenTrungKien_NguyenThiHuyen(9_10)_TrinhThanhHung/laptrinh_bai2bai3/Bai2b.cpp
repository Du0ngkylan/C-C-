#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void PhanTich(int n)
{     
	int d;
	d = 2; 		       
	if (n==1)
    {
		getch();
		exit(0);	
	}		       
	else 
	{
   		 while ((n%d) != 0)  
           d = d+1 ;
		printf("%d ",d); 
		PhanTich(n/d);
	}    
}
int main()
{
	int n;
	printf("\nNhap n= ");scanf("%d",&n);
	PhanTich(n);
	getch();
	return 0;	
}
