#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 50
#define TRUE 1
#define FALSE 0
int n,s,t;
int truoc[MAX];//luu cac dinh truoc tai thoi diem dang xet cua dinh
int d[MAX];//luu do dai duong di tu dinh bat dau den cac dinh con lai
int DT[MAX][MAX];//do thi
int cuoi[MAX];
char chon;

void nhap()
{
int i,j;
printf("So dinh cua do thi: ");
scanf("%d",&n);
printf("\n Ma tran khoang cach");
for (i=1;i<=n;i++)
{
printf("\n");
for(j=1;j<=n;j++)
{
scanf("%d",&DT[i][j]);
}
}
}

void xuly()
{
int v,u,minp;
printf("\n Tim duong di tu dinh s= ");
scanf("%d",&s);
printf(" den dinh: ");
scanf("%d",&t);



for(v=1;v<=n;v++)
{
d[v]=DT[s][v];
truoc[v]=s;
cuoi[v]=FALSE;
}
truoc[s]=0;
d[s]=0;
cuoi[s]=TRUE;
while(!cuoi[t])
{
minp=1000;//khoi tao do dai tu dinh dang xet den cac dinh con la 999( xap xi vo cung)
for(v=1;v<=n;v++)
{
if((!cuoi[v])&&(minp>d[v]))//neu dodai[v] nho hon min
{ 
u=v;
minp=d[v];//min bang do dai cua dodai[i]
}
}
cuoi[u]=TRUE;
if(!cuoi[t])
{
for(v=1;v<=n;v++)
{
if((!cuoi[v])&&(d[u]+DT[u][v]<d[v]))
{
d[v]=d[u]+DT[u][v];
}
}
}
}

}
main()
{
int i,j;
nhap();
xuly();

printf("\nDuong di ngan nhat tu %d den %d la\n",s,t);
printf("%d <=",i);
i=truoc[i];
while(i!=s)
{
printf("%d <= ",i);
i=truoc[i];
}
printf("%d",s);
printf("\nDo dai duong di la: %d", d[t]);



getch();
}
