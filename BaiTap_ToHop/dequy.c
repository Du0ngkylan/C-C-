#include<stdio.h>
#include<stdlib.h>

void nhap(int a[], int b[], int n){
  for(int i = 0; i < n; i++) {
    a[i]=i+1;
    b[i]=0;
  }
}

void printSubset(int a[], int b[], int n){
    int i;
    printf("{");
    for(int i = 0; i < n; i++) {
        if(b[i]==1){
            printf("%d", a[i]);
        }
    }
    printf("}\n");
}

void enumerate(int a[], int b[], int n, int k){
    if(k<0){
        printSubset(a,b,n);
    } else {
        b[k]=0;
        enumerate(a,b,n,k-1);
        b[k]=1;
        enumerate(a,b,n,k-1);
    }
}

int main(){
    int a[100], b[100], n;
    printf("nhap n: ");
    scanf("%d", &n);
    nhap(a,b,n);
    printf("cac tap con sinh ra la:\n");
    enumerate(a,b,n,n-1);
    getch();
    return 0;
}
