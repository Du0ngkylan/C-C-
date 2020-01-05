
#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#define hs 100
int m,n,w[hs][hs],v[hs],xp,dich,tr[hs];
int max=9999999999;
// ham khoi tao 
void khoidau()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			w[i][j]=max;      
}
// Ham nhap 
void nhap()
{
	int i,j,k,l;
	char s[200];
	FILE *f;
	f=fopen("roadmin.txt","r");
	if(!f)
	{
		printf("loi mo tep");	
        getch();	
        exit(0);
	}
	fscanf(f,"%d%d",&n,&m);
	khoidau();
	for(k=1;k<=m;k++)
	{
		fscanf(f,"%d%d%d",&i,&j,&l);
		w[i][j]=l;
		fgets(s,100,f);
	}
	fclose(f);
}
// ham in duong di 
void inmang(int a[],int n)
{
    int i;
	for(i=n;i>1;i--)
		printf(" %d-->",a[i]);
		printf(" %d\t",a[1]);
}
// ham tim duong di ngan nhat bang thuat toan dijstra
void tim()
{
	int i,j,tiep;
	int mang[hs];
	for(i=1;i<=n;i++)
		v[i]=max;
	v[xp]=0;
	tiep=1;
	while(tiep)
	{
		tiep=0;
		for(i=1;i<=n;i++)
			if(v[i]<max)
				for(j=1;j<=n;j++)
					if((w[i][j]<max)&&(v[i]+w[i][j]<v[j]))
					{
						v[j]=v[i]+w[i][j];                
                        tr[j]=i;	
                        tiep=1;	
					}
	}
	if(v[dich]<max)
	{
		printf("\n Duong di ngan nhat tu %d toi %d la: \n",xp,dich);	
		int k=1,x=dich;	mang[k]=dich;	
		while(x!=xp)
		{
			k++;	
            mang[k]=tr[x];		
            x=tr[x];
		}
		inmang(mang,k);
		getch();	
		exit(0);
	}
	printf("khong co duong di tu %d toi %d",xp,dich);
}
// ham chinh 
int main()
{
	nhap();
	printf("\n nhap dinh xuat phat la =  ");		
    scanf("%d",&xp);
	printf(" \n nhap dinh dich la =  ");	    
    scanf("%d",&dich);
	tim();
	getch();
}

