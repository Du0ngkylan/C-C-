/*
De bai:
    "Xep ba lo 0-1"
    Cho N do vat.
    Moi do vat co trong luong P va gia tri V.
    Ba lo co gioi han trong luong W.
    Chon cac do vat xep vao ba lo <= W va gia tri max.    
    Moi do vat chi duoc chon toi da 1 lan.

Input:
    N
    P[1], V[1]
    ...
    P[N], V[N]
    W    
Output:
    Gia tri lon nhat co the chon.
    Cac vat duoc chon.
    
Thuat giai:
    Cong thuc truy hoi:
            Neu vat thu i khong duoc chon: C[i][j]=C[i-1][j]
            Neu vat thu i duoc chon      : C[i][j]=C[i-1][j-p[i]]+v[i]
            Cong thuc truy hoi:
                C[i][j]=Max {C[i-1][j] ; C[i-1][j-p[i]]+V[i]}
        
    Co so quy hoach dong:
            C[i][0]=0;
            C[0][j]=0;
        
    Ket qua:    
            In ra: C[n][w]
        
    Truy vet:
            Neu C[i][j]=C[i-1][j] thi vat thu i ko duoc chon va xet tiep C[i-1][j]
            else C[i][j]=C[i-1][j-p[i]]+V[i] thi vat thu i duoc chon va xet tiep C[i-1][j-p[i]]+V[i]
            Dung khi: i=0 hoac j =0
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INPUT_FILE "XepBaLo01.txt"

int n, w, c[50][50], p[100], v[100] ;

void docDuLieu(){
   FILE *file;
    file = fopen(INPUT_FILE, "r");
     if(file != NULL){
        fscanf(file, "%d", &n);    
        for(int i=1; i<=n; i++){ 
                fscanf(file, "%d %d", &p[i], &v[i]);   
        }       
        fscanf(file, "%d", &w);
    }
    else{
        puts("Khong tim thay file!");    
        getch();
        exit(0);
    }
}

void inDuLieu(){
        for(int i=1; i<=n; i++){
            printf("Vat thu %d: (%d, %d)\n", i, p[i], v[i]);
        }
        printf("Gioi han cua ba lo: %d\n\n", w);
}

void dungBangPhuongAn(){
        for(int i=0; i<=n; i++){
            c[i][0]=0;
        }
        for(int j=0; j<=w; j++){
            c[0][j]=0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=w; j++){
                c[i][j] = c[i-1][j];
                if(p[i]<=j){
                    if(c[i-1][j-p[i]]+ v[i] > c[i][j] ){    
                        c[i][j]= c[i-1][j-p[i]]+v[i];
                    }
                }
            }        
        }     
}

void truyVet(){
    int i=n, j=w;
    if(c[n][w]>0){
        while(i>0&& j>0){
                if(c[i][j]==c[i-1][j-p[i]]+v[i]){
                    printf("Su dung vat thu %d: (%d, %d) \n", i, p[i], v[i] );
                    j-=p[i]; 
                } 
                    i--;
        }
    } 
    printf("Gia tri lon nhat la: %d\n", c[n][w]);
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
    Theo de bai, moi do vat chi duoc chon 1 lan.
    Nhung voi de bai ma moi do vat duoc chon nhieu lan thi cong thuc lai khac.
*/
