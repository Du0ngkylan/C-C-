/*
Bai toan: Cho 2 day X (M phan tu) va Y (n phan tu)
            Tim day con chung dai nhat cua 2 day
*/
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

int n,m,C[100][100],X[100],Y[100];

void DocTep(){
    int i;
    FILE *f;
    f = fopen("DayConChungDaiNhat.txt","r");  
    if(!f)
    {
        puts("Loi mo tep!");    
        getch();
        exit(0);
    }
    else{ 
        fscanf(f,"%d", &m);
        for(i=1;i<=m;i++)
            fscanf(f,"%d",&X[i]);
        fscanf(f,"%d",&n);
        for(i=1;i<=n;i++)
            fscanf(f,"%d",&Y[i]);
    }
    fclose(f);       
}

void In()
{
    int i;
    printf("X= ");
    for(int i=1; i<=m;i++)
        printf("%d ",X[i]);
    printf("\nY= ");
    for(int i=1;i<=n; i++)
        printf("%d ",Y[i]);
    
}
void BangPhuongAn()
{
     int i,j;
     // co so QHD
     for(i=0;i<=m;i++)
        C[i][0]=0;
     for(j=0;j<=n;j++)
        C[0][j]=0;
    // dung Bang phuong an
     for(i=1;i<=m;i++)
     {
         for(j=1;j<=n;j++)
            if(X[i]==Y[j])
                C[i][j]=C[i-1][j-1]+1;
            else 
            {
                    C[i][j]=C[i-1][j];
                    if(C[i][j-1]>C[i-1][j])
                        C[i][j]=C[i][j-1];
            }
     }
}

void TruyVet()
{
    int i=m,j=n;
    printf("\n\nDo dai day con chung dai nhat la: %d \n",C[m][n]);
    if(C[m][n]>0)
    {
          printf("\nDay con chung dai nhat la:(truy vet) \n");
          while(i>0&&j>0)
          {
                if(X[i]==Y[j])
                {
                    printf("%d  ",X[i]);
                    i=i-1;j=j-1;
                }
                else 
                {
                    if(C[i-1][j]>C[i][j-1])
                        i=i-1;
                    else j=j-1;
                }
          }     
    }
    else 
            printf("\nHai day khong co day con chung !");
}
int main()
{
    DocTep();
    In();
    BangPhuongAn();
    TruyVet();
    getch();
    return 0;
}
