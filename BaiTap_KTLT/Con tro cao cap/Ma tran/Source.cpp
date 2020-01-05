#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void CapPhat(int**& a, int sodong,int socot)
{
	a = new int* [sodong];     // Cấp phát tạo ra các dòng
	for(int i = 0; i < sodong; i++)
	{
		a[i] = new int[socot];
	}
}
void NhapMaTran(int** a,int sodong, int socot)
{
	for(int i = 0; i < sodong * socot; i++)
	{
		printf("Nhap vao a[%d][%d]",i / socot,i % socot);
		scanf_s("%d",&a[i/socot][i%socot]);
	}
}
void XuatMaTran(int** a,int sodong, int socot)
{
	for(int i = 0; i < sodong * socot; i++)
	{
		printf("%d\t",a[i/socot][i%socot]);
		if((i + 1) % socot == 0)
			printf("\n");
	}
}
void ThuHoi(int*** a, int sodong)
{
	for(int i = 0; i < sodong; i++)
	{
		delete [](*a)[i]; 
	}
	delete [](*a);
}
void XoaDong(int**&a , int& sodong, int socot, int dongcanxoa)
{
	for(int i = dongcanxoa; i < sodong - 1; i++)
	{
		for(int j = 0; j  < socot; j++)
		{
			a[i][j] = a[i+1][j];
		}
	}
	sodong--;
	a =(int**) realloc(a, sodong * sizeof(int));
}
void XoaCot(int**&a, int sodong, int& socot, int cotcanxoa)
{
	for(int i = 0; i < sodong; i++)
	{
		for(int j = cotcanxoa; j < socot - 1;j++)
		{
			a[i][j] = a[i][j+1];
		}
	}
	socot--;
	for(int i = 0; i < sodong; i++)
	{
		a[i] = (int*)realloc(a[i], socot * sizeof(int));
	}
}
void ThemDong(int**&a, int& sodong, int socot, int vitrithem, int dongcanthem[])
{
	sodong ++;
	a = (int**)realloc(a, sodong * sizeof(int));
	a[sodong - 1] = new int [socot];
	for(int i = sodong - 1; i > vitrithem; i--)
	{
		for(int j = 0; j  < socot; j++)
		{
			a[i][j] = a[i-1][j];
		}
	}
		for(int j = 0; j < socot; j++)
			a[vitrithem][j] = dongcanthem[j];
} 
void main()
{
	int** a = NULL;
	int sodong = 3, socot = 3;
	CapPhat(a, sodong, socot);
	NhapMaTran(a, sodong, socot);
	XuatMaTran(a, sodong, socot);
	//XoaDong(a, sodong, socot, 2);
	//XoaCot(a, sodong, socot,0);
	int vitrithem;
	//int* dongthem = new int[socot];
	int dongthem[3];
	printf("Ban muon them vao vi tri nao?");
	scanf_s("%d",&vitrithem);
	printf("\n Nhap dong muon them:\n");
	for(int i = 0; i < socot; i++)
	{
		printf("Nhap phan tu thu dongthem[%d]",i);
		scanf_s("%d",&dongthem[i]);
	}
	ThemDong(a, sodong, socot, vitrithem, dongthem);
	XuatMaTran(a, sodong, socot);
	if( a != NULL)
		ThuHoi(&a, sodong);

	_getch();
}