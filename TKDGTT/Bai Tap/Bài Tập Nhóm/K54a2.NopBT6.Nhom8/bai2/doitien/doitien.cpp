#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#define max 100
int n, soTien;
int T[max];
int pa[max];
int B[max][max];

void DocDL()
{
    FILE *f;
    f = fopen("DoiTien.txt", "r");
    if(!f)
    {
        puts("Loi doc tep");
        getch();
        exit(0);
    }
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &soTien);
    int i;
    for(i=1; i<=n; i++)
        fscanf(f, "%d", &T[i]);
    fclose(f);
}

int Min(int a, int b)
{
    if(a<b)
        return a;
    return b;
}

void QHD()
{
    int i, j;
    for(j=1; j<=soTien; j++)
        B[0][j] = 32767;
    for(i=1; i<=n; i++)
        for(j=1; j<=soTien; j++)
        {
            if(j<T[i])
                B[i][j] = B[i-1][j];
            else
                B[i][j] = Min(B[i-1][j], 1+ B[i][j-T[i]]);
        }
}

void TruyVet()
{
    int i, j;
    i = n; j = soTien;
    int k;
    k = 1;
    while(i && (j>0))
    {
        if(B[i][j] == B[i-1][j])
            i--;
        if(B[i][j] == (1 + B[i][j-T[i]]))
        {
            j -= T[i];
            pa[k] = i;
            k++;
        }
    }
}

void InPA()
{
    int i;
    i = 1;
    while(pa[i])
    {
        printf("%3d", T[pa[i]]);
        i++;
    }
}

int main()
{
    DocDL();
    QHD();
    TruyVet();
    InPA();
    getch();
}
