#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
BaiToanBaLo
Tim do vat
Phuong phap quay lui
*/

/*Doc du lieu tu file Balo.txt
Dong thu nhat ghi so do vat (n) va trong luong toi da cua ba lo (m)
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
    FILE *f;
    f = fopen("BaLo.txt", "r");
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
      printf("So do vat da cho la: ");
      printf("%2d",n); 
      printf("\n"); 
      printf("Tong trong luong cho phep cua tui : ");
      printf("%2d",W);
      printf("\n"); 
}

void LuuPa(int i)
{
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

void Quaylui(int i)
{
    for(int j=0; j<n; j++)
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
                Quaylui(i+1);
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
    Quaylui(0);
    printf("phuong an chon la:");
    InPa();
    getch();
}
