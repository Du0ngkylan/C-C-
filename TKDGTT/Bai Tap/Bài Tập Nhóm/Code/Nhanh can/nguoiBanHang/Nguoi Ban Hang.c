//Bai toan tim duong di cua nguoi ban hang qua cac thanh pho - Nguyen Quoc Huy K51a2
#include <stdio.h>
#include <conio.h>
#define inf 99999

int n,A,T,best,x[50],y[50],Free[50],a[50][50];

void readFile(char *s)
{
    FILE *f;
    int i,j;
    f=fopen(s,"r");
    fscanf(f,"%d%d",&n,&A);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            fscanf(f,"%d",&a[i][j]);
    printf("So phan tu cua ma tran : %d \n",n);
    printf("Thanh pho bat dau khoi hanh : %d \n",A);
    puts("Ma tran la :");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%3d     ",a[i][j]);
        puts("");
    }
    fclose(f);
}

void init()
{
    int i,j,k;
    for(i=1;i<=n;i++)
        Free[i]=0;
    x[1]=A;
    Free[A]=1;    
    for(k=1;k<=n;k++)
    {
        for(j=1;j<=n;j++)
            if(a[i][j]==-1)
                a[i][j]=inf;
    }
    best=inf;
} 

void findRoad(int t,int i)
{
    int j,k;
    for(j=1;j<=n;j++)
    {
        if(a[x[i-1]][j]<inf && !Free[j])
        {
            t=t+a[x[i-1]][j]; 
            if(t<best)
            {
                x[i]=j;
                Free[j]=1;
                if(i==n &&(t+a[x[i]][x[1]]<best)) 
                {
                     best=t+a[x[i]][x[1]];
                     for(k=1;k<=n;k++)
                         y[k]=x[k];
                 
                }
                if(i<n)
                     findRoad(t,i+1); 
                Free[j]=0;
                t=0;                         
            }
        }
    }
}
        
void printRoad()
{
    int i; 
    puts("Duong di cua nguoi ban hang la : ");
    for(i=1;i<=n;i++)
        printf(" %d -> ",y[i]);
    printf(" %d ",y[1]);
}

int main()
{
    readFile("nbh.txt");
    init();
    findRoad(0,2);
    printRoad();
    getch();
    return 0;
}
