#include <stdio.h>
#include <conio.h>

int fibonannci(int k)
{
    if(k == 0)
        return 0;
    if(k == 1)
        return 1;
    else
    {
        return fibonannci(k - 1) + fibonannci(k - 2);     
    }   
}
    
main()
{
    int k;
    do
    {
        printf("\n Nhap k = ");
        scanf("%d", &k);
        if(k < 0)
            printf("\n Nhap lai");
    }
    while(k < 0);
    
    printf("\n So Fibonannci thu %d la: %d", k, fibonannci(k));
    
    
    getch();
}
    
