#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#define max 100 
int C[max][max];
int m,n;        
void nhap()
    {
    printf("BAI TOAN CHIA THUONG\n");
    printf("________________Nhap_____________\n||  m (phan thuong)\t");
    scanf("%d",&m);
    printf("||  n(sinh vien)\t");
    scanf("%d",&n);
    printf("||________________________________");
    }
int SCC()
   	{ 
    int i,j;
    for (i=1; i<=m; i++) C[i][0]=0;
    for (j=1; j<=n; j++) C[0][j]=1;
    for (i=1; i<=m; i++)
    {
        for (j=1; j<=n; j++)
        if (i<j) C[i][j] = C[i][i];
        else
            C[i][j] = C[i][j-1] + C[i-j][j];
    }
    return C[m][n];
}


void xuat()
    {
    printf("\n\n____________________ket qua_________________________\n");
    printf("||%d phan thuong \n||%d sinh vien\n|| => %d cach chia\n",m,n,C[m][n]);
    printf("||______________________________________________________");
    }
int main()
    {
    char k;
    do 
    {
       nhap();
       
       SCC();
      
       xuat();
       printf("\n\n Nhan 0 neu muon thoat\n Nhan so bat ki neu muon tiep tuc\n");
       scanf("%d",&k);
    }
    while(k!=0);
    printf("Chao ban^-^");
    getch();
    }
