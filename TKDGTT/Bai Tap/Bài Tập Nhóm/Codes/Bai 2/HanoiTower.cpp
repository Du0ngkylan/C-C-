#include <stdio.h>
#include <conio.h>

void HanoiTower(int n, char x, char z, char y)
{
    if(n == 1)
    {
        printf("\n Chuyen dia 1 tu cot %c den cot %c", x, z);
        return;
    }
    HanoiTower(n-1, x, y, z);
    printf("\n Chuyen dia %d tu cot %c den cot %c", n, x, z);
    HanoiTower(n-1, y, z, x);
}


int main ()
{
    int n;
    printf("\n Nhap so dia: ");
    scanf("%d", &n);
    printf("Cac buoc chuyen dia:");
    HanoiTower(n, 'A', 'B', 'C');
    getch();
}

