#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/*
    Bai toan tim cay bao trum toi tieu su dung thuat toan Prim
*/
typedef struct dothi{
    int s,f,d;
} dothi;

dothi p[50];
int n,m,danhdau[50];

void doctep()
{
    FILE *f;
    int i;
    f=fopen("dothi.txt","r");
    if(!f)
    {
        printf("Loi mo tep");
        getch();
        exit(0);
    }
    while(!feof(f))
    {
        fscanf(f,"%d",&n);
        fscanf(f,"%d",&m);
        for(i=1;i<=m;i++)
        {
            fscanf(f,"%d",&p[i].s);
            fscanf(f,"%d",&p[i].f);
            fscanf(f,"%d",&p[i].d);
        }
    }
    fclose(f);
}

void sapxep()
{
    int i,j,tg;
    for(i=1;i<m;i++)
        for(j=i+1;j<=m;j++)
            if(p[i].d>p[j].d)
            {
                tg=p[i].s;
                p[i].s=p[j].s;
                p[j].s=tg;
                
                tg=p[i].f;
                p[i].f=p[j].f;
                p[j].f=tg;
                
                tg=p[i].d;
                p[i].d=p[j].d;
                p[j].d=tg;
            }
}

void prim()
{
    int i,j;
    for(i=1;i<=n;i++)
        danhdau[i]=0;
    danhdau[p[1].s]=1;
    danhdau[p[1].f]=1;
    printf("\tCung %d <--> %d\n",p[1].s,p[1].f);
    for(i=2;i<=m;i++)
        if(danhdau[p[i].s]==0 || danhdau[p[i].f]==0)
        {
            danhdau[p[i].s]=1;
            danhdau[p[i].f]=1;
            printf("\tCung %d <--> %d\n",p[i].s,p[i].f);
        } 
}

int main()
{
    doctep();
    sapxep();
    printf("\nKET QUA________________________\n");
    prim();
    getch();
}
