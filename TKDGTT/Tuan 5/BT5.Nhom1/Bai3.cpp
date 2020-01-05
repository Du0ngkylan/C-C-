#include<conio.h>
#include<stdio.h>
#define MAX 100
int mts[MAX][MAX]; //ma tran trong so
int n;
int Cost=0;
int Tour[MAX]; //lo trinh
int daxet[MAX];
int Ddau;
void readFile(char *fname)
{
        int i,j;
        FILE *f;
        f=fopen(fname,"r");
        if (!f)
                printf("khong doc duoc tep");
        else
                printf("doc tep tin thanh cong!");
 
        fscanf(f,"%d",&n);
        for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                        fscanf(f,"%d",&mts[i][j]);
}
void out()
{
        int i,j;
        printf("\nCo %d thanh pho\n\n", n);
        for (i=1;i<=n;i++)
        {
                for (j=1;j<=n;j++)
                        printf("%3d", mts[i][j]);
                printf("\n");
        }
}
int Dulich()
{
    int v, k, w, i; 
    int mini; 
    int Cost; 
    //int daxet[max]; 
    for (k = 1; k <= n; k++)
            daxet[k]=0;
    Cost=0; 
    //int i;
        v=Ddau;
        i=1;
        Tour[i]=v;
        daxet[v]=1;
     while (i<n)
     {
           mini=1000;
           for (k=1; k<=n; k++)
           if(!daxet[k])
                   if(mini>mts[v][k])
                   {
                           mini-mts[v][k];
                           w=k;
                   }
           v=w;
           i++;
           Tour[i]=v;
           daxet[v]=1;
           Cost+=mini;
     } 
     Cost+=mts[v][Ddau];
     return Cost;
}
int main()
{
        //int Ddau;
        char c;
        char *fname="C:\Users\user\Desktop\Thamlam\dulieu.txt";
        readFile(fname);
        out();
        do
                {
                        printf("\n\nNhap vao thanh pho xuat phat (0<x<%d): ", n);
                        scanf("%d",&Ddau);
                }
                while(Ddau<=0 || Ddau>n);
 
                Dulich();
                printf("\nDuong di ngan nhat la: \n");
                for (int i=0;i<n;i++)
                        printf("%d->", Tour[i]);
                printf("%d", Tour[n]);
 
                printf("\nTong quang duong: %d", Cost);
 
        getch();
}
 
