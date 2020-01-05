//den truong
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define unlimited 10000
int **a, **b, *dd, *dd1, *dd2, n, m, k, *v, *vbo, *vxe, Bestcost = unlimited, Bestcost1 = unlimited;
//mang a[][] de thoi gian cho qua trinh di xe
//mang b[][] de luu thoi gian cho qua trinh di bo
//mang dd, dd1, dd2 la cac mang danh dau cho cac nut giao thong tuong duong voi cac dinh trong do thi
//n la so nut giao thong
//k la nut giao thong truong hoc
//m la so cac duong dinh tren cac nut giao thong
//v la luu cac dinh thuoc qua trinh di
//vbo la luu cac dinh trong qua trinh tim duong di bo
//vxe la luu cac dinh trong qua trinh tim duong di cua xe
//Bestcost. Bestcost1 la phuong an tot nhat hien tai tim duoc
//khoi tao cho bai toan
void khoitao()
{
	int i, j;
	a=(int**)malloc((n+1)*sizeof (int*));
	for(i=1; i<=n; i++)
	{
		a[i]=(int *)malloc((n+1)*sizeof(int));
	}
	b=(int**)malloc((n+1)*sizeof (int*));
	for(i=1; i<=n; i++)
	{
		b[i]=(int *)malloc((n+1)*sizeof(int));
	}
	dd=(int*)malloc((n+1)*sizeof(int));
	dd1=(int*)malloc((n+1)*sizeof(int));
	dd2=(int*)malloc((n+1)*sizeof(int));
	v=(int*)malloc((n+1)*sizeof(int));
	vbo=(int*)malloc((n+1)*sizeof(int));
	vxe=(int*)malloc((n+1)*sizeof(int));
	for(i=1; i<=n; i++)
	{
		dd[i]=0;
		dd1[i]=0;
		dd2[i]=0;
		
	}
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			a[i][j]=Bestcost;
			b[i][j]=Bestcost;
		}
	}
}
//doc du lieu tu file
void readfile()
{
	FILE *f;
	int i, j, t, dixe, dibo;
	f=fopen("school.inp", "r");
	if(!f)
	{
		puts("Loi mo tep");
		getch();
		exit(1);
	}
	fscanf(f, "%d %d %d\n", &n, &m, &k);
	khoitao();
	for(t=1; t<=m; t++)
	{
		fscanf(f, "%d %d", &i, &j);
		fscanf(f, "%d %d\n", &b[i][j], &a[i][j]);
	}
	fclose (f);
}
// viet ra thoi gian ngan nhat me den co quan lam viec
void writefile(int C2)
{
	FILE *f;
	f=fopen("school.out", "w");
	if(!f)
	{
		puts("Loi mo tep");
		getch();
		exit(1);
	}
	fprintf(f, "%d", C2);
	fclose(f);
}
//tim xem co duong di bo nho hon 59 phut khong neu so thi return true
int timduongdibo(int h, int BO)
{
	int i, C1;
	for(i=1; i<=n; i++)
	{
		if(dd1[i]==0)
		{
			C1= BO + b[vbo[h]][i];
			if(C1<=59)
			{
				vbo[h+1]= i;
				dd1[i]=1;
				if(vbo[h+1]==k)
				{
					return 1;
				}
				else
				{
					return timduongdibo(h+1, C1);
				}
				dd1[i]=0;
			}
		}
	}
	return 0;
}
//tim thoi gian ngan nhat de me co the den co quan
void timduongdixe(int h, int XE)
{
	int i, C2;
	for(i=1; i<=n; i++)
	{
		if(dd2[i]==0)
		{
			C2 = XE + a[vxe[h]][i];
			if(C2 < Bestcost1)
			{
				vxe[h+1]=i;
				dd2[i]=1;
				if(vxe[h+1]==n)
				{
					writefile(C2);
					Bestcost1 = C2;
				}
				else
					timduongdixe(h+1, XE);
				dd2[i]=0;
			}
		}
	}
}	
//tim cach di de me va Tuan deu di duoc den truong thoa man yeu c bai toan
void timcachdi(int h, int XE, int BO, int t)
{
	int i, C1, C2;
	if(t==1 && timduongdibo(1, 0))
	{
		timduongdixe(1, 0);
	}
	else
	{
		for(i=1; i<=n; i++)
		{
			if(dd[i]==0)
			{
				C1= XE + a[h][i]; //qua trinh ma Tuan di cung xe voi me
				C2= BO + a[h][i];
			
				if(C1 < Bestcost && C2<=59)
				{
					v[h+1]=i;
					vbo[h+1]=i;
					vxe[h+1]=i;
					dd[i]=1;
					dd1[i]=1;
					dd2[i]=1;//sau moi lan tim duoc nut giao thong thoa man Tuan di cung voi me
					if(timduongdibo(h+1, C2))//kiem tra xem tuan co di bo duoc den truong khong
					{
						timduongdixe(h+1, C1);//neu co thi tim duong di ngan nhat cho me den co quan
					}
					else
						timcachdi(h+1, C1, C2, 2);
						dd[i]=0;
						dd2[i]=0;
						dd1[i]=0;
				}
			}
		}
	}
}				
int main()
{
	readfile();
	v[1] = 1;
	dd[1]=1;
	dd1[1]=1;
	dd2[1]=1;
	timcachdi(1, 0, 0, 1);
	printf("Mo tep school.out de xem ket qua ");
	getch();
}
