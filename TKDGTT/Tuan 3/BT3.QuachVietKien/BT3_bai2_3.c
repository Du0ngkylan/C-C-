/*L?p trình cho gi?i thu?t ?? quy gi?i các bài toán: 
- Tìm s? Fibonacci th? n.
1   1   2   3   5   8
1   2   3   4   5   6
*/
#include<stdio.h>
#include<conio.h>
int fibonaci(int n)
{
    if(n<=2)return 1;
    else{
        return fibonaci(n-1)+fibonaci(n-2);     
    }
}
int main(){
    int n;
    do{
    printf("\nNhap n=");scanf("%d",&n);
    }while(n<1);
    printf("\nSo Fibonaci thu n=%d",fibonaci(n));
    getch();
    }
