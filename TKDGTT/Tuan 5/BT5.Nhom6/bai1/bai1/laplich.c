#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/*
    Bai toan lap lich
*/
typedef struct process{
    int s,f,d;
} process;

process p[50];
int n;

void doctep()
{
    FILE *f;
    int i;
    f=fopen("laplich.txt","r");
    if(!f)
    {
        printf("Loi mo tep");
        getch();
        exit(0);
    }
    while(!feof(f))
    {
        fscanf(f,"%d",&n);
        for(i=1;i<=n;i++)
        {
            fscanf(f,"%d",&p[i].s);
            fscanf(f,"%d",&p[i].f);
        }
    }
    fclose(f);
}

void sapxep()
{
    int i,j,tg;
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(p[i].f>p[j].f)
            {
                tg=p[i].s;
                p[i].s=p[j].s;
                p[j].s=tg;
                
                tg=p[i].f;
                p[i].f=p[j].f;
                p[j].f=tg;
            }
}

void luachon()
{
    int i,j;
    j=1;
    printf("\tTo chuc chuong trinh tu %d toi %d\n",p[j].s,p[j].f);
    for(i=2;i<=n;i++)
        if(p[i].s > p[j].f)
        {
            printf("\tTo chuc chuong trinh tu %d toi %d\n",p[i].s,p[i].f);
            j=i;
        } 
}

int main()
{
    int i;
    doctep();
    printf("\nDU LIEU VAO__________________\n");
    printf("\n\tCac chuong trinh:\n");
    for(i=1;i<=n;i++)
     printf("\t\tChuong trinh %d tu %d toi %d\n",i,p[i].s,p[i].f);
    
    sapxep();
    printf("\nKET QUA________________________\n");
    luachon();
    getch();
}

