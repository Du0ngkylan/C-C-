#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define max 100
int n;
int a[max][max];
int dd[max];
int pa[max], paToiUu[max];
int kc;
int c, kcMin  = 10000;

void DocDL()
{
    FILE *f;
    f = fopen("NguoiBanHang.txt", "r");
    if(!f)
    {
        printf("Loi mo tep");
        getch();
        exit(0);
    }
    fscanf(f, "%d", &n);
    int i, j;
    for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
    fscanf(f, "%d", &a[i][j]);
    fclose(f);
}

void InPa()
{
    int i;
    printf("\n");
    for(i=1; i<=n; i++)
    printf("%d -> ", pa[i]);
    printf("%d - %d", pa[n+1], kc);
    printf("\n");
}

void InPaTot()
{
    int i;
    puts("\n");
    for(i=1; i<=n+1; i++)
    printf("%d -> ", paToiUu[i]);
    printf("%d - %d", paToiUu[n+1], kcMin);
    puts("\n");
}

void Try(int i)
{ 
    for(int j=2; j<=n; j++)
    if(!dd[j] && a[pa[i-1]][j])
    {
        pa[i] = j;
        dd[j] = 1;
        c += a[pa[i-1]][j];
    if(i==n)
    {
        if(a[pa[n]][1])
        {
        kc = c;
        kc += a[pa[n]][1];
        pa[n+1] = 1;
        InPa();
        if (kc < kcMin)
            {
               kcMin = kc;
               for(i=1; i<=n+1; i++)  
               paToiUu[i] = pa[i];         
            }
        }
    }
    else
    Try(i+1);
    dd[j] = 0;
    c -= a[pa[i-1]][j];
    }
}

void inMt()
{
    for(int i=1; i<=n; i++)
    {
        printf("");
        for(int j=0; j<=n; j++)
        printf("%3d", a[i][j]);
    }
}

int main()
{
    DocDL();
    dd[1] = 1;
    pa[1] = 1;
    c = 0;
    
    printf("Cac duong di co the : \n");
    Try(2);
    
    printf("\n Duong di tot nhat la : \n");
    InPaTot();
    getch();
}
