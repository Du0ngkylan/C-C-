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
void sort(int a[], int n){
     int i, j;
     for (i = 0; i < n - 1; i++)
         for (j = i + 1; j < n; j++)
             if (a[i] > a[j])
                swap(&a[i],&a[j]);
}
int main(){
    int i, n, *a;
    printf("nhap n: "); scanf("%d",&n);
    
    a = (int *)malloc(n*sizeof(int));
    
    nhap(a,n);
//    clrscr();
      system("cls");
    xuat(a,n);
    sort(a,n);
    puts("");
    printf("mang sau khi sap xep la: ");
    puts("");
    for (i = 0; i < n; i++)
        printf("%d\t",*(a + i));
        
    free(a);
    
    getch();
    return 0;    
}
