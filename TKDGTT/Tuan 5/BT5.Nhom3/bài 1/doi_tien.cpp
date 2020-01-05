
// bai toan doi tien.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int A[100];
int T;
int k[100];
int co=0;
int n;

void nhap()
{
     FILE *f;
     int t,i=0;
     if(!(f=fopen("doitien.txt","r")))
     {
        printf("Loi mo tep");
        getch();
        exit(0);
     }
     fscanf(f," %d %d",&n,&T);
     while(fscanf(f,"%d",&t)!=-1)
     {
         A[i]=t;
         i++;
     }
     fclose(f);
}


void ChangeMoney(int n)
{
     int i;
     for(i=0;i<n;i++)
     {
        k[i]=0;
     }
         i=0;
         while(i<n&&T>0)
         {
             k[i]=T/A[i];
             T=T-k[i]*A[i];
             i++;
         }
     if(T>0)
     co=1;
}

int main()
{
    nhap();
    int i;
    printf("So cac loai tien ban co : %d\n",n);
    printf("\n");
    printf("So tien ban muon doi : %d\n",T);
    printf("\n");
    printf("Menh gia cua cac loai tien ma ban co: \n");
    for(i=0;i<n;i++)
    printf("%5d",A[i]);
    printf("\n");
    ChangeMoney(n);
    if(co==1)
    {
       printf("\nRat tiec khong doi duoc ");
    }
    else
    {
        for(int i=0;i<n;i++)
        {
           printf("\nMenh gia %d co so luong %d: \n",A[i],k[i]);
        }
    }
    getch();
    return 0;
}
     
     
