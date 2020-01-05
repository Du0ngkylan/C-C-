#include<stdio.h>
#include<conio.h>
int c[100];
//==============================
void inNghiem(int k,int x[]){
    int i=1;
    for(i=1;i<=k;i++)
         printf("%d",x[i]);
    printf("\n");
}
//===============================
int chinhHopKhongLap( int i,int k,int n,int x[]){
       int j;
       for(j=1;j<=n;j++)
             if (c[j] == 0){
                      x[i] =j;
                       c[j]=1;
                       if(i==k) 
                                inNghiem(k,x);
                       else
                                chinhHopKhongLap(i+1,k,n,x);
                       c[j]=0;
             }
}
//==============================
int main(){
    int i,k,n,x[100];
    int j=100;
    for (i=0;i<100;i++)    c[j]=0;
    printf("\n Nhap n = "); scanf("%d",&n);
    printf(" Nhap k = "); scanf("%d",&k);
    chinhHopKhongLap(1,k,n,x);
    getch();
}




