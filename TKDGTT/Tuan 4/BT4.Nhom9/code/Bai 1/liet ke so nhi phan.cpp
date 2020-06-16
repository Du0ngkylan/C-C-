#include <stdio.h>
#include <conio.h>

void PrintResult(int a[], int n)
{
    printf("\n");
    for(int i = 1; i < n; i++)
        printf("%d", a[i]);
}

void Try(int i, int a[], int n)
{
    for(int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if(i == n)
            PrintResult(a, n);
        else
            Try(i + 1, a, n);
    }
}
            
main()
{
    int a[100], n;
    printf("\n Nhap so n = ");
    scanf("%d", &n);
    Try(1, a, n+1);
    getch();
}
    
