#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define hs 100
int m,n,w[hs][hs],v[hs],xp,dich,tr[hs];
int max=1121990000;
void thongbao(char *s)
{
	puts(s);
	getch();
	exit(0);
}
void init(){
	for (int i=1;i<=n;i++)
	int i,j;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	         w[i][j]=max;
}
void nhap()
{
	int i,j,k,tg;
	FILE *f;
	f=fopen("dothi1.txt","r");
	if(!f)   thongbao("loi mo tep");
	fscanf(f,"%d%d",&n,&m);
	init();
	for(k=1;k<=m;k++)
	{
		fscanf(f,"%d%d%d",&i,&j,&tg);
		w[i][j]=tg;
	}
	fclose(f);
}
void in() 
{
     int x;
     x=tr[dich];
     printf("%d ->",dich);
     while (x!=xp)
	{
           printf("%d ->",x);
           x=tr[x];
    }
    printf("%d",xp);
           
}
void tim()
{
	int i,j,tiep;
	for(i=1;i<=n;i++)   v[i]=max;
	v[xp]=0;
	tiep=1;
	tr[xp]=-1;
	while(tiep)
	{
		tiep=0;
		for(i=1;i<=n;i++)
		  { 
			if(v[i]<max)
				for(j=1;j<=n;j++)
		        	if( v[i]+w[i][j]<v[j])
		        	{
				        v[j]=v[i]+w[i][j]; 
				        tiep=1;
			        	tr[j]=i;
		         	}
		}
		
	}
	if(v[dich]<max) 
	{
		printf("\n do dai duong di ngan nhat tu %d den %d la:%d\n",xp,dich,v[dich]-1);
		in();
		
	}
	else printf("\nkhong co duong di tu %d den %d",xp,dich);
}
int main()
{
	nhap();
	xp=1;
	dich=8;
	tim();
	getch();
}
