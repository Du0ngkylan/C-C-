/*
L?p tr�nh cho gi?i thu?t ?? quy gi?i c�c b�i to�n: 

- Ph�n t�ch s? nguy�n th�nh t�ch c�c th?a s? nguy�n t?.
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int phanTichSoNguyenThanhTichCacThuaSoNguyenTo(int n,int k){
    if(n<2){printf("%d",n);
    return 0;
    }
    else{
         while(n%k==0){
                       n=n/k;
                       printf("%d*",k);
         }
         k++;
         phanTichSoNguyenThanhTichCacThuaSoNguyenTo(n,k);
    }
    }
int main(){
    int n,k=2;
    do{
    printf("\nNhap n=");scanf("%d",&n);
    }while(n<0);
    printf("\nKet Qua Phan Tich So Nguyen Thanh Tich Cac Thua So Nguyen To:\n");
    phanTichSoNguyenThanhTichCacThuaSoNguyenTo(n,k);
    getch();
    }
