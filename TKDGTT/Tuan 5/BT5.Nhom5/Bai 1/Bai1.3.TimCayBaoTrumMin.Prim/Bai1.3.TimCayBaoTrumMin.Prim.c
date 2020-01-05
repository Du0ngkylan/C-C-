/*Tim cay bao trum toi thieu cua do thi vo huong*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
int max=0x7fffffff;
int n,m,dd[100],dau[100],cuoi[100],ts[100],d[100];
// n:so dinh m: so cung
//dd[] mang danh dau cac dinh thuoc cay bao trum toi thieu
//d[] dan dau cac cung thuoc cay bao trum toi thieu
//dau[] cuoi[] mang cac dinh dau va dinh cuoi cua cac cung trong do thi ban dau
//ts[] mang trong so cua cac dih 
//W: Tong trong so cac cung trong cay bao trum toi thieu

//ban dau chua co cung nao thuoc cay bao trum toi thieu
void khoidau()
{
     int i;
     for(i=1;i<=n;i++)
          dd[i]=0;
     for(i=1;i<=m;i++)
          d[i]=0;
}
void in1()
{
     int i;
     for(i=1;i<=m;i++)
          printf("%d\t%d----%d\n",dau[i],cuoi[i],ts[i]);
}
void nhap()
{
     FILE *f;
     int i;
     char s[200];
     f=fopen("dothi.dat","r");
     if(!f)
     {
           printf("Loi mo tep!");  getch();   exit(0);
     }
     fscanf(f,"%d%d",&n,&m);
     fgets(s,200,f);
     for(i=1;i<=m;i++)
     {
           fscanf(f,"%d%d%d",&dau[i],&cuoi[i],&ts[i]);
           fgets(s,200,f);
     }
     fclose(f);
}
/*tim cung trong so nho nhat chua thuoc cay bao trum dang xay dung
co 1 dinh thuoc cay va 1 dinh chua thuoc cay*/
int tim()
{
    int i,min=max;//min: chi so cua cung co trong so nho nhat chua thuoc cay bao trum
    int tsMin=max;//max1: trong so cua cung nho nhat chua thuoc cay bao trum
    for(i=1;i<=m;i++)
    {
        if(d[i]==0)
        {
            if((dd[dau[i]]+dd[cuoi[i]])==1 &&ts[i]<tsMin)
            {
                 tsMin=ts[i];
                 min=i;
            }    
        }
    }
    return min;
}
void Prim()
{
     int i,a;
     for(i=1;i<=n-1;i++)
     {
           a=tim();
           d[a]=1;
           dd[dau[a]]=1;  dd[cuoi[a]]=1;
         
     }
}
void in()
{
     int i;
     for(i=1;i<=n;i++)
          if(dd[i]==0)
          {
                      printf("do thi khong co cay bao trum toi thieu!\n");  getch(); exit(0);
          }
     for(i=1;i<=m;i++)
     {
          if(d[i])
          {
                  printf("%d\t%d---%d\n",dau[i],cuoi[i],ts[i]);
          }
     }
}
int main()
{
    nhap();
    khoidau();
    printf("\n....................Do thi ban dau.....................\n");
    in1();
    dd[1]=1;
    Prim();
    printf("\n....................Cay bao trum toi thieu.....................\n");
    in();
    getch();
    return 0;
}
