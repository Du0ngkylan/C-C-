#include <stdio.h>
#include <conio.h>
#define tong 100
void swap(int &a, int &b)
    {
    int temp=a;
    a=b;
    b=temp;
    }
void swap(float &a, float &b)
    {
    float temp=a;
    a=b;
    b=temp;
    }
void sapxep(int n, int p[], int w[], float dg[])
    {
    for (int i=1; i<=n-1; i++)
        for (int j=i+1; j<=n; j++)
            if (dg[i]<dg[j])
                {
                swap(p[i],p[j]);
                swap(w[i],w[j]);
                swap(dg[i],dg[j]);
                }
    }
void nhapMnpw(int &M, int &n, int p[], int w[], float dg[])
    {
    printf("Trong luong toi da cua balo: ");
    scanf("%d",&M);
    printf("So mon do co la: ");
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        {
        printf("Khoi luong w va Gia tri p cua vat %d la: ",i);
        scanf("%d%d",&w[i],&p[i]);
        dg[i]=(float)p[i]/w[i];
        }
    }
void xuatMnpw(int M, int n, int p[], int w[], float dg[])
    {
    printf("Trong luong toi da cua balo:%d\n ",M);
    printf("So mon do co: %d \n",n);    
    }
void GreedyKnapsack(int M, int n, int p[], int w[])
    {
    int t=0,k=0;
    for (int i=1; i<=n; i++)
        if (w[i]<M)
            {
  
            t+=M/w[i]*p[i];
            k+=M/w[i]*w[i];
            M%=w[i];
            }
    printf("Tong trong luong cua phuong an toi uu la: %d \n",t);
    printf("Tong gia tri cua phuong an la :%d",k);
    }
int main()
    {
    int M, n, p[tong], w[tong];
    float dg[tong];
    nhapMnpw(M,n,p,w,dg);
    sapxep(n,p,w,dg);
    xuatMnpw(M,n,p,w,dg);
    GreedyKnapsack(M,n,p,w);
    getch();
    }
