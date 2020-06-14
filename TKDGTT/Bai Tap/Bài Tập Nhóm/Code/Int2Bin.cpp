#include <stdio.h>
#include <conio.h>

void Int2Bin(int n)
{
    if(n > 0)
    {
        Int2Bin(n/2);
        printf("%d", n%2);
    }
}

main()
{
    int n;
    printf("\n Nhap so can doi sang nhi phan n = ");
    scanf("%d", &n);
    printf("\n So dc doi sang nhi phan la: ");
    Int2Bin(n);
    getch();
}

        
