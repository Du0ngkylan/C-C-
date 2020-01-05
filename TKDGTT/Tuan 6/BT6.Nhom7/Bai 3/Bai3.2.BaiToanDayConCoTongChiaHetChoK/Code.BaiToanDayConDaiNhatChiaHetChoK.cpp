/*
Bai 3.2: Day con co tong chia het cho K

Bai toan: Cho 1 day gom n so nguyen duong và so nguyen duong k. Hãy tìm dãy con
	nhieu phan tu nhat co tong chia het cho k
Phan tich: 
	A[1..n] mang luu n so nguyen duong
	
	F(i,v) = chieu dai day con dai nhat, chia k du v 
	1. Cong thuc truy hoi
		+ F(i,v) = F(i-1,v) neu day con dai nhat ko chua A[i]
		+ Neu day con co chua A[i]
			r = A[i] mod k
			=> F(i,v) = F(i-1,v-r) + 1
	=> F[i][v] = max(F[i-1][v], F[i-1][0] +1) TH v=r
	   F[i][v] = max(F[i-1],[v], F[i-1][(v-r+k)%k] + 1) TH v != r;

	2 Co so QHD: i=1 day con co 1 phan tu
		F(1,v) =0 neu r khac v
		F(1,v) = 1 neu r =v
*/	

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define hs 50

int n, k;//n: so cac phan tu, k:so nguyen k
int r;//so du
int A[hs];// mang luu gia tri cua day ban dau
int F[hs][hs]; //F[1..n][0..k-1]


void nhap()
{
	int i=1;
	int v=0;
	FILE *f;
	f = fopen("input.txt","r");
	if(!f)
	{
		puts("Loi mo tep");
		getch();
		exit(0);	
	}
	fscanf(f,"%d%d", &n, &k);
	
	for(i=1; i<=n; i++)
	{
		fscanf(f,"%d", &A[i]);
		printf("%d\t", A[i]);	
	}
	//khoi tao
	for(i=1; i<=n; i++)
	{
		for(v=0; v<k; v++)
		{
			F[i][v] =0;	
		}	
	}
	fclose(f);
}

void BangPhuongAn()
{
	// Dong 1
	int v, i;
	for(v=0; v<k; v++)
	{
		if(A[1]%k == v)
			F[1][v] = 1;
		else 
 			F[1][v] = 0;	
	}
	
	for(i=2; i<=n; i++)
	{
		for(v=0; v<k; v++)
		{
			r = A[i]%k;
			F[i][v] = F[i-1][v];
			if(v==r && F[i][v] < (F[i-1][0] +1))
				F[i][v] = F[i-1][0] + 1;
			else if(F[i-1][((v-r+k)%k)] > 0 && F[i][v] < (F[i-1][((v-r+k)%k)] +1))
				F[i][v] = F[i-1][(v-r+k)%k] + 1;				
		}	
	}	
}

void TimNghiem()
{
	// bat dau tu o F[n][0]
	int i=n, v=0;
	int r;
	printf("\nDay dc chon:\n ");
	while(i>=0 && v >=0)
	{
		r = A[i]%k;
		if(F[i][v] == F[i-1][0] + 1 || F[i][v] == F[i-1][(v-r+k)%k] + 1)
		{
			printf("%d\t",A[i]);			
			v = (v-r+k)%k;	
		}	
		i--;
	}
}

int main()
{
	nhap();
	BangPhuongAn();
	TimNghiem();
	getch();
	return 0;	
}
