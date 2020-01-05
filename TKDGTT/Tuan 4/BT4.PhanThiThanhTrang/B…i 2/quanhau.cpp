#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



void InBanCo(int *a, int n)
{
    printf(" ");
    for(int i=0; i<n; i++)
            printf(" %d", i+1);
    for(int i=0; i<n; i++)
    {
            printf("\n%d", i+1);
            for(int j=0; j<n; j++)
            {
                    if(*(a+i)==j)
                           printf(" *");
                    else
                           printf(" -");
            }
           
    }
    puts("");
}

void XepHau(int *a, int i, int n, int *row, int *col, int *plus, int *minus)
{
    for(int j=0; j<n; j++)
            if(!*(row+i) && !*(col+j) && !*(plus+i+j-1) && !*(minus+i-j+n-1))
            {
                        *(a+i) = j;
                        *(col+j) = 1;
                        *(row+i) = 1;
                        *(plus+i+j-1) = 1;
                        *(minus+i-j+n-1) = 1;
                        if(i==n-1)
                               InBanCo(a, n);
                        else
                               XepHau(a, i+1, n, row, col, plus, minus);
                        *(col+j) = 0;
                        *(row+i) = 0;
                        *(plus+i+j-1) = 0;
                        *(minus+i-j+n-1) = 0;
            }
}

int main()
{
    int n, *a, *row, *col, *plus, *minus;
    printf("BAI TOAN XEP HAU\n\n");
    printf("Nhap n = ");
    scanf("%d", &n);
    printf("\nCac vi tri thoa man:\n");
    a = (int *)calloc(n, sizeof(int));
    row = (int *)calloc(n, sizeof(int));
    col = (int *)calloc(n, sizeof(int));
    plus = (int *)calloc(2*n, sizeof(int));
    minus = (int *)calloc(2*n, sizeof(int));
    
    for(int i=0; i<n; i++)
    {
            *(a+i) = 0;
            *(row+i) = 0;
            *(col+i) = 0;
    }
    for(int i=0; i<n*2; i++)
    {
            *(plus+i) = 0;
            *(minus+i) = 0;
    }

    XepHau(a, 0, n, row, col, plus, minus);
    getch();
}
