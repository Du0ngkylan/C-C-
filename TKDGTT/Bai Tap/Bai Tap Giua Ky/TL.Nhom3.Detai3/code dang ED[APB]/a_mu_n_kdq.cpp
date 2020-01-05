#include<stdio.h>
#include<conio.h>
int main()
{
    int a,n,dem=-1,p=1,stack[100],x;
    printf("Nhap a:");
    scanf("%d",&a);
    printf("Nhap n:");
    scanf("%d",&n);
    while(n>=1)
    {
               dem++;
               stack[dem]=n;
               n=n/2;               
    }
    while(dem!=-1)
    {
                  x=stack[dem];                 
                  dem--;
                  if(x%2==0)
                    p=p*p;
                  if(x%2!=0)
                    p=p*p*a; 
    }
    printf("%d mu %d:%d",a,x,p);
    getch();
    return 0;
    }
