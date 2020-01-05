#include <stdio.h>
#include <conio.h>
#include "Stack.h"


int main()
{
    int n;
    printf("Nhap so dia n =  ");
    scanf("%d",&n);
    while (n<1)
    {
          printf("nhap it nhat la 1 dia. Nhap lai so dia : ");
          scanf("%d",&n);
    }
    printf("\nThu tu chuyen dia.\n");
    printf("A: Cot Nguon\tB: Cot Dich\tC: Cot Trung Gian\n\n");
    
    char a = 'A';  
    char b = 'B';
    char c = 'C';
    char tg;
    
    label:;
    if(n>0)
    {
           if(isFull(Top)==1)
           {
           Push(MA_ASCII(n));
           Push(a);
           Push(b);
           Push(c);
           n = n-1;
           tg = b;
           b = c;
           c= tg;
           goto label;
           }
    } 
    else
    {
        if(isEmpty(Top)==1)
        {
           c = Pop(b);
           b = Pop(c);   
           a = Pop(a);
           n = Pop(MA_ASCII(n));
           printf("\t%c -> %c \n", a, b);
           n = n-1;
           tg = a;
           a = c;
           c = tg;
           goto label;
        }
    }
    getch();
}
