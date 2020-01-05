/*ho va ten: BUi Thi Thu Dung*/

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int i, F[100];
    int n;
    F[1] = F[2] =1;
     printf ("nhap so n = "); 
    scanf ("%d", &n);
    printf ("F(1) = %d\n",F[1]);
    printf ("F(2) = %d\n",F[2]);
    for (i=3; i<=n; i++)
    {
        F[i] = F[i-1]+ F [i-2];
        printf ("F(%d) = %d\n",i, F[i]);
    }
    getch();
}
