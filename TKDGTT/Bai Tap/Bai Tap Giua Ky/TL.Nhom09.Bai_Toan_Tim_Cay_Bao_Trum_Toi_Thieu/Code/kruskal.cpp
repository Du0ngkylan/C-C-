//viet chuong trinh tim cay bao trum nho nhat bang thuat toan kruskal
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct canh // cau truc du lieu cho mot canh
{
	int dau;
	int cuoi;
	int trs;
}canh;
int m, n, *dd, *ddc, len;
//mang dd de danh dau cac canh
//mang ddc de danh dau cac canh
canh *tapcanh;
//khoi tao bo nho cho tap canh
//==========================================================
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
//doi cho 2 canh trong tap canh
//============================================================
void swap(int i, int j)
{
	canh temp;
	temp = tapcanh[i];
	tapcanh[i] = tapcanh[j];
	tapcanh[j] = temp;
}
//dua tap canh ve dang heap bang ham up heap
//===========================================================
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
//thu tuc downheap de sap xep lai heap
//===========================================================
void downheap(int k, int l)
 {
	int i;
	while(2*k<l)//phai nho hon do dai vi neu la 2*k<=l thi co the phan tu cuoi duoc sap xep roi nhung van bi doi cho
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
//thuc hien sap xep tap canh theo thu tu tang dan cua trong so
//================================================================
void sapxep()
{
	while(len>=2)
	{
		swap(1, len);
		len--;
		downheap(1, len);
	}	
}			
//doc tep lay du lieu cac canh
//====================================================================
void readfile()
{
	FILE *f; 
	int i;
	f=fopen("CBTNN.INP", "r");
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
	printf("\nDu lieu doc duoc da sap xep la\n");
	for(i=1; i<=m; i++)
		printf("%d %d %d\n", tapcanh[i].dau, tapcanh[i].cuoi, tapcanh[i].trs);
	fclose(f);
}
//in ra cac canh nam trong cay bao trum nho nhat
//=================================================
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
//kiem tra cac dinh da duoc danh dau vao trong cay bao trum chua
//=======================================================================
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
//thuat toan kruskal tim cay bao trum nho nhat
//=================================================================
void kruskal()
{
	int i, d=1, count=0, j;
	ddc[1]=1;//tap canh duoc sap xep chon cay dau tien
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
				//neu hai dinh cua canh duoc chon thuoc 2 cay khac nhau 
			//thi dua 2 cay do hop thanh 1 cay
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
		if(kt())//kiem tra co tim duoc cay bao trum hay ko
		{
			print();//in ra cac canh thuoc cay bao trum
			return;
		}
	}
	printf("Do thi khong co chu trinh");
}
//ham main
//=======================================================================
int main()
{
	
	readfile();
	kruskal();
	getch();
	return 0;
}
	