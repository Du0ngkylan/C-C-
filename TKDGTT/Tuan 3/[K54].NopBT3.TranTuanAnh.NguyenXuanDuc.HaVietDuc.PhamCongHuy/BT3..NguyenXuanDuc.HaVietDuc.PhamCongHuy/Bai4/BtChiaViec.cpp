#include<stdio.h>
#include<conio.h>
#include<math.h>

int maxTong  = 0;
int n, A[50], dd[50], cv[50][50], Cuoi[50];
/*
    Mau test:
    2 3 4 7
    3 9 2 1
    4 5 6 2
    4 3 1 4
    
    Output : 
    7 9 6 4
    Tong : 26
*/

void khoiTao()
{
    int i, j;
    for (i=1;i<=n;i++)
    {
       dd[i] = 0;
       A[i] = 0;    
    }
    printf("Nhap vao so nguoi : ");
    scanf("%d",&n);
    printf("Nhap vao nang suat cua moi nguoi:\n ");
    //cv[i][j] la nguoi thu i voi nang suat cong viec j
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
           printf("cv[%d][%d]:",i,j);
           scanf("%d",&cv[i][j]);  
        }   
        printf("\n");     
    }

}

void select(int per, int wor, int tong)
{
     int i;
     //Danh dau nguoi per da lam cong viec wor .
     A[per] = wor;
     // Danh dau cong viec wor da co nguoi nhan.
     dd[wor] = 1;
     //Tinh tong nang suat hien tai khi them nguoi per voi cong viec wor
     tong = tong + cv[per][wor];
     
     if (per == n)
     {
       //Truong hop da duyet toi nguoi cuoi cung
         if (tong > maxTong)
         {
           maxTong = tong;
           for (i=1;i<=n;i++)
           Cuoi[i] = 0;         
           
           for (i=1;i<=n;i++)
           {
               Cuoi[i] = A[i];
           }
         }        
     }
     else
     {
       //Neu chua duyet het 
       for (i = 1;i <= n;i ++)
       {
         if(dd[i] == 0)
         {
            select(per+1,i,tong);         
         }    
       }
     }
     dd[wor] = 0;
     //Bo danh dau
}


int main()
{
    khoiTao();
    select(0,0,0);
    int i;
    
    printf("Danh sach nguoi va cong viec tuong ung : \n");
    for (i=1;i<=n;i++)
    {
       printf("%d : %d.\n",i,Cuoi[i]);    
    }
    printf("Tong nang suat : %d.\n",maxTong);
    getch();
}
