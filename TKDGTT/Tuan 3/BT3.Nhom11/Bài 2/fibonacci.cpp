#include<stdio.h>
#include<conio.h>

/* BAI 2
tìm so Fibonacci thu n bang giai thuat de quy
*/

int Fi(int n)
{
     int i;
    if(n==1||n==2) return 1;
	     else  return Fi(n-1)+Fi(n-2);
}
main()
{
      int n;
      do{
    printf("nhap n = ");
    scanf("%d",&n);
    }
    while (n<=0);
      printf("\n so fibonacci thu %d la:%d ",n,Fi(n));
      getch();
}
