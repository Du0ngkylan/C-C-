#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 100
int m, n, a[max][max], c[max][max];

void nhap()
{
    FILE *f;
    f = fopen("duongdi.txt", "r");
    if(!f){
        printf("loi mo tep");    
        getch();
        exit(0);
    }
    else
    {
        fscanf(f, "%d %d", &m, &n);    
    for(int i=1; i<=m; i++)
      for(int j=1; j<=n; j++)
            {
                fscanf(f, "%d",&a[i][j]);
            }                            
    }
    
}

void in()
{
     int i,j;
     printf(" do thi duong di\n");
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
            printf("%d\t ",a[i][j]);  
            printf("\n");             
    }
}

int Max(int a, int b, int c)
{
 int t;
    t=a;
    if(t<b)    
        t=b;
    if(t<c)
        t=c;
return t;        
}

void quyhoach()
{
 int i,j;
    for( i=0; i<=m ;i++)
        c[i][0] = 0;
    for( j=0; j<=n; j++)
        c[0][j] = 0;
      
    for( i=1; i<=m; i++)        
        for( j=1; j<=n; j++){
            c[i][j] = Max(c[i-1][j-1], c[i][j-1], c[i+1][j-1])+a[i][j];
        }
}

void truyvet()
{
    int i=m, j=n,k;
    printf("\nTong do dai duong di: %d\n", c[m][n]);
    printf("duong di tu dich ve la:\n");
    while(j>0){
        printf("(%d, %d)\t", i, j);
        if(j>1)
        if(i>1)
        {
            k=c[i][j]-a[i][j];
            if(c[i-1][j-1]==k)
            {
                i--;
                j--;    
            }
             else 
                if(c[i][j-1]==k)
                                j--;
                else
                i--;
        }
         else i--;
         else
            j--;    
        }
        
}

int main()
{
    nhap();
    in();
    quyhoach();
    truyvet();   
    getch();
    return 0;
}

