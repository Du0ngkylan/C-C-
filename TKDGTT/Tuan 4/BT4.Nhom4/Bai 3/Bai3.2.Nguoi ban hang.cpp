#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100

int n, matran[max][max], daxet[max], pa[max], chiphi;

void nhap()
{
     FILE *f;
     f = fopen("nguoibanhang.txt", "r");
     if(!f)
     {
           puts("Loi mo tep");
           getch();
           exit(0);
     }
     fscanf(f, "%d", &n);
     int i, j;
     for(i=1; i<=n; i++)
     	for(j=1; j<=n; j++)
     		fscanf(f, "%d", &matran[i][j]);
     fclose(f);
}

void in()
{
     int j;
     for(j=1; j<=n; j++)
     printf("%d -> ", pa[j]);
     printf("%d - %d", pa[n+1], chiphi);
}

void Try(int i, int c)
{
     int j;
     int c1;
     for(j=2; j<=n; j++)
     {
        if(!daxet[j] && matran[pa[i-1]][j])
		{
        	c1 = c + matran[pa[i-1]][j];
        	if(c1<chiphi)
        	{
            	pa[i] = j;
            	daxet[j] = 1;
            	c = c1;
        		if(i==n)
				{
            		if(matran[pa[n]][1] && (c+ matran[pa[n]][1]) < chiphi)
                	{
                    	pa[n+1] = 1;
                    	chiphi = c+ matran[pa[n]][1];
                	}
            }
            else
                Try(i+1, c);
            daxet[j] = 0;
        	}
     	}
     }
}


int main()
{
    nhap();
    pa[1] = 1;
    daxet[1] = 1;
    chiphi = 1000;
    Try(2, 0);
    in();
    getch();
    exit(0);
}
