#include "conio.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define SIZE 100
class CBanCo
{
private:
int n;
int a[SIZE][SIZE];

public:
void Nhap();
void Xuat();
void KhoiTao();
int DemODiQuan(int d, int c);
void DatNgua(int d, int c, int ThuTu);
int ThuatGiaiAKT();
};

void CBanCo::Nhap()
{
printf("Nhap n:");
scanf("%d",&n);
}

void CBanCo::Xuat()
{
for(int i=0; i<n; i++)
{
for(int j=0; j<n; j++)
printf("%5d",a[i][j]);
printf("\n");
}
}

void CBanCo::KhoiTao()
{
for(int i=0; i<n; i++)
for(int j=0; j<n; j++)
a[i][j]=0;
}

void CBanCo::DatNgua(int d, int c, int ThuTu)
{
a[d][c]=ThuTu;
}

int CBanCo::DemODiQuan(int d, int c)
{
int di[8]={-2,-1,+1,+2,+2,+1,-1,-2};
int dj[8]={+1,+2,+2,+1,-1,-2,-2,-1};
int dem=0;
for(int k=0; k<8; k++)
if(d+di[k]>=0 && d+dj[k]<n &&
  c+di[k]>=0 && c+dj[k]<n &&
  a[d+di[k]][c+dj[k]] ==0)
dem++;
return dem;
}


int CBanCo::ThuatGiaiAKT()
{
int di[8]={-2,-1,+1,+2,+2,+1,-1,-2};
int dj[8]={+1,+2,+2,+1,-1,-2,-2,-1};
KhoiTao();
int d=0;
int c=0;
int ddau,cdau;
do{
printf("Nhap vao vi tri dong: ");scanf("%d",&ddau);
printf("Nhap vao vi tri cot : ");scanf("%d",&cdau);
}while((ddau<0||ddau>n-1)||(cdau<0 || cdau>n-1));
DatNgua(ddau,cdau,1);
for (int thutu=2; thutu<=n*n; thutu++)
{
int lc=9;
int vtd=-1,vtc=-1;
for(int k=0; k<8; k++)
if( d+di[k]>=0 && d+di[k]<n &&
c+dj[k]>=0 && c+dj[k]<n &&
a[d+di[k]][c+dj[k]]==0 )
{
int dem=DemODiQuan(d+di[k],c+dj[k]);
if(dem==lc)
{
if(rand()%2==0)
{
lc=dem;
vtd=d+di[k];
vtc=c+dj[k];
}
}
if(dem<lc)
{

lc=dem;
vtd=d+di[k];
vtc=c+dj[k];
}
}
if(vtd==-1)
{
printf("Khong co loi giai\n");
return 0;
}
DatNgua(vtd,vtc,thutu);
d=vtd;
c=vtc;
}
return 1;
}

int main( )
{
CBanCo a;
a.Nhap();
srand((unsigned)time(NULL));
do{

}while(a.ThuatGiaiAKT()==0);
a.Xuat();
return 1;
}
