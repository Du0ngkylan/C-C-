/*	Bai toan: Vong tron so nguyen to:
	Mot vong tron chua 2*n chu so, can dien cac so tu 1 toi 2*n vao cac vi tri
	sao cho	tong cua hai vi tri lien tiep nhau luon la mot so nguyen to*/
#include<stdio.h>
#include<conio.h>

int n,dd[100], x[100];

void nhap(int *n)
{
	printf("Nhap vao so n = ");	
	scanf("%d",n);	
}

int ngto(int n)
{
	for(int i=3; i< n/2+1; i++)		
		if(n %i ==0)
			return 0;
	if(n == 2)
		return 1;
	return 1;
}

void in(int n, int x[100])
{
	printf("\n");	
	for(int i=1; i<= 2*n; i++)
		printf("%4d", x[i]);
}
void Try(int i, int n, int *dd, int *x)
{
	for(int j=1; j<= 2*n; j++)
	{
		if(*(dd+j) ==0 && ngto(*(x+i-1) + j) == 1)	
		{
			*(x+i) = j;
			*(dd+j) = 1;
			if(i == 2*n)
			{
				in(n,x);
				getch();
			}
			else
				Try(i+1, n, dd, x);
			*(dd+j) = 0;
		}
	}
}

int main()
{
	nhap(&n);
	x[1]= 1;
	dd[1] = 1;
	printf("Vong tron nguyen to la(An Enter de co phuong an tiep theo): ");
	Try(2,n,dd,x);
	getch();
	return 0;
}
