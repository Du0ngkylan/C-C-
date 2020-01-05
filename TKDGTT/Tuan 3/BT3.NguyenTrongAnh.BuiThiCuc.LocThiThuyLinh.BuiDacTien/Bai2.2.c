// Phan tich so nguyen thanh tich cac thua so nguyen to
#include <stdio.h>
#include <conio.h>
int pt(int n, int i)
{
    int dem = 0;
    while (n%i == 0)
    {
        dem ++;
        n = n / i;
    }
    if (dem != 0) printf("%d ^ %d\n",i,dem);
    if (n == 1) return 0;
    i++;
    pt(n, i);
}

int main()
{
    int n;
    scanf("%d", &n);
    pt(n, 2);
    getch();
    return 0;
}
