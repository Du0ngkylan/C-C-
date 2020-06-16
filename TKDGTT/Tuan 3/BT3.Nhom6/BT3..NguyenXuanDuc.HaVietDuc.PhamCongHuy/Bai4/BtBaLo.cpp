#include<stdio.h>
#include<conio.h>
#include<math.h>

int n, m, dd[50], Cuoi[50], can[50], giatri[50];
int maxTemp = 0, MAX;
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
void khoiTao()
{
     int  i;
     printf("Nhap vao so vat : ");
     scanf("%d",&n);
     printf("Nhap vao gioi han ba lo : ");
     scanf("%d",&MAX);
     printf("Nhap vao can nang cua tung vat : ");
     for (i = 1; i<= n ;i ++)
     {
       printf("a[%d]: ",i);
       scanf("%d",&can[i]);    
     } 
     
     printf("Nhap vao gia tri cho tung vat : ");
     for (i = 1;i <= n; i++)
     {
        printf("gt[%d]: ",i);
        scanf("%d",&giatri[i]);    
     }
     
     for(i = 1;i <= n;i ++)
     {
       Cuoi[i] = 0;    
       dd[i] = 0;
     }
}

int select(int index, int tong ,int  giaTriMoi)
{
    dd[index] = 1;
    //danh dau vat da duoc chon
    tong = tong + can[index];
    giaTriMoi = giaTriMoi + giatri[index];
    // Tinh lai tong va gia tri moi
    for (int i = 1;i <= n;i ++)
    {
       if(dd[i] == 0)
       {
         if ((tong + can[i]) <= MAX)
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
    khoiTao();
    select(0,0,0);
    printf("Tong Max : %d.\n",maxTemp);
    for (int i = 1;i <=n ;i++)
    {
       if (Cuoi[i] == 1)
       printf("%d   %d\n",i,giatri[i]);    
    }
    getch(); 
}
