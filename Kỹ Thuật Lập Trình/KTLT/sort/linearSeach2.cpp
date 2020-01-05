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
int *linearSearch(int *a, int n, int value){
    for (int i = 0; i < n; i++){
        if (a[i] == value){
           return a + i;        
        }
    }
    return NULL;
}
void inKq(int *a, int n, int value){
     if (linearSearch(a,n,value) == NULL)
        printf("\ntrong mang ko co gia tri %d\n ",value);
     else
         printf("\ngia tri %d trong mang\n",*linearSearch(a,n,value));
}
int main(){
    int i, n, *a;
    int value;
    printf("nhap n: "); scanf("%d",&n);    
    a = (int *)malloc(n * sizeof(int));
    
    nhap(a,n);
    system("cls");
    printf("mang da nhap la: \n");
    xuat(a,n);
   
    puts("");
    printf("nhap gia tri can tim: ");
    scanf("%d",&value);
    
    inKq(a,n,value);
    
    free(a);
    
    getch();
    return 0;    
}
