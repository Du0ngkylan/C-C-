/* Liet ke cac day nhi phan co do dai n */

#include <stdio.h>
#include <conio.h>

void In(int a[], int n) {
    printf("\n");
    for(int i = 1; i < n; i++)
        printf("%d", a[i]);
}

void Try(int i, int a[], int n) {
    for(int j = 0; j <= 1; j++) {
        a[i] = j;
        if(i == n)
            In(a, n);
        else
            Try(i + 1, a, n);
    }
}
            
main()
{
    int a[100], n;
    printf("\nNhap so n = ");
    scanf("%d", &n);
    printf("\nLiet ke cac day nhi phan co do dai n la:\n");
    Try(1, a, n+1);
    getch();
}
    
