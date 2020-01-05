#include<conio.h>
#include<stdio.h>
//=========================
void printResult(int i,int n)
{
    int j,k,dem=0;
    static int a[30];
    for(j=0;j<=1;j++)
    {
        a[i]=j;
        if(i==n-1)
    {
            for(k=0;k<n;k++)
                printf(" %d",a[k]);
            printf("\n");
                        }
        else printResult(i+1,n);
    }
}
//==========================
main()
{       
    int n;
    printf("\n Nhap n = ");          scanf("%d",&n);
    printf ("\n----------------------------------");
    printf("\n Day nhi phan co do dai %d la : \n\n",n);
    printResult(0,n);
    getch();
}
