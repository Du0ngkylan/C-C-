//Liet ke cac day nhi phan co do dai n. 
#include<stdio.h>
#include<conio.h>
int x[30],y[3];
int n;
void write()
{
     int i;
     FILE *f2;
     f2=fopen("daynhiphan.out","a");
     for(i=1;i<=n;i++)
     {
                      fprintf(f2,"%d",x[i]);
     }
     fprintf(f2,"\n");
     fclose(f2);
}
void try1(int i)
{
              int j;
              for(j=1;j<=2;j++)
              { 
                    x[i]=y[j];     //gan x[i] bang gia tri co the co ( 0 or 1 )         
                    if(i==n)       //neu i == n thi co 1 bo nghiem thoa man
                    write();       
                    else
                    try1(i+1);         
              }
}
int main()
{
    FILE *f1;
    int i=0;
    printf("\nNhap n: ");
    scanf("%d",&n);
    y[1]=0;
    y[2]=1;
    try1(1);
    printf("\nKet qua da duoc in ra tep daynhiphan.out.");
    getch();
    return 0;
}
