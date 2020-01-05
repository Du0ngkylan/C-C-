/*
  Name:Tim cay bao trum be nhat
  Copyright: 
  Author: Nhom 1
  Date: 16/04/12 23:42
  Description: Su dung phuong phap tham lam
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define hs 100
int n,m,dd[hs],v[hs];
typedef struct 
{
   int dau,cuoi,w;
}cung;
cung cg[hs];

void nhap()
{
         FILE *f;
         int k;
         cung t;
         char s[200];
         f=fopen("caybaotrum.txt","r");
         if(!f)
         {
             puts("\nLoi mo tep");
             getch();
             exit(0);
         }
         fscanf(f,"%d%d",&n,&m);
         for(k=1;k<=m;k++)
         {
             fscanf(f,"%d%d%d",&cg[k].dau,&cg[k].cuoi,&cg[k].w);
             fgets(s,100,f);
         }
}

main()
{
    	int h,k,tiep,i,c=2,s=0;
    	cung t;
    	nhap();
    	printf("\nDo thi co dang sau:  ");
    	printf("\nSo dinh=  %d So cung = %d",n,m);
    	printf("\nDanh sach cung cung voi trong so la: \n");
    	for(h=1;h<=m;h++)
    	{
    		v[h]=0;
    		printf("%d-->%d co trong so =  %d\n",cg[h].dau,cg[h].cuoi,cg[h].w);
    	}
    	for(i=1;i<=n;i++)
    	dd[i]=0;
    	for(h=1;h<=m-1;h++)
        {
           for(k=h+1;k<=m;k++)
           {
              if(cg[h].w>cg[k].w)
              {
                 t=cg[k];
                 cg[k]=cg[h];
                 cg[h]=t;
              }
           }
        }
        printf("\nDanh sach cung cung voi trong so sau khi sap xep la: \n");
    	for(h=1;h<=m;h++)
    	{
    		printf("%d-->%d co trong so =  %d\n",cg[h].dau,cg[h].cuoi,cg[h].w);
    	}
       	v[1]=1;
    	dd[cg[1].dau]=1;dd[cg[1].cuoi]=1;
    	tiep=1;
    	while(tiep)
    	{
    		tiep=0;
    		for(h=1;h<=m;h++)
    			if(v[h]==0)
    				if((dd[cg[h].dau] + dd[cg[h].cuoi])==1)
    				{
    					v[h]=1;
    					dd[cg[h].dau]=1;
    					dd[cg[h].cuoi]=1;
    					tiep=1;
    					c++;
    					break;
    				}
    	}
        if(c!=n)
        {
           puts("\nKhong co cay bao trum be nhat");
        }
        else
        {
            puts("\nCay bao trum be nhat la: ");
              for(h=1;h<=m;h++)
               if(v[h]==1)
               {
    	            printf("%d--->%d  with weight %d\n",cg[h].dau,cg[h].cuoi,cg[h].w);
    	            s+=cg[h].w;
               }
            printf("\nTong do dai khung la: %d",s);
        }
    	getch();
}
