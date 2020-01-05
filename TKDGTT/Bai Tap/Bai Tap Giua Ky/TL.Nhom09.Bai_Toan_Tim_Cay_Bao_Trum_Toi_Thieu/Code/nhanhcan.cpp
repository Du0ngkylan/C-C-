#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct canh
{
	int dau, cuoi;
	int trs;
}canh;

int m, n, *ddc, *dd, *v;
canh *tapcanh;//chua tat ca cac canh cua do thi
// khoi tao
void khoitao()
{
	int i;
	tapcanh=(canh*)malloc((m+1)*sizeof(canh));
	ddc=(int*)malloc((m+1)*sizeof(int));
	for(i=1; i<=m; i++)
	{
		ddc[i]=0;
	}
	dd=(int*)malloc((n+1)*sizeof(int));
	for(i=1; i<=n; i++)
	{
		dd[i]=0;
	}
	v=(int*)malloc((n+1)*sizeof(int));
	for(i=1; i<=n; i++)
		v[i]=0xFFFF;
}
//doc du lieu cua do thi tu tap
void readfile()
{
	int i;
	FILE *f;
	f=fopen("CBTNN.INP", "r");
	if(!f)
	{
		puts("Loi mo tep");
		getch();
		exit(1);
	}
	fscanf(f, "%d %d\n", &n, &m);
	khoitao();
	for(i=1; i<=m; i++)
	{
		fscanf(f, "%d %d %d\n", &tapcanh[i].dau, &tapcanh[i].cuoi, &tapcanh[i].trs);
	}
	printf("%d %d\n", n, m);
	for(i=1; i<=m; i++)
	{
		printf("%d %d %d\n", tapcanh[i].dau, tapcanh[i].cuoi, tapcanh[i].trs);
	}
	fclose(f);
}
//in ra cac canh thuoc cay bao trum va chi phi cua no
void print(int k)
{
	int i;
	printf("In ra la \n\n");
	for(i=1; i<=m; i++)
	{
		if(ddc[i]==1)
		{
			printf("%d %d %d\n", tapcanh[i].dau, tapcanh[i].cuoi, tapcanh[i].trs);
		}
	}
	printf("\nGia tri trong so nho nhat hien tai la %d\n", v[k]);
}
//kiem tra xem tat ca cac dinh da co trong cay bao trum chua
int kt()
{
	int i;
	for(i=1; i<=n; i++)
	{
		if(dd[i]==0)
			return 0;
	}
	return 1;
}
//tim cay bao trum nho nhat bang phuong phap nhanh can
void Try(int k)
{
	int i, dh=0;
	for(i=1; i<=m; i++)
	{
		if(ddc[i]==0)
		{
			if(dd[tapcanh[i].dau]+dd[tapcanh[i].cuoi]==1)
			{
				if(dd[tapcanh[i].dau]>dd[tapcanh[i].cuoi])
				{
					dh=1;
				}
				if(v[k]>v[k-1]+tapcanh[i].trs)
				{	
					v[k]=v[k-1]+tapcanh[i].trs;
					dd[tapcanh[i].dau]=1;
					dd[tapcanh[i].cuoi]=1;
					ddc[i]=1;
					if(kt())
					{
						print(k);
					}
					else
						Try(k+1);
					ddc[i]=0;
					if(dh==1)
					{
						dd[tapcanh[i].cuoi]=0;
					}	
					else
						dd[tapcanh[i].dau]=1;
				}
			}
		}
	}
}
//ham main
int main()
{
	readfile();
	v[0]=0;
	dd[tapcanh[1].dau]=1;
	Try(1);
	getch();
	return 0;
}
