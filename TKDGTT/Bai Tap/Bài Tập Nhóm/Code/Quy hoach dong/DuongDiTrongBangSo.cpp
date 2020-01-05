/*
De bai:
    "Duong di trong bang so"
    Cho 1 bang so kich thuoc MxN.
    Tu 1 o (i, j) co the di toi (i+1, j-1), (i+1, j), (i+1, j+1)
    Chon duong di tu cot ben trai toi o (M, N) sao cho tong cac o tren duong di la max.

Input:
    M
    N
    A[1, _]...A[M, N]    
Output:
    K - tong cac o tren duong di max
    Toa do cac o tren duong di           
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INPUT_FILE "DuongDiTrongBangSo.txt"

int m, n, a[100][100], c[100][100];

void docDuLieu(){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
    
    if(file != NULL){
        fscanf(file, "%d %d", &m, &n);    
        int t;
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++){
                fscanf(file, "%d", &t);
                a[i][j] = t;
            }                            
    }
    else{
        puts("Khong tim thay file!");    
        getch();
        exit(0);
    }
}

void inDuLieu(){
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++)
            printf("%3d ", a[i][j]);    
        puts("");            
    }
}

int max(int a, int b, int c){
    int max = a;
    if(max<b)    
        max=b;
    if(max<c)
        max=c;
    return max;        
}

void dungBangPhuongAn(){
    /*Co so quy hoach dong*/
    for(int i=0; i<=m ;i++)
        c[i][0] = 0;
    for(int j=0; j<=n; j++)
        c[0][j] = 0;
      
    /*Dung bang phuong an*/
    for(int i=1; i<=m; i++)        
        for(int j=1; j<=n; j++){
            c[i][j] = max(c[i-1][j-1], c[i][j-1], c[i+1][j-1])+a[i][j];
        }
}

void truyVet(){
    /*Tim ket qua toi uu*/
    printf("Tong gia tri cac o tren duong di: %d\n", c[m][n]);
    
    /*Truy vet*/
    int i=m, j=n;
    while(j>0){
        printf("(%d, %d)", i, j);
        if(j>1)
            printf(" <- ");
        if(i>0){
            int k=c[i][j]-a[i][j];
            if(c[i-1][j-1]==k){
                i--;
                j--;    
            } else if(c[i][j-1]==k)
                j--;
            else
                i--;
        } else
            j--;    
    }
    puts("");
}

int main(){
    docDuLieu();
    inDuLieu();
    dungBangPhuongAn();
    truyVet();   
    
    puts("Hoan thanh!");
    getch();
    return 0;
}
/*
Chu y:
    Voi cach lam quy hoach dong, 1 bang phuong an co the chi ra moi duong di toi uu.
    Mien la o xuat phat nam ben trai o ket thuc.
    
    Voi bai nay chu y cach vien xung quanh bang de khong cho di ra ngoai bang.
*/
