#include<stdio.h>
// Tim to hop chap k cua n
#include<conio.h>
int choose(int n, int k)
{
    if(k==0 || k==n)
        return 1;
    else
        return (choose(n-1,k) + choose(n-1,k-1));
}
int main()
{
    int n,k;
    printf("nhap n: ");scanf("%d",&n);
    printf("nhap k: ");scanf("%d",&k);
    printf("To hop chap %d cua %d la: %d",k,n,choose(n,k));
    getch();
}

