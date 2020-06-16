//tim chu trinh haminton;
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#define hs 100
int m,n,v[hs],dau[hs],dd[hs],cuoi[hs];
//nhap do thi
void nhap()
{
	int i;
	FILE *f;
	f=fopen("dothi.dat","r");
	char s[200];
	if(!f)
	{
		printf("loi mo tep");	getch();	exit(0);
	}
	fscanf(f,"%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		fscanf(f,"%d%d",&dau[i],&cuoi[i]);
		fgets(s,200,f);
	}
	fclose(f);
}
//ham kiem tra cung
int cung(int x,int y)
{
	int i;
	for(i=1;i<=m;i++)
		if(dau[i]==x&&cuoi[i]==y)
			return 1;
	return 0;
}
//danh dau cac phan tu chua duoc xet
void khoidau()
{
	int i;
	for(i=1;i<=n;i++)
		dd[i]=0;
}
//inmang
void inmang(int a[],int k)
{
	int i;
	for(i=1;i<k;i++)
	{
		printf("%d-->",a[i]);
	}
	printf("%d",a[k]);
}
//ham tim chu trinh
void tim(int k)
{
	int i;
	if(k>n)	return;//dung tim theo nhanh do//khi nao thi dong nay co tac dung
	if(k==n&&cung(v[k],v[1]))
	{
		printf("chu trinh Haminton la:\n");
		inmang(v,n);	getch();	exit(0);
	}
	for(i=1;i<=n;i++)
		if(dd[i]==0&&cung(v[k],i))
		{
			v[k+1]=i;           
			dd[i]=1;
			tim(k+1);
			dd[i]=0;
		}
}
int main()
{
	nhap();
	khoidau();
	v[1]=1;
	dd[1]=1;
	tim(1);
	printf("do thi khong co chu trinh Haminton");
	getch();
}
