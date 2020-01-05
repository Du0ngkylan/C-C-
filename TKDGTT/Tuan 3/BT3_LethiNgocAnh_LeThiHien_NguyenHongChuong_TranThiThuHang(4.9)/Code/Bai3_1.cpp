#include<stdio.h>
#include<conio.h>
//Thuat toan chia de tri : Tim phan tu trong mang duoc sap
//tim kiem nhi phan

void NhapDay(int A[100], int n) {
     int i;
     for(i=0;i<n;i++){
                      printf("a[%d] = ",i+1);
                      scanf("%d",&A[i]);
                      }
     }
void InDay(int A[],int n) {
     int i;
     printf("Day sau khi sap xep la:\n\n");
     for(i=0;i<n;i++){
                       printf("%d\t",A[i]);
                       }
     }
//Sap xep day so tang dan
void SapXep(int A[], int n){
     int i,j,temp;
     for(i=0;i<n;i++)
     for(j=i+1;j<n;j++)
     if(A[i] > A[j]) {
             temp = A[i];
             A[i]= A[j];
             A[j] = temp;
             }
     }
//Tim kiem nhi phan
void BinarySearch(int A[],int x,int L,int R) {
    if(L==R) {
            if (x==A[L]) printf("\n\nPhan tu %d co trong day.",x);
            else printf("\n\nPhan tu %d khong co trong day.",x);
             }
    else {
        int M = (L+R)/2;
       if(x <= A[M])         BinarySearch(A,x,L,M);
       else                  BinarySearch(A,x,M+1,R);
              }
    }

int main() {
    int n;
    int A[8]={5,6,2,8,9,10,4,3};
    SapXep(A,8);
    InDay(A,8);
    BinarySearch(A,6,0,7);
    getch();
    return 0;
}

