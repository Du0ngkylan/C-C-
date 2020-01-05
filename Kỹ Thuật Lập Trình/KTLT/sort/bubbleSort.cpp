#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void nhap(int a[], int n){
     int i;
     for(i = 0; i < n; i++){
           printf("a[%d] = ",i);
           scanf("%d",a + i);      
     }
}
void xuat(int a[], int n){
     int i;
     for(i = 0; i < n; i++){
           printf("%d \t",a[i]);
     }
}
void swap(int *x, int *y){
     int temp;
     temp = *x;
     *x = *y;
     *y = temp;
}
void sortBubble(int a[], int n){
     int i, j;
     for (i = (n - 1); i > 0; i--)
         for (j = 1; j <= i; j++)
             if (a[j - 1] > a[j])
                swap(&a[j - 1],&a[j]);
}
int main(){
    int i, n, *a;
    printf("nhap n: "); scanf("%d",&n);
    
    a = (int *)malloc(n*sizeof(int));
    
    nhap(a,n);
    xuat(a,n);
    sortBubble(a,n);
    puts("");
    printf("mang sau khi sap xep la: ");
    puts("");
    for (i = 0; i < n; i++)
        printf("%d\t",*(a + i));
        
    free(a);
    
    getch();
    return 0;    
}
