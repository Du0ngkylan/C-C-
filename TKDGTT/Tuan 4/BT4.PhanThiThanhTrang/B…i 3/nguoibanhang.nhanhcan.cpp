#include<stdio.h>
#include<conio.h>
#define max 100



int a[max][max], x[max], w[max], Tmin, danhdau[max];
int n;

void doctep()
{
	FILE *f;
	f=fopen("NguoiBanHang.txt", "r");	
	if(f == NULL)
		printf("Loi Mo Tep !");
	fscanf(f, "%d", &n);
	int i, j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			fscanf(f,"%d",&a[i][j]);
	fclose(f);
}

void in()
{
	printf("n = %d", n);	
	int i,j;
	printf("\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%5d", a[i][j]);		
		printf("\n");
	}
}

void capnhat()
{
	int i;
	for(i=0; i<n; i++)	
		w[i] = x[i];
}

void Try(int i, int s)
{
	int j;
	int T;
	
	for(j=0; j<n; j++)	
	{
		if(danhdau[j] == 0)
		{
			T = T + 
		}
	}
}
int main()
{
	doctep();
	in();
	getch();
	return 0;	
}
