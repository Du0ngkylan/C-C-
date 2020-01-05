/*
L?p trình cho gi?i thu?t ?? quy gi?i các bài toán: 
- In bi?u di?n nh? phân c?a s? nguyên.
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int *inBieuDienNhiPhanCuaSoNguyen(int n){
    int *A=(int*)malloc((n/2+1)*sizeof(int));
    int i=0;
    A[0]=n%2;
    do{
    n=n/2;
    i++;
    A[i]=n%2;
    }while(n>0);
    printf("\n%d\n",i);
    return A;
    }


int main(){
    int n;
    do{
    printf("\nMoi ban nhap vao so nguyen n=");scanf("%d",&n);
    }while(n<0);
    int*A=inBieuDienNhiPhanCuaSoNguyen(n);
    int i=0;
    while(i<n/2+1){
               
               printf("%5d",A[i]);
               i++;
             
    }
    getch();
    }
