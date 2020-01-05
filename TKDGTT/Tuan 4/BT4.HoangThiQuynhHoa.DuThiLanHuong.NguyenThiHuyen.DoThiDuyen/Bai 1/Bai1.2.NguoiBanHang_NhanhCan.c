// Bai 2: Bai Toan nguoi ban hang, phuong phap nhanh can
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int max = 9999;
int M[50][50], n, m, Daqua[50], xp, kq[50], chiphi, temp[50];
// mang M[][]: luu do thi co trong so
// temp[]: dung de luu phuong an tot truoc khi thay doi mang kq[] de tim phuong an tot hon
// neu ko co phuog an tot hon se tra lai mang temp (mang gia tri cua mang kq[] trc ) vao mang kq[]

void khoitao();
void nhap();
void inkq();
void Try(int i, int C);


void khoitao()
{
	int i, j;
	for(i = 1; i<=n; i++)
	{
		Daqua[i] = 0;	
	}	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			M[i][j] = max;
		//	printf("%d", M[i][j]);
		}
	}
	for(i = 1; i<=n; i++)
	{
		kq[i] = 0;
	}
	chiphi = max;
}

void nhap()
{
	int i, j, s,k;
	
	FILE *f;
	f = fopen("dt_trongso.dat","r");	
	if(!f)
	{
		puts("Loi mo tep");
		getch();
		exit(0);	
	}	
	fscanf(f,"%d%d",&n,&m);
	
	khoitao();	
	for(k=1;k<=m;k++)
	{
		fscanf(f,"%d%d%d",&i,&j,&s);
		
		M[i][j] = s;
		M[j][i] = s;	
	}
	fclose(f);
}


void inkq()
{
		int l = 2;
		printf("\n%4d->", xp);
		for(l=2; l <=n; l++) 	
			printf("%4d->",kq[l]);
		printf("%4d", xp);
		//printf("\nChi phi: %d", chiphi);
}


void Try(int i, int C)
{
	int v=1, C1;
	Daqua[xp] = 1;
	for(v=1; v<=n;v++)
	{
		int M1 = M[kq[i-1]][v];
		if(M[kq[i-1]][v] < 999 )
		{			
			C1 = C + M[kq[i-1]][v];		
			if(i==n+1 && M[kq[i-1]][xp] < max && C1 + M[kq[i-1]][xp] < chiphi)
			{
				Daqua[xp] = 0;
			}// xu ly de quay lai dc xp
			if(!Daqua[v])
			{					
				if(C1 < chiphi)
				{						
					kq[i] = v;							
					int l = kq[i];					
					//for(int q=1;q<=n;q++) printf("%d\n", kq[q]);
					Daqua[v] = 1;
					if(i == n+1 && M[kq[i-1]][xp] < max && C1 + M[kq[i-1]][xp] < chiphi)
					{					
						// trc khi thay doi mang kq[] luu lai vao temp[] 
						int h;
						for(h=1;h<=n+1;h++)
						{
							temp[h] = kq[h];
						}
						//inkq();						
						chiphi = C1;					
					}	
					else if(i <= n)
					{						
							Try(i+1,C1);
					}				
					Daqua[v] = 0;
				}
				// neu ko tim dc phuog an tot hon thi tra lai cho mang kq[] phuong an trc da tim dc
				else
				{
					int h;
					for(h=1;h<=n+1;h++)
					{							
						kq[h] = temp[h];
					}
				}
			}
			
		}	
	}	
}

int main()
{	
	nhap();	
	printf("Dinh dau: ");
	scanf("%d", &xp);	
	Daqua[xp] = 1;
	kq[xp] = 1;
	printf("Duong di co chi phi it nhat la:", xp);
	Try(2,0);	
	inkq();
	printf("\nChi phi: %d\n", chiphi);
	getch();
	return 0;	
}
