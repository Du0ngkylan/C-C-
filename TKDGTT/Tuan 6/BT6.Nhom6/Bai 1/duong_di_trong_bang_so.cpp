#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define hs 20
int a[hs][hs],L[hs][hs],v[hs][hs],m,n ;

char fi[]="Tay_Dong.txt" ;
char fo[]="Tay_Dong.txt" ;

void Input()
{
    int tg =0 ;
    FILE *f = fopen(fi,"r");
    if(!f)
    {
          printf("\n\n Can't Open File ");
          getch();
          exit(0);
    }
    fscanf(f,"%d%d",&m,&n);
    for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++)
        {
              fscanf(f,"%d",&tg);
              a[i][j] = tg;
        }
    fclose(f);
    printf("\n\nma tran da cho la \n");
    for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++)
        {
              if(j==1) puts("\n");
              printf("%4d",a[i][j]);
        }
}
void inkq()
{
    printf("\n\n ma tran phuong an  L[][] la  : \n");
    for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++)
        {
              if(j==1) puts("\n");
              printf("%4d",L[i][j]);
        }
}

int init()
{
    for(int j=0;j<=n;j++)  // co so QHD
        L[0][j] = 0 ;
    for(int i = 0 ; i <= m ; i++)
        L[i][0] = 0;
}
int max(int a,int b,int c)
{
    int Max = 0;
    if(a>b )
    {
          Max = a;
    }
    else {
              Max = b;
        }
    if(Max < c )
    {
          Max = c;
    }
   
    return Max;

}

void QHD()
{
    int i,j ;
    for( j = 1 ; j <= n; j++)
        for(i = 1 ; i <= m ; i++) 
              L[i][j] = max(L[i-1][j-1], L[i][j-1], L[i+1][j-1]) +  a[i][j];
       
}
void output()
{
    int k,i,j;
    i = m;
    j = n;
    printf("\n\n Hanh trinh MAX tim dc la  : Tong MAX = %d\n\n ",L[i][j]);
    while(j>0)
      {
            printf("(%d,%d)  ",i,j);
            if(i > 1)
            {
                 if(j > 1)
                 {
                    k = L[i][j] - a[i][j];
                    if(L[i - 1][j - 1] == k)
                    {
                        i -- ; 
                        j--;
                    }
                    else
                        if(L[i][j - 1] == k) j--;
                        else i--;
                 }
                 else i--;
            }
            else j--;
            
      }
}
int main()
{
    Input();
    init();
    QHD();
    inkq();
    output();
    getch();
}
