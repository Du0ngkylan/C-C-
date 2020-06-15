#include <stdio.h>
#include <stdlib.h>

void InputArray(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] = ",i);
        scanf("%d",a + i);      
    }
}

void OutputArray(int *a, int n){
    for(int i = 0; i < n; i++){
          printf("%d \t",*(a + i));
    }
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}