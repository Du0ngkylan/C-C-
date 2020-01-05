#include<stdio.h>
#include<conio.h>

void PT_NgTo(int n)
{
     if(n==1) return ;
     else
     {
         int d= 2;
         while(n%d!=0)
         d= d+ 1;
         printf("%d*",d);
         PT_NgTo(n/d);
     }

}
int main()
{
    int n;
    printf("Nhap n=: ");
    scanf("%d",&n);
    printf("%d=",n);
    PT_NgTo(n);
    getch();
    return 0;
}
