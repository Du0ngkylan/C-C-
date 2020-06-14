#include <stdio.h>
#include <conio.h>

int chia(int m, int n)
{
    if(m == 0) 
        return 1;
    if(n == 0) 
        return 0;
    if(m < n) 
        return chia(m, m);
    else 
        return chia (m, n - 1) + chia (m - n, n);
}   

main()
{
    int n, m;
    printf("\n Nhap so phan thuong: ");
    scanf("%d", &m);
    printf("\n Nhap so nguoi: ");
    scanf("%d", &n);
    
    printf("\n So cach chia %d phan thuong cho %d nguoi la: %d", m, n, chia(m, n));
    getch();
}
