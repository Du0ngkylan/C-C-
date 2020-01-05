/*ho va ten: Bui Thi Thu Dung*/
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int F(int i)
{
        if (i<3)
        {
            return 1; 
        }
        else
        {
            return (F(i-1)+F(i-2));
        }
}
int main()
{
    int n,i;
    printf ("\n Nhap n = ");   scanf ("%d",&n);
    for (i=1; i<=n; i++)
    {
        printf ("%d\t",F (i));
    }
    getch();
}
