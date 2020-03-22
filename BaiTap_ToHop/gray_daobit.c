#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void KhoiTao(int a[], int n){
    for(int i = 0; i < n; i++){
        a[i] = 0;
    }
}

void XuatMang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d", a[i]);
     }
     printf("\n");
}

int ChanLe(int a[], int n){
    int dem = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1){
            dem++;
        }
    }
    return dem%2 == 0 ? 1 : -1;
}

int DaoBit(int x){
    return x == 0 ? 1 : 0;
}

int Tim(int a[], int n){
    for(int i = n-1; i >= 0; i--){
        if(a[i] == 1){
            return i;
        }
    }
}

int gray_daobit(int a[], int n){
    for(int i = 0; i < pow(2,n)-1; i++) {
        if(ChanLe(a,n)==1) {
            a[n-1] = DaoBit(a[n-1]);
        }else{
            int k = Tim(a,n);
            a[k-1] = DaoBit(a[k-1]);
        }
        XuatMang(a,n);
    }
}

int main(){
    int a[100], n;
    printf("nhap n:");
    scanf("%d", &n);
    KhoiTao(a,n);
    in(a,n);
    gray_daobit(a,n);
    getch();
    return 0;
}
