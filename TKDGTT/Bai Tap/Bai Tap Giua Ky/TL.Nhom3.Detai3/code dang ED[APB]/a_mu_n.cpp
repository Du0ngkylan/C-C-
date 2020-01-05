#include<stdio.h>
#include<conio.h>
int mu(int a,int n)
{
    int p;
    if(n==1) return a;
    else
    {
        p=mu(a,n/2);        
        if(n%2==0) 
        {
         printf("\n%d",p*p);
         return p*p;
         }
        else 
        {
         printf("\n%d",p*p*a); 
         return p*p*a;
        }
    }
}
int main()
{
    int p,a,n;
    printf("a=");   scanf("%d",&a);
    printf("n=");   scanf("%d",&n);
    p=mu(a,n);
    printf("\n%d mu %d:%d",a,n,p);
    getch();
    return 0;
}
