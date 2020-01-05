#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int n, m, dd[50], Cuoi[50], w[50], v[50];
int maxTemp = 0, W;
/*
Bo gia tri test: 
BAG.INP	
5 11


3 3
4 4
5 4
9 10
4 4

BAG.OUT
11
5 2 1
*/

void DocDL()
{
    FILE *f;
    f = fopen("BaLo.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
        exit(0);
    }
    
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &W);
    
    for(int i=1; i<=n; i++)
    {
        fscanf(f, "%d", &w[i]);
        fscanf(f, "%d", &v[i]);
    }
    fclose(f);
}

int select(int index, int tong ,int  giaTriMoi)
{
    dd[index] = 1;
    //danh dau vat da duoc chon
    tong = tong + w[index];
    giaTriMoi = giaTriMoi + v[index];
    // Tinh lai tong va gia tri moi
    for (int i = 1;i <= n;i ++)
    {
       if(dd[i] == 0)
       {
         if ((tong + w[i]) <= W)
         {
            select(i,tong,giaTriMoi);         
         }         
       }     
    }
    if (giaTriMoi> maxTemp)
    {
       maxTemp = giaTriMoi;
       for (int i = 1;i <=n ;i ++)
       Cuoi[i] = 0;
       
       for (int i = 1; i <= n ;i ++)
       {
           if (dd[i] == 1)
           {
              Cuoi[i] = dd[i];
              printf("%d  ",i);        
           }
       }   
       printf("\nmaxTemp : %d\n",maxTemp);            
    }
    
    dd[index] = 0;
    
}

int main()
{
    DocDL();
    select(0,0,0);
    printf("Tong Max : %d.\n",maxTemp);
    for (int i = 1;i <=n ;i++)
    {
       if (Cuoi[i] == 1)
       printf("%d   %d\n",i,v[i]);    
    }
    getch(); 
}
