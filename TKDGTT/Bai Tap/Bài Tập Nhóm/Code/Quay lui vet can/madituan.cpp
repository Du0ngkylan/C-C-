#include <stdio.h>
#include <conio.h>

#define KICHTHUOC 5

// Do lech cua dong & cot giua vi tri con ma den cac nuoc di
int d[] = {2, 2, 1, -1, -2, -2, -1, 1};
int c[] = {1, -1, -2, -2, -1, 1, 2, 2};

int banco[KICHTHUOC][KICHTHUOC];		// Vi tri cac nuoc di 
int soloigiai = 0;

void khoitao();							// Xoa het nuoc di tren ban co
void nuocdi(int, int, int);				// Ham tim nuoc di cua con ma
void innuocdi(int banco[][KICHTHUOC]);	// In cac nuoc di cua con ma

void main()
{
	int i, j;

	// Duyet het ban co de chon nuoc di thu 1
	for (j=0; j<KICHTHUOC; j++)
		for (i=0; i<KICHTHUOC; i++)
		{
			khoitao();					// Xoa het nuoc di tren ban co
			banco[j][i] = 1;			// Nuoc di thu 1 tai o (j, i)
			nuocdi(2, j, i);			// Nuoc di thu 2 xuat phat tu o (j, i)
		}
}

// Xoa het nuoc di tren ban co
void khoitao()
{
	int i, j;
	for (j=0; j<KICHTHUOC; j++)
		for (i=0; i<KICHTHUOC; i++)
			banco[j][i] = 0;
}

// Ham tim nuoc di thu n, xuat phat tu o (y, x)
void nuocdi(int n, int y, int x)
{
	for (int i=0; i<8; i++)	// 8 nuoc di co the
	{
		// Chon thu huong di thu i (trong 8 huong di)
		int ymoi = y + d[i];
		int xmoi = x + c[i];
		
		// Neu huong di nay hop le va tai vi tri do chua co nuoc di nao
		if (ymoi>=0 && ymoi<KICHTHUOC && xmoi>=0 && xmoi<KICHTHUOC && banco[ymoi][xmoi] == 0)
		{
			// => Ghi nhan nuoc di thu n nay
			banco[ymoi][xmoi] = n;

			// Neu nuoc di nay la nuoc di cuoi cung => in tat cac nuoc di
			if (n == KICHTHUOC*KICHTHUOC)
				innuocdi(banco);
			else
				nuocdi(n+1, ymoi, xmoi);	// Nguoc lai, tim nuoc di ke tiep

			// Du thanh cong hay that bai deu quay lai de tim loi giai moi
			// <=> phuc hoi trang thai truoc khi di nuoc di thu n
			banco[ymoi][xmoi] = 0;
		}
	}
}

// In cac nuoc di cua con ma
void innuocdi(int banco[][KICHTHUOC])
{
	int i, j;
	printf("Loi giai thu %d:\n", ++soloigiai); 

	
	printf(" ");
	for (i=0; i<KICHTHUOC; i++)
		printf("%3d", i);
	printf("\n");

	for (j=0; j<KICHTHUOC; j++)
	{
		printf("%d  ", j);
	
		for (i=0; i<KICHTHUOC; i++)
		{
			printf("%-3d", banco[j][i]);
		}
	
		printf("\n");
	}
	
	printf("\n\n");
}
