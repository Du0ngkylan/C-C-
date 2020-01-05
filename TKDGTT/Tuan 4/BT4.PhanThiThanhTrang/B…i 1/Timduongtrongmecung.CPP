#include<stdlib.h>
#include<stdio.h>

#define inp "inp.txt"
#define out "out.txt"
int inx,iny,outx,outy;
int x[2500],y[2500],a[50][50],c[50][50],
	dx[5]={0,0,1,0,-1},
	dy[5]={0,-1,0,1,0};
int m,n,i,j,d,s;
FILE *f;

void nhap()
{
 f=fopen(inp,"r");
 fscanf(f,"%d %d",&m,&n);
 fscanf(f,"%d %d %d %d",&inx,&iny,&outx,&outy);
 for (i=0;i<m;++i)
  for (j=0;j<n;++j) fscanf(f,"%d",&a[i][j]);
 fclose(f);
}

int  ok(int i,int j)
{
 if ((i<0)||(i>=m)||(j<0)||(j>=n)) return 0;
 if ((a[i][j]!=0)||(c[i][j]!=0))   return 0;
 return 1;
}

void dfs(int i,int j)
{
 if ((i==outx-1)&&(j==outy-1)) d=1;
 else
  {
   int k;
   for (k=1;k<=4;++k)
   if (ok(i+dx[k],j+dy[k]))
	{
	 c[i+dx[k]][j+dy[k]]=k;
	 dfs(i+dx[k],j+dy[k]);
	}
  }
}

void chuanbi()
{
 for (i=0;i<m;++i)
  for (j=0;j<n;++j) c[i][j]=0;
 c[0][0]=-1;
 d=0;
}

void tim()
{
 s=0;
 x[0]=outx-1;
 y[0]=outy-1;
 i=outx-1;
 j=outy-1;
 int k;
 while (c[i][j]!=-1)
  {
   k=c[i][j];
   i=i-dx[k];
   j=j-dy[k];
   s++;
   x[s]=i;
   y[s]=j;
  }
}

void xuly()
{
 chuanbi();
 dfs(inx-1,iny-1);
 if (d==1) tim();
}

void xuat()
{
 FILE *f;
 f=fopen(out,"w");
 if (d != 1)fprintf(f,"Noresult");
 if (d==1)
 {
 /*for (i=0;i<m;++i)
  {
   for (j=0;j<n;++j)
	if (c[i][j]!=0) fprintf(f,"1 ");else fprintf(f,"0 ");
   fprintf(f,"\n");
  }*/
 fprintf(f,"%d\n",s);
 for (i=s;i>=0;i--) fprintf(f,"%4d%4d\n",x[i],y[i]);
// for (i=s;i>=0;i--) fprintf(f,"%d\n",y[i]);
 }
 fclose(f);
}

int  main()
{
 nhap();
 xuly();
 xuat();
 return 0;
}