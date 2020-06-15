#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int *binarySearch(int *a, int n, int value){
    int i, j;
    int m;
    i = 0;
    j = n - 1;
    while (i <= j){
        m = (i + j) / 2;    
        if (a[m] == value){
            return a + m;
        }else {
            if (a[m] > value){
               j = m - 1;  
            } else {
               i = m + 1;     
            }
        }
    }
    return NULL;
}

void inKq(int *a, int n, int value){
     if (binarySearch(a,n,value) == NULL)
        printf("\ntrong mang ko co gia tri %d\n ",value);
     else
         printf("\ngia tri %d trong mang\n",*binarySearch(a,n,value));
}

int main(){
    int i, n, *a;
    int value;
    printf("nhap n: "); scanf("%d",&n);    
    a = (int *)malloc(n * sizeof(int));
    
    InputArray(a,n);
    system("cls");
    printf("mang da nhap la: \n");
    OUtputArray(a,n);
   
    puts("");
    printf("nhap gia tri can tim: ");
    scanf("%d",&value);
    
    inKq(a,n,value);
    
    free(a);
    
    getch();
    return 0;    
}
