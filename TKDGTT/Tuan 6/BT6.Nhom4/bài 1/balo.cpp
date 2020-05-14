#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100

int v[max], w[max];
int n, W;
int L[max][max];
int vmax;
int pa[max];

void DocDL()
{
    FILE *f;
    f = fopen("XepBaLo01.txt", "r");
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
    printf(" co %d do vat\n gia tri cua toi da cua ba lo la:%d\n_____cac do vat la:____\n",n,W);
    for(int i=1;i<=n;i++)
    {
        printf("do vat thu %d: (%d,%d)\n",i,w[i],v[i]);
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
     for(int i=0; i<=n; i++)
            L[i][0]=0;
     for(int j=0; j<=W; j++)
            L[0][j]=0;
     
    for(i = 1; i<=n; i++)
        for(j=1; j<=W; j++)
        {        
            if(j>=w[i])
                L[i][j] = Max(v[i]+L[i-1][j-w[i]], L[i-1][j]);
        }
}

void TruyVet()
{
    int i, j;
    i = n; j = W;
    int k;
    k = 1;
    vmax = 0;
    

    while(i>0 && j>0)
    {
        if(L[i][j] == (v[i] + L[i-1][j-w[i]]) )
        {
            if(vmax+v[i]<=W)
            {
                            pa[k] = i;
                            vmax += v[i];
                            j -= w[i];
                            k++;
            }
        }    
        i--;
    }
    
}

void InPA()
{
    int i;
    i = 1;
    printf("\nsu dung vat thu:");
    while(pa[i])
    {
        printf("%d\t", pa[i]);
        i++;
    }
    printf("\n trong luong %3d", vmax);
}

int main()
{
    DocDL();
    QHD();
    TruyVet();
    InPA();
    getch();
}
