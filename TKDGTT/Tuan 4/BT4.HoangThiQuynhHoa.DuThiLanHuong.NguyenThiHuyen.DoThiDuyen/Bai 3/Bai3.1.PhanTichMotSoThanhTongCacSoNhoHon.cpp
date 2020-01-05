/*
Bai 3.1: Phan tich so n thanh tong cua cac so nho hon.
*/

#include <stdio.h>
#include <conio.h>

/*Khai bao chung*/
int x[50], n;    
int dem;
 

void KiemTra()
{
    int i, s = 0;
    for (i = 0; i < n; i++)
        if (x[i] == 1) s += i+1;
    if (s == n)
    {
        dem++;
        printf("Chuoi %d: ", dem);
        for (i = 0; i < n; i++)
            if (x[i] == 1)
                printf("%d ", i+1);
        printf("\n");
    }
}


void Try(int i)
{
	int v;
    for (v = 0; v <= 1; v++)
    {
        x[i] = v;
        if (i == n-2) 
			KiemTra();
        else 
			Try(i+1);
    }
}

/*Chuong trinh chinh*/
main()
{
	printf("\nNhap so can phan tich n = ");
	scanf("%d", &n);
    dem = 0;
    Try(0);
 
    getch(); 
}
