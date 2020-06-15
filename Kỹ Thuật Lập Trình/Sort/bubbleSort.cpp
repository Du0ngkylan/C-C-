#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void sortBubble(int a[], int n){
    for (int i = (n - 1); i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (a[j - 1] > a[j]) {
                swap(&a[j - 1],&a[j]);
            }
        }
    }
}

int main(){
    int i, n, *a;
    printf("nhap n: "); scanf("%d",&n);
    
    a = (int *)malloc(n*sizeof(int));
    
    InputArray(a,n);
    OutputArray(a,n);
    sortBubble(a,n);
    puts("");
    printf("mang sau khi sap xep la: ");
    puts("");
    for (i = 0; i < n; i++) {
        printf("%d\t",*(a + i));
    }

    free(a);

    return 0;    
}
