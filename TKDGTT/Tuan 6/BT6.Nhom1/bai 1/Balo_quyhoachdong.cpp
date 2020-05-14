#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Code by Laptrinh.vn

/*
BaiToanBaLo
Tim do vat
Phuong phap quy hoach dong
*/

/*Doc du lieu tu file Balo.txt
Dong thu nhat ghi so do vat (n) va trong luong toi da cua ba lo (m)
n dong tiep theo ghi trong luong va gia tri cua vat
*/

#define max 100

int v[max], w[max];
int n, W;
int L[max][max];
int vmax;
int pa[max];

void DocDL()
{
    FILE *f;
    f = fopen("BaLo.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
        exit(0);
    }
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &W);
    for(int i=1; i<=n; i++)
    {
        fscanf(f, "%d", &w[i]);
        fscanf(f, "%d", &v[i]);
    }
    fclose(f);
}

int Max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

void QHD()
{
    int i, j;
    for(i = 1; i<=n; i++)
        for(j=0; j<=W; j++)
            if(j>=w[i])
                L[i][j] = Max(v[i]+L[i-1][j-w[i]], L[i-1][j]);
}

void TruyVet()
{
    int i, j;
    i = n; j = W;
    int k;
    k = 1;
    vmax = 0;
    while(i && j)
    {
        if(L[i][j] == L[i-1][j])
            i--;
        if(L[i][j] == (v[i] + L[i-1][j-w[i]]) && (j>w[i]))
        {
            pa[k] = i;
            vmax += v[i];
            j -= w[i];
            k++;
            i--;
        }    
    }
}

void InPA()
{
    int i;
    i = 1;
    while(pa[i])
    {
        printf("%3d", pa[i]);
        i++;
    }
    printf("-%3d", vmax);
}

int main()
{
    DocDL();
    QHD();
    TruyVet();
    InPA();
    getch();
}
