/*Bai toan nguoi du lich thuc chat la bai toan tim duong di ngan nhat 
di qua moi dinh cua do thi(co trong so) :do thi vo huong*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 9999

int M[50][50], n, m, Daqua[50], xp, kq[50], chiphi, temp[50], cmin=9999;
//daqua[]: mang danh dau cac dinh da di qua
//kq[]:doung di tot nhat hien thoi
//temp[]duong di hien thoi
//M[][] ma tran ke
//n: so dinh m: so cung

/*khoi tao tat ca cac dinh chua duoc di qua*/
void khoitao()
{
	int i, j;
	for(i = 1; i <= n;i++)
	{
		Daqua[i] = 0;	
		kq[i]=0;
		temp[i]=0;
	}	
	for(i = 1;i <= n; i++)
	{
		for(j = 1;j <= n; j++)
		{
			M[i][j] = MAX;
		}
	}
	chiphi = MAX;
}

/*Doc ma tran ke*/
void nhap()
{
	int i, j, s, k;
	FILE *f;
	f = fopen("dt_trongso.dat", "r");	
	if(!f)
	{
		puts("Loi mo tep!");
		getch();
		exit(0);	
	}	
	fscanf(f, "%d%d", &n, &m);
	
	khoitao();	
	for(k = 1;k <= m; k++)
	{
		fscanf(f, "%d%d%d", &i, &j, &s);	
		M[i][j] = s;
		M[j][i] = s;	
	}
	fclose(f);
}

void tim()
{
	int i, j;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j<= n; j++)
		{
			if(M[i][j] < cmin) cmin = M[i][j];		
		}
	}	
}

void inkq()
{
	int l = 2;
	printf("\n%4d->", xp);
	for(l=2; l <=n; l++) 	
		printf("%4d->",kq[l]);
	printf("%4d", xp);		
}

void Try(int i, int C)//tim dinh thu i cua duong di voi chi phi hien tai la C
{
    int v, j, C1;
    for(v = 1; v <= n; v++)//duyet tat ca cac dinh
    {
        if(Daqua[v] == 0)//neu dinh do chua di qua
        {                     
            if(M[temp[i-1]][v] < MAX)
            {
                C1 = C + M[temp[i-1]][v];//tinh thu chi phi neu chon v
                if(C1 + (n-i+1)*cmin < chiphi)
                {
                    temp[i] = v;
                    Daqua[v] = 1;
                    if(i == n)
                        Daqua[xp] = 0;
                    if(temp[i] == xp)
                    {
                        chiphi = C1;
                        for(j = 1; j <= n; j++)
                        {
                            kq[j] = temp[j];
                        }
                        kq[n+1] = xp;
                    }
                    else
                        Try(i+1,C1);
                    Daqua[v] = 0;
                    Daqua[xp] = 1;
                }
            }
        }
    }
}

/*Chuong trinh chinh*/
int main()
{	
	nhap();	
	tim();
	printf("Dinh dau: ");
	scanf("%d", &xp);
	Daqua[xp] = 1;
	temp[1] = xp;
	Try(2,0);	
	inkq();
	printf("\nChi phi: %d\n", chiphi);
	getch();
	return 0;	
}
