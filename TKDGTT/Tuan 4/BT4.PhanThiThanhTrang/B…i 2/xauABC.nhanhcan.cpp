#include<conio.h>
#include<stdio.h>
#define max 100

// HTML (*_*) Kute....

int x[max], w[max], Tmin, n;

void nhap()
{
	printf("\nChieu dai cua day n = ");	
	scanf("%d", &n);
}

int giongnhau(int i, int l)
{
	int j;
	for(j=0; j< l; j++)	
		if(x[i-j] != x[i-j-l])
			return 1;
	return 0;
}

int ktra(int i)
{
	int l;
	for(l=1 ; l<= (i+1)/2; l++)	
		if(giongnhau(i,l) == 0)
			return 0;
	return 1;
}

void capnhat()
{
	int i;
	for(i=0; i<n; i++)	
		w[i] = x[i];
}

void in()
{
	int i;
	for(i=0; i<n; i++)	
		printf("%c", w[i]);
}

void Try(int i, int s)
{
	int j, T;
	for(j = 'A'; j<= 'C'; j++)	
	{
		x[i] = j;
		if(ktra(i)== 1)	
		{
			if(j== 'C')
				T= s+1;
			else
				T= s;
			if(T+ (n-i)/4 < Tmin)	
			{
				if(i==n-1)
				{
					Tmin = T;
					capnhat();	
				}
				else
					Try(i+1,T);
			}
		}
	}
}

void xauABC()
{
	Tmin = n;
	x[0] = 'A';
	Try(1,0);	
}

int main()
{
	nhap();
	printf("\nXau ABC co la:");	
	xauABC();
	in();
	getch();
	return 0;
}
