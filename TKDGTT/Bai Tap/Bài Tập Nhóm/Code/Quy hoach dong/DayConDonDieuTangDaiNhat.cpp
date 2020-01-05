/*
De bai:
    "Day con don dieu tang dai nhat"
    Cho 1 day N phan tu.
    Nhat ra cac phan tu va giu nguyen thu tu, ta duoc 1 day con.
    Tim day con don dieu tang dai nhat.

Input:
    N
    A[1]...A[N]    
Output:
    M - do dai day con don dieu tang dai nhat
    X[1]...X[M]         
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INPUT_FILE "DayConDonDieuTangDaiNhat.txt"

int a[100], n, l[100];

void docDuLieu(){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
    
    if(file != NULL){
          //Doc du lieu        
          fscanf(file,"%d", &n);
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
    for(int i=1; i<=n; i++)
            printf("%d ", a[i]);
    puts("");
}

int max(int i){
    int max=0;
    for(int j=1; j<i; j++)
            if(l[j]>max && a[j]<a[i])    
                        max = l[j];
    return max;
}

void dungBangPhuongAn(){
     /*Co so*/
     l[1] = 1;
     
     /*Dung bang*/              
     for(int i=2; i<=n; i++)
        l[i] = max(i)+1;
             
    /*
    for(int i=1; i<=n; i++)
        printf("%d ", l[i]);
    */
}

void truyVet(){
    int i=1; 
    for(int j=2; j<=n; j++)
        if(l[j]>l[i])
            i=j;
    
    printf("Do dai lon nhat: %d\n", l[i]);
    
    while(l[i]>1){
        printf("%d, ",a[i]);              
        for(int j=i-1; j>0; j--)
            if(l[j]==l[i]-1 && a[j]<a[i]){
                i=j;
                break;                
            }
                                          
    }
    printf("%d.", a[i]);
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
    Bai nay chi chu y dac biet o cho xay dung bang phuong an.
*/
