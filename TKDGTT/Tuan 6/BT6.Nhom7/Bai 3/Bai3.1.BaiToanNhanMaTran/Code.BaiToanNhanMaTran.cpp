//bai toan nhan ma tran
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
int F[100][100],n,Tr[100][100],a[100];
int max=0x7fffffff;
FILE *fo;
//F[][]: ma tran phuong an
//Tr[][] :Ma tran truy vet
//n : so ma tran can nhan
//a[] : mang luu kich co cua ma tran
void nhap()
{
     FILE *f;
     int i;
     char s[200];
     f=fopen("matran_input.txt","r");
     if(!f)
     {
           printf("Loi mo tep!");   getch();    exit(0);
     }
     fscanf(f,"%d",&n);
     fgets(s,200,f);
     for(i=1;i<=n+1;i++)
     {
          fscanf(f,"%d",&a[i]);
        
     }
     fclose(f);
}
//xac dinh ma tran phuong an
void Optimize()
{
     int i,j,k,len,r,p,q,x;
     //co so quy hoach dong
     for(i=1;i<=n;i++)
     {
            for(j=1;j<=n;j++)
            {
                   if(i==j)  F[i][j]=0;
                   else
                             F[i][j]=max;
            }
     }
     //giai cong thuc truy hoi
     for(len=2;len<=n;len++)//tinh do dai tu 2 toi n
     {
            for(i=1;i<=n-len+1;i++)//tinh F[i,i+len-1]
            {
                   j=i+len-1;
                   //thu cac vi tri phan hoach k
                   for(k=i;k<=j-1;k++)
                   {
                         p=a[i];
                         q=a[k+1]; 
                         r=a[j+1];
                         x=F[i][k]+F[k+1][j]+p*q*r;
                         if(x<F[i][j])
                         {
                                      F[i][j]=x;
                                      Tr[i][j]=k;
                         }   
                   }
            }
     }
}
//truy vet bang de quy
void Trace(int i,int j)
{
     int k;
     if(i==j)
     {
            printf("A[%d]",i);
            fprintf(fo,"A[%d]",i);
     }
     else
     {
            fprintf(fo,"(");
            printf("(");
            k=Tr[i][j];
            Trace(i,k);
            fprintf(fo,".");
            printf(".");
            Trace(k+1,j);
            fprintf(fo,")");
            printf(")");
     }
            
}
void in()
{
     int i,j;
     for(i=1;i<=n;i++)
     {
            for(j=1;j<=n;j++)
            {
                  if(F[i][j]==max)
                        printf("max\t");
                  else
                        printf("%d\t",F[i][j]);
            }
            printf("\n");
     }
}
int main()
{
    nhap();
    Optimize();
    fo=fopen("matran_output.txt","w");
    printf("\n......................Bang phuong an......................\n");
    in();
    printf("........................Phuong an.........................\n");
    Trace(1,n);
    fclose(fo);
    getch();
}
