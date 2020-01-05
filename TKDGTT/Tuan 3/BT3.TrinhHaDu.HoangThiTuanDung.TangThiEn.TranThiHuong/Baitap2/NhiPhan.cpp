#include <stdio.h>
#include <conio.h>
void Int2Bin( int n){
   if (n>0) Int2Bin(n/2);
       printf("%d",n%2);
}
int main(){
     int n;
   printf("Nhap so can doi:");
   scanf("%d",&n);
   printf("So sau khi doi thanh nhi phan la:\n");
      Int2Bin(n);
    getch();
}
