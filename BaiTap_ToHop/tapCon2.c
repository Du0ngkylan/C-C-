/*
    thuat toan de quy sinh cac tap con cua tap co n phan tu
*/

#include<conio.h>
#include<stdio.h>
#include "tapcon.h"

void tapCon2(int a[], int n, int k, int *count){
    if(k<1){
        inketqua(a, n, (*count)++);
        return ;
    }
    else{
        a[k] = 0;
        tapCon2(a, n, k-1, count);
        a[k] = 1;
        tapCon2(a, n, k-1, count);
    }
}

int main(){
    int a[100];
    int n = 5;
    int count = 1;
    
    khoitao(a, n);
    printf("cac tap con cua tap co n phan tu:\n", n);
    tapCon2(a, n, n, &count);
    
    
    getch();
    return 0;
}
