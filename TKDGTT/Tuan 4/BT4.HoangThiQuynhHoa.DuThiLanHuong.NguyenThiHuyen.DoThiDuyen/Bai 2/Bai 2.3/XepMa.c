/*
 Bai toan xep quan ma
 De bai: Hãy chi ra 1 cach di cua quan ma xuat phat tu 1 o (x, y)
 nao do co the di qua tat ca cac o co, moi o co 1 lan duy nhat
 Quan ma co the di hinh chu L
 Tien hoac lui 2 o roi dich trai hoac phai 1 o
 Trai hoac phai 2 o roi tien hoac lui 1 o
 */ 
#include<stdio.h>
#include<conio.h>

int n, M[50][50], h=0;
int a[] = {2, 2, -2, -2, 1, -1, 1, -1};
int b[] = {1, -1, 1, -1, 2, 2, -2, -2};
// 2 mang dai dien cho 8 buoc di cua quan ma

void khoitao();
void Try(int k, int x, int y);
void inkq();

void khoitao()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			M[i][j] = 0; // danh dau cac o con trong	
		}	
	}	
}

void Try(int k, int x, int y)
{ 
	int i, xmoi, ymoi;
	for(i=0;i<8;i++)
	{
		// Chon tung huong di de thu
		xmoi = x + a[i];
		ymoi = y + b[i];
		if(xmoi >=0 && xmoi < n && ymoi >=0 && ymoi < n && M[xmoi][ymoi] == 0)
		{
			M[xmoi][ymoi] = k;	
			if(k == n*n)
			{
				inkq();	
				printf("\n\n");
			}
			else
			{
				Try(k+1, xmoi, ymoi);	
			}
			M[xmoi][ymoi] = 0;
		} 	
	}	
}
void inkq()
{
	int i,j;
	h++;
	printf("\nLoi giai thu %d : ",h);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t", M[i][j]);	
		}
		puts("\n");
	}	
}

int main()
{
	n=5;
	printf("Voi ban co %d * %d cac canh xep quan ma la: \n\n", n, n);
	int i, j;
	khoitao();
	//Try(2, 1, 2);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			khoitao();		
			M[i][j] = 1;
			Try(2, 1, 2);
			break;
			break;
			exit(0);
		}	
		break;
		exit(0);	
		
	}	 	

	getch();
	return 0;
}
