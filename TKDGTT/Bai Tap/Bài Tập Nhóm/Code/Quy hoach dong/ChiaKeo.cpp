/*
De bai:
    "Chia keo"
    Cho N doi keo.
    Goi keo thu i co A[i] vien keo.
    Chia cac goi keo ra thanh 2 phan de chenh lech giua 2 phan la it nhat.

Input:
    N
    A[1]...A[N]    
Output:
    M - Chenh lech giua 2 phan
    Cach chia  
    
Thuat giai:
    Dang bai:
        Day con tong bang S
        
    Cong thuc truy hoi:
        Goi S la so keo it hon -> S<=T/2 voi T la tong so keo
        So keo cua phan con lai la T-S -> chenh lech giua 2 phan la T-2S
        Chenh lech min <=> S max <=T/2
        
        Goi C[i][j] = TRUE neu su dung cac goi keo tu 1...i de tao ra 1 phan co j cai keo.
        C[i][j] = TRUE khi C[i-1][j] = TRUE hoac C[i-1][j-A[i]] = TRUE.
        
    Co so quy hoach dong:
        C[0][j] = FALSE
        C[i][0] = TRUE
        
    Ket qua:
        Tim S = max j  trong cac C[i][j] = TRUE
        S se la so keo cua phan it nhat
        
    Truy vet:
        Chi can xac dinh cac goi keo nao cua phan thu nhat.
        Bat dau tu C[i][S], ket thuc khi den hang dau tien hoac cot dau tien
        Neu C[i-1][j] = TRUE -> khong chon goi i
        Neu khong -> co chon goi i va chuyen sang xet o C[i-1][j-A[i]]
        
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INPUT_FILE "ChiaKeo.txt"

int a[50], n, t=0, t2, s=-1;
bool c[100][100], phan1[50];

void docDuLieu(){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
    
    if(file != NULL){
        fscanf(file, "%d", &n);    
        for(int i=1; i<=n; i++)
            fscanf(file, "%d", &a[i]);
    }    
    else{
        puts("Khong tim thay file!");    
        getch();
        exit(0);
    }
}

void inDuLieu(){
    puts("So keo trong moi goi:");
    for(int i=1; i<=n; i++)
        printf("Goi %-2d: %d\n", i, a[i]);
}

void dungBangPhuongAn(){
    /*Tinh tong so keo*/
    for(int i=1; i<=n; i++)
        t += a[i];
    t2 = t/2;
    
    /*Co so quy hoach dong*/ 
    for(int j=0; j<=t2; j++)
        c[0][j] = false;       
    for(int i=0; i<=n; i++)
        c[i][0] = true;        
        
    /*Dung bang*/
    for(int i=1; i<=n; i++)
        for(int j=1; j<=t2; j++){
            if(c[i-1][j] == true)    
                c[i][j] = true;
            else if(j>=a[i]){
                if(c[i-1][j-a[i]] == true)
                    c[i][j] = true;
            }
            else
                c[i][j] = false;                
        }
}

void truyVet(){
    puts("\nCach chia keo:");
    /*Tim S*/
    int i, j=t2;
    while(s == -1 && j>0){
        for(i=n; i>0; i--)
            if(c[i][j] == true){    
                s = j;
                break;
            }
        j--;                
    }
    
    /*Khoi tao phan 1 chua co goi keo nao*/
    for(int i=1; i<=n; i++)
        phan1[i] = false;
        
    /*Truy vet tim cac goi thuoc phan 1*/        
    j=s;
    while(i>0 && j>0){
        if(j>=a[i]){
            if(c[i-1][j-a[i]] == true){
                phan1[i] = true;
                j -= a[i];    
            }    
        }
        i--;
    }
    
    
    /*Chenh lech*/
    printf("So keo cua phan 1 la %d, phan 2 la %d -> chenh lech giua 2 phan la %d\n", s, t-s, t-s-s);
    
    
    /*Liet ke cac goi o phan 1*/
    puts("Cac goi keo trong phan 1:");
    for(int k=1; k<=n; k++)
        if(phan1[k] == true)
            printf("Goi %-2d: %d\n", k, a[k]);

    /*Liet ke cac goi o phan 2*/
    puts("Cac goi keo trong phan 2:");
    for(int k=1; k<=n; k++)
        if(phan1[k] == false)
            printf("Goi %-2d: %d\n", k, a[k]);
        
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
