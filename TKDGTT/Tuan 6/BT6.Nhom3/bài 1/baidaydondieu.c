/*ho va ten: Bui thi thu dung*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define m 8

int main()
{
    int a[m] = {1,4,5,9,2,6,7,10}; //dãy A
    int l[m]; //l[i]: d? dài DCÐÐTDN c?a dãy a[0],..,a[i] mà có ch?a a[i]
    int t[m]; //t[i]: v? trí ph?n t? ngay phía tru?c a[i] trong DCÐÐTDN c?a dãy a[0],..,a[i]
    int i,j, max;
 
    // Bu?c 1. L?p b?ng phuong án (tính m?ng L và T)
    l[0] = 1; t[0] = -1; 
    for (i=1; i<m; i++)
    {
         max = 1; //d? dài DCÐÐTDN c?a dãy a[0],..,a[i]
        for (j=0; j<i; j++)
            if (a[j] < a[i] && max < l[j] + 1)
            {
                max = l[j] + 1;
                t[i] = j; //d? sau này truy v?t: ph?n t? ngay phía sau a[i] là a[j]
            }
        l[i] = max;
    }
 
    //Bu?c 2. Tìm v? trí cu?i c?a DCÐÐTDN
    int lMax = 0; //d? dài DCÐÐTDN c?a dãy A
    int viTriMax = 0; //a[viTriMax] s? là ph?n t? cu?i cùng trong DCÐÐTDN c?a dãy A
    for (i=1; i<m; i++)
        if (l[i] > lMax)
        {
            lMax = l[i];
            viTriMax = i;
        }
 
    //Bu?c 3. Truy v?t d? tìm DCÐÐTDN (kq): d?a vào T và viTriMax
    int kq[m]; 
    int k = lMax-1;
    do {
        kq[k] = a[viTriMax];
        k--;
        viTriMax = t[viTriMax];
    }while (k>=0);
 
    //Bu?c 4. Xu?t k?t qu?
    printf("\n- Day A: "); //Hi?n th? dãy A
    for (i=0; i<m; i++) printf("%d ", a[i]);
    printf("\n- Day con don dieu tang dai nhat: "); //Hi?n th? DCÐÐTDN
    for (i=0; i<lMax; i++) printf("%d ", kq[i]);
    printf("\n  (gom %d phan tu)", lMax);
    getch(); //d?ng màn hình d? xem k?t qu?
}
