#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100

int n;
int a[max][max];
int daxet[max];
int x[max];
int chiphi;

void DocDL()
{
    FILE *f;
    f = fopen("Prim.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
        exit(0);
    }
    fscanf(f, "%d", &n);
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)// cung co duong di thi khac 0; khong co thi =0
            fscanf(f, "%d", &a[i][j]);
    fclose(f);
    printf("do thi \n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf( "%d\t", a[i][j]);
            printf("\n");
    }
    printf("\n");
}

void In()
{
    int i,j;
    printf(""); 
    printf("___________ket qua____________\n\n");
    x[n+1]=1;
    for(i=1; i<=n; i++)
        {
         printf("%d -> ", x[i]);
        }
    printf("%d\tchiphi %3d", x[n+1], chiphi);
}

int ChiPhiMin(int i)
{
    int chiso = -1;
    int j;
    for(j=1; j<=n; j++)
        if(a[i][j] && !daxet[j])
            break;
    if(j>n)
        return -1;
    else
    {
        chiso = j;
        for(j=1; j<=n; j++)
            if(a[i][chiso] > a[i][j] && a[i][j] && !daxet[j])
                chiso = j;
        return chiso;
    }
}

void Prim()
{
     int i;    
    for(i = 2; i<=n; i++)
    {
        int chiso;
        chiso = ChiPhiMin(x[i-1]);
        if(chiso==-1)
            break;
        else
        {
            x[i] = chiso;
            daxet[chiso] = 1;
            chiphi += a[x[i-1]][chiso];
        }
    }
    if(i!=n+1)        
              printf("\nKhong co phuong an - Khong di qua het cac dinh");
    else
    {
        if(a[x[n]][1])
        {
            chiphi += a[x[n]][1];
            In();
        }
        else
            {
                   printf("\nKhong co phuong an - Khong quay tro lai dinh 1 duoc");
            }
    }
}

int main()
{
    DocDL();
    x[1] = 1;
    daxet[1] = 1;
    chiphi = 0;
    Prim();
    getch();
}
