//Bai toan: Duong di trong bang so
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int m,n,a[100][100],c[100][100];

void DocTep(){
    int i,j,k;
    FILE *f;
    f = fopen("DuongDiTrongBangSo.txt","r"); 
    if(!f){
        puts("Loi mo tep!");    
        getch();
        exit(0);      
    }
    else
    {
        fscanf(f,"%d %d",&m,&n);       
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++){
                fscanf(f,"%d",&k);
                a[i][j]=k;
            }                      
    }
}

void In(){
    int i,j;
    for(i=1;i<=m;i++){
        printf("\n");
        for(j=1;j<=n;j++)
            printf("  %d",a[i][j]);             
    }
    
}

int max(int x,int y,int z){
    int max = x;
    if(max<y)   max=y;
    if(max<z)   max=z;
    return max;        
}

void BangPhuongAn(){
    int i,j;
    //Co so quy hoach dong
    for(i=0; i<=m ;i++)    c[i][0] = 0;
    for(j=0; j<=n; j++)    c[0][j] = 0;
      
    //Dung bang phuong an
    for(i=1;i<=m;i++)        
        for(j=1;j<=n;j++)
            c[i][j] = max(c[i-1][j-1], c[i][j-1], c[i+1][j-1]) + a[i][j];      
}

void TruyVet(){
    int i=m,j=n,k;
    printf("\nTong gia tri cac o tren duong di: %d\n", c[m][n]);// Ket qua toi uu
    /*Truy vet*/
    printf("\nTruy vet:\n");
    while(j>0)
    {
        printf("(%d, %d)  ",i,j);
        if(i>1)    
        if(j>1)
        {
            k=c[i][j]-a[i][j];
            if(c[i-1][j-1]==k)       {i--; j--;} 
            else if(c[i][j-1]==k)    j--;
            else                     i--;
        } 
        else   i--;  
        else   j--;
    }
}

int main(){
    DocTep();
    In();
    BangPhuongAn();
    TruyVet();   
    getch();
    return 0;
}
