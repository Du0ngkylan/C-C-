// Bai toan nguoi ban hang
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int n,A,x[30],a[30][30],flag[30],T=0,BestCost=100000,d=0;

void input()
{
     int i,j,t;
     FILE *f;
     f=fopen("nguoibanhang.txt","r");
     fscanf(f,"%d",&n);
     for(i=1;i<=n;i++)
         for(j=1;j<=n;j++)
         {
             fscanf(f,"%d",&t);
             a[i][j]=t;
             flag[j]=0;             
         }
     fclose(f);                       
}
void write()
{
     int i;
     FILE *f2;
     f2=fopen("nguoibanhang.out","w");
     for(i=1;i<=n;i++)
     {
                      fprintf(f2,"%d",x[i]);
     }
     fprintf(f2,"\n");
     fclose(f2);
}
void try1(int i,int S)
{
     int j;
     for(j=1;j<=n;j++)
     {
        if(flag[j]==0 && a[i-1][j]!=10000)  //neu tp nay chua di qua va co duong di.
        {
            T= S + a[i-1][j];               //cong them chi phi khi di qua tp nay
            if(T<BestCost)                  //neu nho hon chi phi min
            {
                x[i]=j;
                flag[j]=1;
                if(x[i]==A && i==n+1 )      //khi da quay tro ve thanh pho ban dau.
                       {
                           write();
                           d=1;
                       }
                else
                       try1(i+1,T);
                flag[j]=0;
            }
        }
     }         
}
int main()
{
    input();
    printf("Nhap dinh bat dau: ");
    scanf("%d",&A);
    try1(A,0);
    if(d==1)
    printf("\nKet qua da duoc ghi ra tep nguoibanhang.out!");
    else
    printf("\nKo the di qua tat ca cac thanh pho tu dinh nay!.");
    getch();
    return 0;
}
