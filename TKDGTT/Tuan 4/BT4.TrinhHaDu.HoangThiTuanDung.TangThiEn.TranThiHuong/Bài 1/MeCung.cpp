#include<stdio.h>
#include<conio.h>
int a[100][100],dd[100],x[100],n,xp,kt;  

void induong(int dem)
{
	int i;
	for(i=1;i<=dem;i++)
	{
		printf(" %d ",x[i]);
	}
	printf("\n");
}

void khoitao()
{
	int i;
	for(i=1;i<=n;i++)
	{
		dd[i]=1;// tat ca cac dinh chua duoc di qua
	}
}
// ham tim duong di trong me cung
// bien dem dung de dem cac duong co the di trong me cung 

void Try(int i,int dem)
{
	int v;
	for(v=1;v<=n;v++)
	{
		if(a[x[i-1]][v] && dd[v])
        {
			dem = dem +1;
			x[i] = v;
			dd[v] = 0;
			if(x[i] == kt)
			{
				induong(dem);
				dd[v] = 1;
				dem = dem - 1;
				return;
            }
            Try(i+1,dem);
            dd[v] = 1;
            dem = dem - 1;
        }
	}
}

int main()
{
	FILE *f;
	int i,j;
	if((f=fopen("input.txt","r"))==NULL)
	{
		printf("khongn tim thay file o vi tri file ");
	}
	else
	{
		fscanf(f,"%d%d%d",&n,&xp,&kt);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				fscanf(f,"%d",&a[i][j]);
   			}
		}
		khoitao();
		x[1]=xp;
		dd[xp]=0;
		Try(2,1);
	}
	getch();
	return 0;
}
