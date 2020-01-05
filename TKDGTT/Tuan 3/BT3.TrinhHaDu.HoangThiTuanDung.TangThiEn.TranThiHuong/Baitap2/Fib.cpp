#include <stdio.h>
#include <conio.h>
int Fib( int n){
    int fib;
  if (n==1||n==2)  fib = 1;
    else  fib = Fib(n-1)+Fib(n-2);
    return fib;
}


int main(){
     int n;
   printf("ban muon tim so Fib thu:");
   scanf("%d",&n);
   printf("So fibonaci thu %d la:\n",n);

      printf("%d",Fib(n));
    getch();
}
