#include<stdio.h>
#include<stdlib.h>

void BangPhanHoach(int a[][100], int n){
    a[0][0] = 1;
    for(int i = 1; i < n; i++) {
        a[i][0]=0;
        for(int j = 0; j <= i; j++) {
            a[i][j] = a[i-1][j-1] + a[i-j][j];
        }    
    }
}

void Partition(int a[], int i, int v){
    if(v==0){
        for(int j = 0; j < i; j++) {
            printf("%d", a[j]);
        }
       printf("\n");
    } else{
        int min = a[i-1] < v ? a[i-1] : v;
        for(int j = min; j >= 1;j--) {
           a[i]=j;
           Partition(a, i+1, v-j);
        }
    }
}

void OutPut(int a[][100], int n){
     for(int i = 1; i < n; i++){    
        for(int j = 0; j <= i; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
     }
}

int main(){
    int a[100][100], b[100], n;
    
    printf("nhap n: ");
    scanf("%d", &n);
    
    printf("Bang phan hoach la:\n");
    
    BangPhanHoach(a,n);
    OutPut(a, n);
    
    printf("cac phan hoach nguyen la:\n");
    
    Partition(b,0, n);
    return 0;
}
