#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#define INPUT_FILE "XepBaLo.txt"

int maxTemp = 0;
int n, w, dd[50], p[100], v[100],Cuoi[100] ;

void docDuLieu()
{
	FILE *file;
	file = fopen(INPUT_FILE, "r");
	if(file != NULL)
	{
		fscanf(file, "%d", &n);
		for(int i=1; i<=n; i++)
		{
			fscanf(file, "%d %d", &p[i], &v[i]);
		}
		fscanf(file, "%d", &w);
    }
	else
	{
		puts("Khong tim thay file!");
		getch();
		exit(0);
	}
}

void inDuLieu()
{
	for(int i=1; i<=n; i++)
	{
		printf("Vat thu %d: (%d, %d)\n", i, p[i], v[i]);
	}
	printf("Gioi han cua ba lo: %d\n\n", w);
}

int select(int index, int tong ,int  giaTriMoi)
{
    dd[index] = 1;
    //danh dau vat da duoc chon
    tong = tong + p[index];
    giaTriMoi = giaTriMoi + v[index];
    // Tinh lai tong va gia tri moi
    for (int i = 1;i <= n;i ++)
    {
       if(dd[i] == 0)
       {
         if ((tong + p[i]) <= w)
         {
            select(i,tong,giaTriMoi);         
         }         
       }     
    }
    if (giaTriMoi> maxTemp)
    {
       maxTemp = giaTriMoi;
       for (int i = 1;i <=n ;i ++)
       Cuoi[i] = 0;
       
       for (int i = 1; i <= n ;i ++)
       {
           if (dd[i] == 1)
           {
              Cuoi[i] = dd[i];       
           }
       }             
    }
    dd[index] = 0;
}

int main()
{
	docDuLieu();
	inDuLieu();
	select(0,0,0);
	printf("Tong Max : %d.\n",maxTemp);
    for (int i = 1;i <=n ;i++)
    {
       if (Cuoi[i] == 1)
       printf("%d   (%d  %d )\n",i,p[i],v[i]);    
    }
	puts("Hoan thanh!");
	getch();
	return 0;
}
