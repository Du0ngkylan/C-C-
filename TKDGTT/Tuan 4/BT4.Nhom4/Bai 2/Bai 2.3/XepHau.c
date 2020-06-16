// Bai toan xep quan co
//Thuat toan quay lui
#include<stdio.h>
#include<conio.h>

int n, pa[50], soDuongCheo, cot[50], cheonguoc[50], cheoxuoi[50], soDapAn=0;

void khoitao();
void inda();
void Try(int i);

void khoitao()
{
	int k=1;
	soDuongCheo = 2*n - 1;
	// ban dau cac cot, cac duong cheo xuoi, cheo nguoc deu con trong
	for(k = 1;k <= n; k++) cot[k] = 1;
	for(k = 1; k <= soDuongCheo; k++)
	{
		cheonguoc[k] = 1;
		cheoxuoi[k] = 1;	
	}
}
void Try(int i)
{
	int j=1;
	// duyet cac cot
	for(j=1;j<=n;j++)
	{
		if(cot[j] && cheoxuoi[j-i+n] && cheonguoc[i+j-1]) // cot j duoc chap nhan
		{
			pa[i] = j; // dat quan hau i o cot j
			// danh dau cot, duong cheo xuoi, duong cheo nguoc di qua no khong con trong
			cot[j] = 0;
			cheoxuoi[j-i+n] = 0;
			cheonguoc[i+j-1] = 0;
			if(i == n)
				inda();
			else
			{
				Try(i+1);	
			}	
			cot[j] = 1;
			cheoxuoi[j-i+n] = 1;
			cheonguoc[i+j-1] = 1;
		}	
	}	

}
void inda()
{
	int k=1;
	soDapAn++;
	printf("Phuong an thu: %d\n",soDapAn);
	for(k=1; k <=n; k++)
	{
		printf("%d\t",pa[k]);
	}
	printf("\n");
		
}

int main()
{
	n = 8;
	printf("Voi ban co %d * %d cac canh xep quan hau la: \n\n", n, n);
	khoitao();
	Try(1);
	getch();
	return 0;	
}
