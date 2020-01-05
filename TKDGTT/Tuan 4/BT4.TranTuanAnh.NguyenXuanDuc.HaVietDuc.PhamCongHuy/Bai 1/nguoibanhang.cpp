#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define max 100
int n;
int matran[max][max];
int daxet[max];
int pa[max];
int chiphi;

void DocDL()
{
    FILE *f;
    f = fopen("new.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
        exit(0);
    }
    fscanf(f, "%d", &n);
    int i, j;
    for(i=1; i <= n; i++)
        for(j=1; j<=n; j++)
            fscanf(f, "%d", &matran[i][j]);
    fclose(f);
}

void InPa()
{
    int i;
    puts("Duong di: ");
    for(i = 1; i <= n; i++)
        printf("%d -> ", pa[i]);
    printf("%d \nChi phi: %3d", pa[1], chiphi);
}

int ChiPhiMin(int i)
{
    int chiso = -1;
    int j;
    for(j = 1; j <= n; j++)
        if(matran[i][j] && !daxet[j])
            break;
    if(j>n)
        return -1;
    else
    {
        chiso = j;
        for(j = 1; j <= n; j++)
            if(matran[i][chiso] > matran[i][j] && matran[i][j] && !daxet[j])
                chiso = j;
        return chiso;
    }
}

void Greed_TSP()
{
    int i;
    for(i = 2; i <= n; i++)
    {
        int chiso;
        chiso = ChiPhiMin(pa[i-1]);
        if(chiso==-1)
            break;
        else
        {
            pa[i] = chiso;
            daxet[chiso] = 1;
            chiphi += matran[pa[i-1]][chiso];
        }
    }
    if(i!=n+1)
        printf("\nKhong co phuong an - Khong di qua het cac dinh");
    else
    {
        if(matran[pa[n]][1])
        {
            chiphi += matran[pa[n]][1];
            InPa();
        }
        else
            printf("\nKhong co phuong an - Khong quay tro lai dinh 1 duoc");
    }
}

int main()
{
    DocDL();
    pa[1] = 1;
    daxet[1] = 1;
    chiphi = 0;
    Greed_TSP();
    getch();
}
