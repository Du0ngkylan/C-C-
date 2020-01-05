/*ho va ten: Bui Thi Thanh Huong*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int m, n, a[100][100], c[100][100];

void doctep()
{
    int i, j, k;
    FILE *f;
    f = fopen("duong_di_trong_bang_so.txt", "r");
    
    if(f != NULL)
    {
        fscanf(f, "%d %d", &m, &n);    
        for(i=1; i<=m; i++)
            for(j=1; j<=n; j++)
            {
                fscanf(f, "%d", &k);
                a[i][j] = k;
            }                            
    }
    else
    {
        puts("Khong tim thay file!");    
        getch();
        exit(0);
    }
}

void in()
{
    int i, j;
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
            printf("%5d ", a[i][j]);    
        puts("");            
    }
}

int max(int a, int b, int c)
{
    int max = a;
    if(max<b)    
        max=b;
    if(max<c)
        max=c;
    return max;        
}

void BangPhuongAn()
{
    int i, j;
    /*Co so quy hoach dong*/
    for(i=0; i<=m ;i++)
        c[i][0] = 0;
    for(j=0; j<=n; j++)
        c[0][j] = 0;
      
    /*Dung bang phuong an*/
    for(i=1; i<=m; i++)        
        for(j=1; j<=n; j++)
        {
            c[i][j] = max(c[i-1][j-1], c[i][j-1], c[i+1][j-1])+a[i][j];
        }
}

void Tr()
{
    /*Tim ket qua toi uu*/
    printf("tong gia tri cac o tren duong di: %d\n", c[m][n]);
    
    /*Truy vet*/
    int i=m, j=n;
    while(j>0)
    {
        printf("(%d,%d)", i, j);
        if(j>1)
            printf(" <-- ");
        if(i>0)
        {
            int t=c[i][j]-a[i][j];
            if(c[i-1][j-1]==t)
            {
                i--;
                j--;    
            } 
            else if(c[i][j-1]==t)
                j--;
            else
                i--;
         }
         else
            j--;    
    }
    puts("");
}

int main()
{
    doctep();
    in();
    BangPhuongAn();
    Tr();   
    getch();
    return 0;
}

