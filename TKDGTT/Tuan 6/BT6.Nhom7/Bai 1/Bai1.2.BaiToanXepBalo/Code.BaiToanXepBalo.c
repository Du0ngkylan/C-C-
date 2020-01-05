/*
	Bai toan xep ba lo 0-1
	De bai: Co N do vat. Moi do vat co gia tri va trong luong tuong ung(pi,wi) 
	Tim cach cho cac vat vao ba lo co trong luong P sao cho dat gia tri cao nhat
	Moi vat chi duoc chon 1 lan
*/
/*
	Cac buoc giai bai toan quy hoach dong:
		1. Tim cong thuc truy hoi
		2. Xac dinh Co so QHD
		3. Lap bang phuong an
		4. Ket qua toi uu cua bai toan
		5. Truy vet tim nghiem
*/
/*
	C(i,j): GTri ($) max khi chon cac vat tu 1 den i voi trong luong balo j
	Cong thuc truy hoi
		1. Do vat thu i duoc chon: C(i,j) = C(i-1,j-pi) + wi (DK:pi <=j- Vat dc dua vao phai co khoi luong <= khoi luong con chua dc cua balo)
			Neu vat thu i dc chon de xep vao ba lo: - Khoi luong balo de chua cac dvat khac giam di
													- Giá tri cua balo tang len
		2. Do vat thu i khong duoc chon C(i,j) = C(i-1,j)
		3. C(i, j) =max(1,2) - max cua 2 truog hop tren. Th nào co gia tri lon hon thi chon
	Co so QHD
		C(0,j) = 0 - khong dvat nao dc chon
		C(i,0) = 0 - balo da day
	Lap bang phuong an: Mang 2 chieu
	Ket qua toi uu: Gia tri LN tren bang phuog an
	Truy vet tim nghiem: 
		- Bat dau tu o co gtri toi uu
		- Neu C(i, j) = C(i-1,j): vat khong dc chon.Xet tiep C(i-1,j)
			  C(i,j) = C(i-1,j-pi) + wi: vat dc chon.Xet tiep o C(i-1,j-pi)
	
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define hs 50

int n; //so do vat
int wmax; //Trong luong toi da cua balo
int p[hs]; //mang luu gia tri cua cac vat
int w[hs]; //mang luu trong luong cua cac vat
int c[hs][hs]; //mang 2 chieu luu bang ph.an


void nhap()
{
	int i;
	FILE *f;
	f = fopen("XepBaLo.txt","r");
	if(!f)
	{
		puts("Loi mo tep");
		getch();
		exit(0);	
	}
	fscanf(f,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fscanf(f,"%d%d",&p[i],&w[i]);	
	}
	fscanf(f,"%d",&wmax);
	fclose(f);
		
}
void bangPhuongAn()
{
	int i=0,j=0;
	//co so quy hoach dong
	for(i=0;i<=n;i++) 
		c[0][i] = 0;
	for(j=0;j<=wmax;j++)
		c[j][0] = 0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=wmax;j++)
		{
			c[i][j] = c[i-1][j];//gan bang TH ko co dieukien
			if(w[i]<=j)
			{
				if(c[i-1][j-w[i]] + p[i] > c[i][j])
					c[i][j] = c[i-1][j-w[i]] + p[i];
			}		
		}	
	}	
}
void timNghiem()
{
	//bat dau tu o c[n,W]??? co chac la gia tri nay la lon nhat ko
	int i=n, j=wmax;
	while(i>0 && j>0)
	{
		if(c[i][j] == c[i-1][j-w[i]] + p[i])
		{
			printf("\nDo vat thu %d duoc chon (%d, %d)",i,w[i],p[i]);
			j = j - w[i];;	
		}
		i--;
	}
	printf("\nGia tri $ lon nhat ba lo la: %d",c[n][wmax]);	
}

void in()
{
	int i;

	for(i=1;i<=n;i++)
	{
		printf("\n%d\t%d",p[i],w[i]);		
	}	
}

int main()
{
	nhap();
	in();
	bangPhuongAn();
	timNghiem();
	getch();
	return 0;
		
}
