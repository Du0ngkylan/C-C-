#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 100

/*Doc du lieu tu file balo.txt
Dong thu nhat ghi so do vat (n) va trong luong toi da cua ba lo (m)
n dong tiep theo ghi trong luong va gia tri cua vat
*/

int n, W, w[max], v[max], vmax, daqua[max],x[max], pa[max], vi, wi;

void DocDL()
{
    FILE *f;
    f = fopen("balo.txt", "r");
    if(!f)
    {
          puts("Loi mo tep");
    }
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &W);
    for(int j=0; j<n; j++)
    {
          fscanf(f, "%d", &w[j]);
          fscanf(f, "%d", &v[j]);
    }
}

void LuuPa(int i)
{
//intf("%d\n", i);
    for(int j=0; j<=i; j++)
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
    for(int j=0; j<n; j++)
          if(!daqua[j] && (wi+w[j])<=W)
          {
                x[i] = j+1;
                daqua[j] = 1;
                vi += v[j];
                wi += w[j];
                if(vi>vmax)
                {
                       vmax = vi;
                       LuuPa(i);
                }
                Try(i+1);
                //x[i] = 0;
                daqua[j] = 0;
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
