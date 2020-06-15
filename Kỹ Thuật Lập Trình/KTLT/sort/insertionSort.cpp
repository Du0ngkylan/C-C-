#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void shiftElement(int *a, int i){
     int iValue = a[i];
     while((i > 0) && (a[i - 1] > iValue)){
            a[i] = a[i - 1];
            i--; 
     }
     a[i] = iValue;
}

int insertionSort(int *a, int n){
    for (int i = 0; i < n; i++){
        if (a[i] < a[i - 1]){
            shiftElement(a,i);
        }
    }
}

int main(){
    int i, n, *a;
    printf("nhap n: "); scanf("%d",&n);    
    a = (int *)malloc(n*sizeof(int));
    
    InputArray(a,n);
    system("cls");
    printf("mang da nhap la: \n");
    OutputArray(a,n);
   
    puts("");
    printf("\nmang sau khi sap xep la: \n");
    insertionSort(a,n);
    OutputArray(a,n);
    free(a);
    
    getch();
    return 0;    
}
