/* 
BAI 2
Thap Ha Noi
*/

#include <stdio.h>
#include <conio.h>

void hanoi (int n, char *cotA, char *cotC, char *cotB) 
{ 
     if(n == 1) 
     printf("\nchuyen dia 1 tu %s den %s ",cotA,cotC);
     else 
     { 
       hanoi(n-1, cotA, cotB, cotC); 
       printf("\nchuyen dia %d tu %s den %s ",n,cotA,cotC);
       hanoi(n-1, cotB, cotC, cotA);
       } 
}
int main()
{
    int n;
    char cotA,cotB,cotC;
    do
    {
    printf("nhap so dia can chuyen n = ");
    scanf("%d",&n);
    }
    while (n<=0);
    hanoi(n,"cotA","cotC","cotB");
    getch();
}
