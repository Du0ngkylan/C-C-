/*
3. Lap trình cho giai thuat chia de tri giai các bài toán: 
- Tìm kiem phan tu trên mang duoc sap xep.
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int *nhapDL(int *n){
    printf("\nNhap n=");scanf("%d",n);
    int i;
    int *A=(int*)malloc(*n*sizeof(int));
    printf("A[0]=");  scanf("%d",A+0);
    for(i=1;i<*n;i++){
                      do{
                      printf("A[%d]=",i);scanf("%d",A+i);
                      }while(A[i-1]>A[i]);
    }
    return A;
    }
void printOut(int n,int*A){
     int i=0;
     printf("\n***********************\n\n");
     while(i<n){
                printf("\t%d",A[i]);
                i++;
     }
     }
int timKiem(int left,int right,int*A,int k){
    
    if(right==left)return (A[left]=k?left:-1);                        
    else{
         int i=(left+right)/2;
         if(A[i]==k)return i;
         else{
         if(k<A[i])timKiem(left,i,A,k);
         else timKiem(i+1,right,A,k);
         }
    }
    }
int main(){
    int n;
    int*A=nhapDL(&n);
    printOut(n,A); 
    int left=0,right=n-1;
    int k;
    printf("\nNhap phan tu tim kiem K=");scanf("%d",&k);
    if(timKiem(left,right,A,k)==-1)printf("\nKhong tim thay.");
    else printf("\n%d vi tri so do trong mang la: %d",k,timKiem(left,right,A,k));
    getch();
    }
