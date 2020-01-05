#include <stdio.h>
#include <conio.h>

void main()
{
	int n;
	do 
	{
		printf("Nhap n:\n");
		scanf_s("%d",&n);
		if(n < 0)
			printf("n khong hop le. Nhap lai\n");
	}while(n < 0);
	int sothu1 = 1, sothu2 = 1;
	if(n == 1)
	{
		printf("%d",sothu1);
	}
	else if(n == 2)
	{
		printf("%d %d",sothu1, sothu2);
	}
	else 
	{
		printf("%d %d ",sothu1, sothu2);
		for(int i = 3; i <= n; i++)
		{
			int sothu3 = sothu1 + sothu2;
			printf("%d ",sothu3);
			sothu1 = sothu2;
			sothu2 = sothu3;
		}
	}
	_getch();
}