#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Nhap(int a[], int n){
    for(int i=0; i < n; i++) {
        a[i] = i+1;
    }
}
void copy(int a[][100], int i, int j, int length){
    for(int k = 0; k < length; k++){
        a[k][j]=a[k][i];
     }
}

void DoiXung(int a[][100], int j, int length){
    for(int i = 0; i < length; i++) {
        a[i+length][j]=a[length-i-1][j];
    }
}

void Xuat(int a[][100], int n){
     for(int j=0;j<(int) pow(2,n);j++) {
        for(int i = 0; i < n; i++) {
            printf("%2d", a[j][i]);
        }
        printf("\n");
     }
}

void Gray(int n){
    int a[100][100];
    a[0][0]=0;
    a[1][0]=1;
    for(int i = 1; i < n; i++) {
        for(int j = i;j>0;j--) {
             copy(a,j-1,j,(int) pow(2,i));
             DoiXung(a,j,(int) pow(2,i));
         }
         for(int j=0;j<(int) pow(2,i);j++){
             a[j][0]=0;
             a[j+(int)pow(2,i)][0]=1;
         }
    }
    Xuat(a,n);
}

int main(){
    int a[100],n;
    printf("nhap n:");
    scanf("%d", &n);
    Nhap(a,n);
    Gray(n);
    getch();
    return 0;
}
