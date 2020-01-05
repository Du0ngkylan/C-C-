/*Bai toan vong tron so nguyen to*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define Nmax 10

int N, D[2*Nmax];//Mang danh dau xem chi so nao da dc chon.
int X[2*Nmax];//Phuong an thoa man.
int dem = 0;
FILE *fos;

void nhap()
{
	FILE *f;
    f = fopen("VONGSO.INP", "r");
    if(!f)
    {
		puts("Loi mo tep!");
		getch();
		exit(0);	
	}
    fscanf(f, "%d", &N);
    N=N*2;
    fclose (f);
}

int nguyento(int k)
{
     for(int i=2 ; i < k; i++)
     {
      	if(k%i == 0)	return 0;
     }
     return 1;
}

void Try(int i)
{
	int v, k;
	for(v = 1; v < N; v++)
	{
		if(D[v] == 0 && nguyento(X[i-1] + v +1))//D[v]==0 chua dc chon.
		{
			X[i] = v+1;
			D[v] = 1;
			if(i == N-1)
			{
				if(nguyento (X[N-1] + X[0]))
				{
					for(k = 0; k < N; k++)
					{
						fprintf(fos, "%d ", X[k]);
					}	
					fprintf(fos, "\n");
					dem++;	
				}	
			}	
			else 
				Try(i+1);
			D[v]=0;
		}	
	}	
}

int main()
{
	int i;
	printf("\n\n__________Bai toan ^^VONG SO NGUYEN TO^^____________\n\n\n");
	nhap();
   	fos=fopen ("VONGSO.OUT", "w");
   	fprintf (fos, "%d ", N/2);
	fprintf (fos, "\n");
	for(i = 0; i < N; i++)
		D[i]=0;
	X[0]=1;
	D[0]=1;
	Try(1);
	fprintf(fos,"So phuong an cua bai toan la: %d", dem);
	fclose(fos);
	printf("-+-+-+-+-Da xuat ra file VONGSO.OUT(^_^)!-+-+-+-+-");
	getch();
}
