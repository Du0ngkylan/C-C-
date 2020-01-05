#include<stdio.h>
#include<conio.h>
int a[100][100],free[100],x[100],n,xp,kt;  
void printfresult(int dem)
{
     int i;
     
     for(i=1;i<=dem;i++)
     {
     	printf(" %d ",x[i]);
     }
     printf("\n");
}
void khoitao()
{
     int i;
     for(i=1;i<=n;i++)
     {
        free[i]=1;
     }
}
void dfs(int k,int dem)
{
     int v;
     for(v=1;v<=n;v++)
     {
        if(a[x[k-1]][v]&&free[v])
        {
            dem = dem +1;
            x[k] = v;
            free[v] = 0;
            if(x[k] == kt)
            {
                printfresult(dem);
                free[v] = 1;
				dem = dem - 1;
			    return;
             }
                dfs(k+1,dem);
                free[v] = 1;
                dem = dem - 1;
              
                                                   
        }
     }
}
main()
{
      FILE *f;
      int i,j;
      if((f=fopen("matran.txt","r"))==NULL)
      {
          printf("khongn tim thay file ");
      }
      else
      {
          fscanf(f,"%d%d%d",&n,&xp,&kt);
          for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
          {
             fscanf(f,"%d",&a[i][j]);
          }
          khoitao();
          x[1]=xp;
          free[xp]=0;
          dfs(2,1);
      }
      getch();
}
