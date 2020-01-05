#include <stdio.h>
#include <conio.h>

int BinarySearch(int a[], int x, int l, int r)
{
    int m;
    if(l == r) 
    {
        if(x == a[l])
            return l;
        return -1;
    }
    else 
        m = (l+r)/2;
        if (x = a[m]) 
            return m;
		else
            if (x < a[m]) 
                BinarySearch(a, x, l, m);
            else 
                BinarySearch(a, x, m + 1, r) ;
}

main()
{
    int a[100] = {1, 2, 4, 5, 6, 7, 9};
    printf("Vi tri cua so 4 la %d", BinarySearch(a, 4, 0, 6));
    getch();
}
