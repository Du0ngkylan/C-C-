#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void nhap(int *a, int n){
     int i;
     for(i = 0; i < n; i++){
           printf("a[%d] = ",i);
           scanf("%d",a + i);      
     }
}
void xuat(int *a, int n){
     int i;
     for(i = 0; i < n; i++){
           printf("%d \t",*(a + i));
     }
}
void shiftElement(int *a, int i){
     int iValue = a[i];
     while((i > 0) && (a[i - 1] > iValue)){
            a[i] = a[i - 1];
            i--; 
     }
     a[i] = iValue;
}
int insertionSort(int *a, int n){
    int i;
    for (i = 0; i < n; i++){
        if (a[i] < a[i - 1]){
            shiftElement(a,i);
        }
    }
}
int main(){
    int i, n, *a;
    printf("nhap n: "); scanf("%d",&n);    
    a = (int *)malloc(n*sizeof(int));
    
    nhap(a,n);
    system("cls");
    printf("mang da nhap la: \n");
    xuat(a,n);
   
    puts("");
    printf("\nmang sau khi sap xep la: \n");
    insertionSort(a,n);
    xuat(a,n);
    free(a);
    
    getch();
    return 0;    
}
