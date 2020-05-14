/*
  Name:  Bai Toan Doi Tien
  Description: 
            Trong ngan hang co n loai tien menh gia A1...An
        	Doi m don vi tien sao cho so to tien la it nhat
  Author: Nhom 12
  Date: 23/04/12 22:24
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 555

int n, m , a[50], b[50], max[50], kq[50], x[50], c[50][50];

void DocDL()
{
    FILE *f;
    f = fopen("DoiTien.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
        exit(0);
    }
    
    fscanf(f, "%d %d", &n, &m);
    
    for(int i=1; i<=n; i++)
    {
        fscanf(f, "%d", &a[i]);
    }
    fclose(f);
}

void InDL()
{
    int i;
    printf("\n----------------------------------------\n");
    printf("\n--------------BAI TOAN DOI TIEN---------\n");
    printf("Menh gia tien phai doi :%d.\n",n);
    printf("So loai tien : %d.\n",m);
    for (int i = 1;i <= n;i ++)
    {
       printf("%d)    %d\n",i,a[i]);    
    }     
    printf("\n----------------------------------------\n");
    printf("\n\n");
}

void InBangQHD()
{
    int i;
    printf("\n------------------------------------------------------------------------------\n");
    printf("\n-------------------------------BANG QUY HOACH DONG----------------------------\n");

   	for(int i=0; i<=n; i++)
    {
       for(int j=0; j<=m; j++)
       {
          printf("%d     ",c[i][j]);    
       }
       printf("\n");
    }     
    printf("\n------------------------------------------------------------------------------\n");    
}

void KhoiTao()
{
   	for(int i=0; i<=m; i++)
   	c[0][i] = MAX;
	for (int j = 0;j <= n; j ++)
    c[j][0] = 0;
}

void LapBangQHD()
{
    // Khoi Tao Gia Tri Ban Dau Cho Bang
    KhoiTao();
    /*
      Qua trinh thuc hien lap bang quy hoach dong.
    */    
   	for(int i=1; i<=n; i++)
    {
       for(int j=1; j<=m; j++)
       {
         c[i][j] = c[i-1][j];
         if (j - a[i] >= 0)
         {
           if (c[i][j-a[i]] + 1 < c[i-1][j])
           {
              c[i][j] = c[i][j-a[i]] + 1;                
           }      
         }
       }
    }  
    InBangQHD();
}

/*
     Truy Vet Va in Ra Ket Qua
*/
void TruyVetVaIn()
{
   if (c[n][m] > 0)
   {
      printf("\n----------------------------------------\n");
      printf("\n--------------BAI TOAN DOI TIEN---------\n");
      int i=n, j=m, count=0;
      while (j > 0)
      {
         if (c[i][j] == c[i-1][j])
         {
             if (count > 0)
             {
                printf("Dung %d to co menh gia %d.\n",count,a[i]);          
             }            
             count = 0;
             i --;
         }      
         else 
         {
            j = j - a[i];
            count ++;     
         }
      }
      if (count > 0)
       printf("Dung %d to co menh gia %d.\n",count,a[i]); 
       printf("\n----------------------------------------\n");
   }
   else
   {
     printf("Khong tim ra phuong an doi tien.\n");    
   }     
}

int main()
{
    DocDL();
    InDL();
    LapBangQHD();
    TruyVetVaIn();
    getch();
}
