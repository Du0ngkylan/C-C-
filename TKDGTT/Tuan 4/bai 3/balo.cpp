#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
BaiToanBaLo
*/

/*
Dong thu nhat ghi so do vat (n) va trong luong toi da cua ba lo (M)
n dong tiep theo ghi trong luong va gia tri cua vat
*/

#define max 100

int n, W;
int w[max], v[max], vmax;
int daxet[max];
int x[max];
int pa[max];
int vi, wi;

void DocDL()
{
     int j;
    FILE *f;
    f = fopen("balo.txt", "r");
    if(!f)
    {
          puts("Loi mo tep");
    }
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &W);
    for( j=0; j<n; j++)
    {
          fscanf(f, "%d", &w[j]);
          fscanf(f, "%d", &v[j]);
    }
}

void LuuPa(int i)
{
     int j;
    for( j=0; j<=i; j++)
        pa[j] = x[j];
}

void InPa()
{
    int i = 0;
    while(pa[i])
    {
        printf("%3d", pa[i]);
        i++;
    }
}

void Try(int i)
{
     int j;
     for( j=0; j<n; j++)
          if(!daxet[j] && (wi+w[j])<=W)
          {
                x[i] = j+1;
                daxet[j] = 1;
                vi += v[j];
                wi += w[j];
                if(vi>vmax)
                {
                       vmax = vi;
                       LuuPa(i);
                }
                Try(i+1);
                //x[i] = 0;
                daxet[j] = 0;
                wi -= w[j];
                vi -= v[j];
          }
}

int main()
{
    DocDL();
    wi = 0;
    vmax = 0;
    vi = 0;
    Try(0);
    InPa();
    getch();
}
