#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define index 100;
#define STOP 27
typedef int hanhtrinh[100];
typedef int cuocphi[100][100];
int xp,n,t,min,max;

typedef struct time  time1;
double t1,t2;
hanhtrinh p,pm;
cuocphi c;
char b[100];
float r;
int  init()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        b[i]=1;
        p[i]=xp;
    }
    min=c[1][1];
    max=min;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        if(c[i][j]<min)
        min=c[i][j];
        if(c[i][j]>max)
        max=c[i][j];
    }
    printf ("min=%d\n",min);
    printf ("max=%d\n",max);
    t=n*max;
    printf ("t=%d",t);
    b[xp]=0;
    return 0;
}
int inkq()
{
    int i;
    printf ("\nHanh trinh toi uu:\n");
    for(i=0;i<n;i++)
    printf ("%d=>",pm[i]);
    printf ("%d\nChi phi:%d",xp,t);
    return 0;
}
int nhapdl()
{
    int i,j ;
    printf ("\nSo thanh pho:");     scanf ("%d",&n);
    printf ("\nThanh pho xuat phat(0...%d):",n-1);scanf("%d",&xp);
    if((xp<0)||(xp>=n))
    exit(1);
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
      printf("c[%d][%d]=",i,j);scanf("%d",&c[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf ("%3d",c[i][j]);printf("\n");
    }
     return 0;
}
int Try(int k,int s)
{
    int i,j,tg;
    for(i=0;i<n;i++)
    {
        tg=s+c[p[k-1]][i];
        if((b[i])&&(tg+min*(n-k)<t))
        {
            p[k]=i;
            b[i]=0;
            if((k==n-1)&&(tg+c[i][xp]<t))
            {
                for(j=0;j<n;j++)
                pm[j]=p[j];
                t=tg+c[i][xp];
            }
            else
                if(k<n-1)
                Try(k+1,tg);
                b[i]=1;
        }
    }
    return 0;
}
int main()
{
    printf ("    BAI TOAN NGUOI DU LICH\n");
    nhapdl();
    init();
    Try(1,0);
    inkq();
    getch();
}
