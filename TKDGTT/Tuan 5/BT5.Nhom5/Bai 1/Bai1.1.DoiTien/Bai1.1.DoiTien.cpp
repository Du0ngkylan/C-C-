/* Bai toan doi tien */

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int a[100], k[100], n, T, min;
//T : so tien can doi
// n: so loai tien
//k[i]: so to tien duoc doi cua loai tien thu i
//a[i]: menh gia cua loai tien thu i
void swap (int *x, int *y)
{
	int temp;
    temp = *x;
    *x = *y;
    *y = temp;	
}

void nhap ()
{
     int i, j, temp;
     printf ("\nNhap so loai tien: ");
     scanf ("%d", &n);
     printf ("\nNhap menh gia tien: \n");
     for (i=1; i<=n; i++)
     {              
        printf ("\nMenh gia thu %d: ", i);
        scanf ("%d", &a[i]);
     }
     for (i=1; i<n; i++)
        for (j=i+1; j<=n; j++)
        	if (a[i]<a[j])
        		swap (&a[i],&a[j]);
}
  
void in ()
{
     int i, j;
     printf ("\n------Ket qua doi tien la------\n");
     for (i=1; i<=n; i++)
        printf ("\nMenh gia %d lay %d dong.\n", a[i], k[i]);
}  
              
void changeMoney (int *a, int T)
{
     int i;
     for (i=1; i<=n; i++)
         k[i] = 0;
     i=1;
     while (i<=n && T>0)
     {
           k[i] = T/a[i];
           T = T - k[i]*a[i];
           i++;
     }     
     if (T>0) 
	 	printf("\nKhong doi duoc(u_u)!!!"); 
     else 
	 	in ();
}

int main()
{
    int i;
    printf ("\n______BAI TOAN DOI TIEN______\n\n");
    printf ("Nhap so tien can doi: ");
    scanf ("%d", &T);
    nhap ();
    changeMoney (a, T);
	getch ();
}
      



