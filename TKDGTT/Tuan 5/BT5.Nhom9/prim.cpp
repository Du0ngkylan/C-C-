//tim cay bao trum toi thieu bang thuat toan prim
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct canh
{
	int dau;
	int cuoi;
	int trs;
}canh;
int m, n, *dd, *ddc, len;
canh *tapcanh;
//khoi tao cho tap canh, mang dd, ddc
//=================================================
void khoitao()
{
	int i;
	len=m;
	tapcanh = (canh *)malloc((m+1)*sizeof(canh));
	dd = (int*)malloc((n+1)*sizeof(int));
	ddc = (int*)malloc((m+1)*sizeof(int));
	for(i=1; i<=n; i++)
		dd[i]=0;
	for(i=1; i<=m; i++)
		ddc[i]=0;
}
//doi cho 2 canh cua tap canh
//===============================================================
void swap(int i, int j)
{
	canh temp;
	temp = tapcanh[i];
	tapcanh[i] = tapcanh[j];
	tapcanh[j] = temp;
}
//ham upheap de tao heap khi doc tung canh tu tep 
//========================================================
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
//su dung downheap khi sap xep tap canh
//================================================================
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
//sap xep tap canh theo chieu tang cua trong so su dung heap
//==================================================================
void sapxep()
{
	int i;
	while(len>=2)
	{
		swap(1, len);
		len--;
		downheap(1, len);
	}	
}
//doc file lay du lieu
//=========================================================================================
void readfile()
{
	FILE *f; 
	int i, j, h, k, ts;
	f=fopen("dothi.inp", "r");
	if(!f)
	{
		puts("Loi mo tep");
		getch();
		exit(1);
	}
	fscanf(f, "%d %d\n", &n, &m);
	khoitao();
	printf("\nSau sap xep la\n");
	printf("%d %d\n", n, m);
	for(i=1; i<=m; i++)
	{
		fscanf(f, "%d %d %d\n", &tapcanh[i].dau, &tapcanh[i].cuoi, &tapcanh[i].trs);
		upheap(i);
	}
	sapxep();
	for(i=1; i<=m; i++)
		printf("%d %d %d\n", tapcanh[i].dau, tapcanh[i].cuoi, tapcanh[i].trs);
	fclose(f);
}
//in ra cac canh nam trong cay bao trum nho nhat
//=============================================================================
void print()
{
	int i;
	for(i=1; i<=n; i++)//kiem tra xem co cay bao trum ko
	{
		if(dd[i]==0)
		{
			printf("Do thi khong co chu trinh");
			return;
		}
	}
	printf("Danh sach cac cung nam trong cay prim\n");//in ta tap cac canh thuoc cay bao trum
	for(i=1; i<=m; i++)
	{
		if(ddc[i]==1)
		{
			printf("%d %d %d\n", tapcanh[i].dau, tapcanh[i].cuoi, tapcanh[i].trs);
		}
	}
}
//thuat toan prim tim cay bao trum nho nhat
//========================================================================
void prim()
{
	int i, j, tiep=1;
	dd[tapcanh[1].dau]=1;
	while(tiep)
	{
		tiep=0;
		for(i=1; i<=m; i++)
		{
			if(ddc[i]==0)
			{
				if(dd[tapcanh[i].dau] + dd[tapcanh[i].cuoi]==1)//kiem tra 2 dinh cua mot canh chua duoc chon co dinh nao da thuoc cay bao trum chua
				{
					dd[tapcanh[i].dau]=1; //dua dinh con lai vao cay bao trum
					dd[tapcanh[i].cuoi]=1;//dua dinh con lai vao cay bao trum
					ddc[i]=1;
					tiep=1;
					break;
				}
			}
		}
	}
}
//ham main
//================================================
int main()
{
	readfile();
	prim();
	print();
	getch();
}
