#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct canh 
{
	int dau;
	int cuoi;
	int trs;
}canh;
int m, n, *dd, *ddc, len;
canh *tapcanh;
void khoitao()
{
	int i;
	tapcanh = (canh *)malloc((m+1)*sizeof(canh));
	dd = (int*)malloc((n+1)*sizeof(int));
	ddc = (int*)malloc((m+1)*sizeof(int));
	for(i=1; i<=n; i++)
		dd[i]=0;
	for(i=1; i<=m; i++)
		ddc[i]=0;
	len = m;
}
void swap(int i, int j)
{
	canh temp;
	temp = tapcanh[i];
	tapcanh[i] = tapcanh[j];
	tapcanh[j] = temp;
}
void upheap(int k)
{
	while(k>1)
	{
		if(tapcanh[k].trs > tapcanh[k/2].trs)
		{
			swap(k, k/2);
			k=k/2;
		}
		else
			break;
	}
}
void downheap(int k, int l)
 {
	int i;
	while(2*k<l)
	{
		i=2*k;
		if(tapcanh[i].trs < tapcanh[i+1].trs)
		{
			i=i+1;
		}
		if(tapcanh[k].trs < tapcanh[i].trs)
		{
				swap(k, i);
		}
		k=i;
	}
}

void sapxep()
{
	while(len>=2)
	{
		swap(1, len);
		len--;
		downheap(1, len);
	}	
}			

void readfile()
{
	FILE *f; 
	int i;
	f=fopen("CBTNN.TXT", "r");
	if(!f)
	{
		puts("Loi mo tep");
		getch();
		exit(1);
	}
	fscanf(f, "%d %d\n", &n, &m);
	printf("%d %d\n", n, m);
	khoitao();
	for(i=1; i<=m; i++)
	{
		fscanf(f, "%d %d %d\n", &tapcanh[i].dau, &tapcanh[i].cuoi, &tapcanh[i].trs);
		upheap(i);
	}
	sapxep();                                                                                            //(*)
	printf("\nDu lieu sap xep la\n");
	for(i=1; i<=m; i++)
		printf("%d %d %d\n", tapcanh[i].dau, tapcanh[i].cuoi, tapcanh[i].trs);
	fclose(f);
}

void print()
{
	int i;
	printf("\nDanh sach cac cung nam trong cay kruskal\n");
	for(i=1; i<=m; i++)
	{
		if(ddc[i]==1)
		{
			printf("%d %d %d\n", tapcanh[i].dau, tapcanh[i].cuoi, tapcanh[i].trs);
		}
	}
}

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

void kruskal()
{
	int i, d=1, count=0, j;
	ddc[1]=1;
	dd[tapcanh[1].dau]=d;
	dd[tapcanh[1].cuoi]=d;
	count =1;
	for(i=2; i<=m; i++)  
	{
		if(ddc[i]==0)
		{
			if(dd[tapcanh[i].dau]==0&&dd[tapcanh[i].cuoi]==0)
			{
				dd[tapcanh[i].dau] =d+1;
				dd[tapcanh[i].cuoi] =d+1;
				d++;
				ddc[i]=1;
			}
			else if(dd[tapcanh[i].dau]!=0&&dd[tapcanh[i].cuoi]==0)
			{
				dd[tapcanh[i].cuoi] = dd[tapcanh[i].dau];
				ddc[i]=1;
			}
			else if(dd[tapcanh[i].dau]==0&&dd[tapcanh[i].cuoi]!=0)
			{
				dd[tapcanh[i].dau] = dd[tapcanh[i].cuoi];
				ddc[i]=1;
			}
			else if(dd[tapcanh[i].dau]!=0&&dd[tapcanh[i].cuoi]!=0&&dd[tapcanh[i].dau]!=dd[tapcanh[i].cuoi])
			
			{
				for(j=1; j<=m; j++)
				{
					if(dd[tapcanh[j].dau]==dd[tapcanh[i].cuoi]&&j!=i)
					{
						dd[tapcanh[j].dau]=dd[tapcanh[i].dau];
					}
					if(dd[tapcanh[j].cuoi]==dd[tapcanh[i].cuoi]&&j!=i)
					{
						dd[tapcanh[j].cuoi]=dd[tapcanh[i].dau];
					}
				}
				dd[tapcanh[i].cuoi]= dd[tapcanh[i].dau];
				ddc[i]=1;
			}
			count++;
		}
		if(kt())
		{
			print();
			return;
		}
	}
	printf("Do thi khong co chu trinh");
}

int main()
{
	
	readfile();
	kruskal();
	getch();
	return 0;
}
	
