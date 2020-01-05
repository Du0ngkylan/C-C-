#include <stdio.h>
#include <conio.h>
#define m 8
//====================================================
int main()
{
    int a[m] = {1,3,6,4,1,8,7,9}; // dãy A
    int l[m]; 
    int t[m]; 
    l[0] = 1; t[0] = -1; 
    for (int i=1; i<m; i++)
    {
        int max = 1; 
        for (int j=0; j<i; j++)
            if (a[j] < a[i] && max < l[j] + 1)
            {
                max = l[j] + 1;
                t[i] = j; 
            }
        l[i] = max;
    }
    int lMax = 0; 
    int viTriMax = 0; 
    for (int i=1; i<m; i++)
        if (l[i] > lMax)
        {
            lMax = l[i];
            viTriMax = i;
        }
    int kq[m]; 
    int k = lMax-1;
    do {
        kq[k] = a[viTriMax];
        k--;
        viTriMax = t[viTriMax];
    }while (k>=0);
    printf("\n- Day A: "); // Hien thi dãy A
    for (int i=0; i<m; i++) printf("%d ", a[i]);
    printf("\n- Day con don dieu tang dai nhat: ");
    for (int i=0; i<lMax; i++) printf("%d ", kq[i]);
    printf("\n  (gom %d phan tu)", lMax);
    getch(); 
}
