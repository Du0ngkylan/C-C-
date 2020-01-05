#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/*
    Bai toan doi tien
*/
int n,a[50],dem[50],t;

void doctep()
{
    FILE *f;
    int m,i;
    f=fopen("doitien.txt","r");
    if(!f)
    {
        printf("Loi mo tep");
        getch();
        exit(0);
    }
    while(!feof(f))
    {
        fscanf(f,"%d",&n);
        fscanf(f,"%d",&t);
        for(i=1;i<=n;i++)
        {
            fscanf(f,"%d",&m);
            a[i]=m;
        }
    }
    fclose(f);
}

void sapxep()
{
     int i,j,tg;
     for(i=1;i<n;i++)
         for(j=i+1;j<=n;j++)
             if(a[i]<a[j])
             {
                 tg = a[i];
                 a[i]=a[j];
                 a[j]=tg;
             }
}

void doitien()
{
    int i;
    for(i=1;i<=n;i++)
        dem[i]=0;
    i=1;
    while(i<=n && t>0)
    {
        dem[i]=t/a[i];
        t=t-dem[i]*a[i];
        i=i+1;
    }
    if(t>0)
        printf("Khong doi duoc");
    else
    {
        for(i=1;i<=n;i++)
         if(dem[i]!=0)
             printf("\tDung %d to menh gia %d\n",dem[i],a[i]);
    }
}

int main()
{
    int i;
    doctep();
    printf("Du lieu vao\n");
    printf("\tCac to tien menh gia:\n");
    for(i=1;i<=n;i++)
        printf("\t%d",a[i]);
    printf("\n");
    printf("\n\tSo tien can doi: %d\n",t);
    sapxep();
    printf("\n");
    printf("KET QUA__________________\n");
    doitien();
    getch();
}
