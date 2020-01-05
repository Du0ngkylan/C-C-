#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int n, m, dd[50], Cuoi[50], w[50], v[50];
int max = 0, T;

void DocDL()
{
    FILE *f;
    f = fopen("Balo.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
        exit(0);
    }
    
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &T);
    
    for(int i=1; i<=n; i++)
    {
        fscanf(f, "%d", &w[i]);
        fscanf(f, "%d", &v[i]);
    }
    fclose(f);
}

int vetcan(int index, int tong ,int  Moi)
{
    dd[index] = 1;
    //danh dau vat da duoc chon
    tong = tong + w[index];
    Moi = Moi + v[index];
    // Tinh lai tong va gia tri moi
    for (int i = 1;i <= n;i ++)
    {
       if(dd[i] == 0)
       {
         if ((tong + w[i]) <= T)
         {
            vetcan(i,tong,Moi);         
         }         
       }     
    }
    if (Moi> max)
    {
       max = Moi;
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
       printf("\nmax : %d\n",max);            
    }
    
    dd[index] = 0;
    
}

int main()
{
    DocDL();
    vetcan(0,0,0);
    printf("Tong Max : %d.\n",max);
    for (int i = 1;i <=n ;i++)
    {
       if (Cuoi[i] == 1)
       printf("%d   %d\n",i,v[i]);    
    }
    getch(); 
}
