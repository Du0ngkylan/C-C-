#include<stdio.h>
#include<conio.h>

int main()
{
    int n, i;
    
    printf("Nhap n = ");
    scanf("%d", &n);
    
    if(n < 0){
        printf("%d = - ", n);
        n = -n;
    }
    else
        printf("%d = ", n);
        
    for(i = 2; i < n;)
        if(!(n % i)) { //neu n chia het cho i
            printf("%d * ", i); //in gia tri i
            n /= i;
        }
        else 
            ++i;
    printf("%d", n);
    
    getch();
    return 0;
}
