/*
    thuat toan cong mot sinh tat ca cac tap con cua tap co n phan tu
*/
#include<stdio.h>
#include<conio.h>
#include "tapCon.h"

void tapCon(int a[], int n);
void lietke(int a[], int n, int *count);

void tapCon(int a[], int n){
    int i;
    for(i = n; i>0; i--){
        if(a[i] == 1)
            a[i] = 0;
        else{
            a[i] = 1;
            break;
        }
    }
}

void lietke(int a[], int n, int *count){
    int i;
    for(i = 1; i<=n; i++)
        a[i] = 0;
        
    int max = power(2, n);
    for(i = 1; i<=max; i++){
        inketqua(a, n, (*count)++);
        tapCon(a, n);
    }
}

int main(){
    int i, count, a[100];
    int n = 15;
    count = 1;
    
    khoitao(a, n);
        
    printf("cac tap con cua tap hop co n phan tu:\n", n);
    lietke(a, n, &count);
        
    getch();
    return 0;
}
