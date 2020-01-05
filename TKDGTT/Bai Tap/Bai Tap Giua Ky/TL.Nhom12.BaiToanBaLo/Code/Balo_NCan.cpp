#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*
BaiToanBaLo
Phuong phap nhanh can
*/

/*Doc du lieu tu file Balo.txt
Dong thu nhat ghi so do vat (n) va trong luong toi da cua ba lo (m)
n dong tiep theo ghi trong luong va gia tri cua vat
*/

#define max 100

int v[max], w[max];
int daxet[max];
int vi, wi, vmax;
int n, W;
int x[max];
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

void LuuPa(int i)
{
    for(int j=1; j<=i; j++)
    pa[j] = x[j];
}

void InPa()
{
    int i = 1;
    while(pa[i])
    {
        printf("%3d", pa[i]);
        i++;
    }
}

void Try(int i)
{
    for(int j=1; j<= n; j++)
    {
        int v1, w1;
        v1 = vi + v[j];
        w1 = wi + w[j];
        
        if(w1<=W)
        {
            x[i] = j;
            vi = v1;
            wi = w1;
            if(vi>vmax)
            {
                vmax = vi;
                LuuPa(i);
            }
            Try(i+1);
            vi -= v[j];
            wi -= w[j];
        }
    }
}

int main()
{
    DocDL();
    vi = 0;
    wi = 0;
    vmax = 0;
    Try(1);
    InPa();
    getch();
}
