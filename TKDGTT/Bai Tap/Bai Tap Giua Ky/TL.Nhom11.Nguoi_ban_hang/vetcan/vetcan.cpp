#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define vc 100
int dd[vc],x[vc],d[vc][vc],n,min,*best;
void nhap()
{
     FILE *f;
    f = fopen("nguoibanhang.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
        exit(0);
    }
    fscanf(f, "%d", &n);
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            fscanf(f, "%d", &d[i][j]);
    fclose(f);
}
void khoitao()
{
     int i;
     for(i=1;i<=n;i++)
     dd[i]=0;
}
void in()
{
     int i,j;
     for(i=1;i<=n;i++)
     {
                      for(j=1;j<=n;j++)
                      printf("%d\t",d[i][j]);
                      printf("\n");
     }
     printf("\n");
}
void Update()
{
int s,i;
s = d[x[n]][1];
for (i = 1;i< n;i++)
 {
        s = s + d[x[i]][x[i+1]];
        if (s < min) 
        {
        min = s;
        best = x;
        }
 }
}

void Try(int i)
{
 int  j;
 
 for (j= 1;j<=n;j++)
 {
  if (dd[j]==0&& d[x[i-1]][j] < vc)
  {
   x[i] = j; dd[j] = 1;
   if (i==n) Update();
   else Try(i+1);
   dd[j] = 0;
   }
   }
}

int main()
{
    int i,j;
    FILE*f;
    f=fopen("ketqua.txt","w");
    nhap();
    khoitao();
    in();
    for(i=1; i<=n; i++)
    {for(j=1; j<=n; j++)
            
        fprintf(f,"%d",d[i][j]);
            fprintf(f,"\n");
    }
min = vc;
x[1]= 1; dd[1] = 1;
x[n+1]=1;
Try(2);
fprintf(f,"ket qua\n");
for(i=1;i<=n+1;i++)
{
 printf("%d\t",x[i]);
 fprintf(f,"%d\t",x[i]);
}
getch();
}
