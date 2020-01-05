/*Bai toan bo tri phong hop sao cho so cuoc hop la lon nhat*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int n, dau[100], cuoi[100], L[100], h[100], a[100];

void nhap ()
{
	FILE *f;
	int i, j, k;
	char s[200];
	f = fopen ("phonghop.dat", "r");
	if (!f) 
	{
		puts ("Loi mo tep!");
		getch ();
		exit (0);	
	}	
	fscanf (f, "%d", &n);
	for (k=1; k<=n; k++)
    {
       fscanf (f,"%d%d", &i, &j);
       dau[k] = i;
       cuoi[k] = j; 
       fgets (s, 200, f);                
    }
}

void doicho (int &x, int &y)
{
     int temp;
     
	 temp = x;
     x = y;
     y = temp;
     
}

void phandoan (int l, int r, int *X) 
{
	int i, j, x; 
    i = l; 
    j = r; 
    x = X[(l+r)/2]; 

    do 
    { 
        while (X[i] < x) 
			i++; 
        while (X[j] > x) 
			j--; 

        if(i <= j) 
        { 
            doicho (cuoi[i], cuoi[j]); 
            doicho (dau[i], dau[j]); 
            i++; 
            j--; 
        } 
    } 
    while (i<=j); 

    if (l < j)
		phandoan (l, j, X); 
    if (i < r) 
		phandoan (i, r, X); 	
}

void quick_sort () 
{ 
    int i, j; 
    phandoan(0, n-1, cuoi); 

    i = 0; 
    while (i < n) 
    { 
        if (cuoi[i] == cuoi[i+1]) 
        { 
            j = i; 
            while(cuoi[j] == cuoi[j+1])
				j++; 
            phandoan(i,j, dau); 
            i = j; 
        } 
        i++; 
    } 
} 

int max (int k)
{
    int j, max = 0;
    for (j=1; j<=k; j++)
        if ((L[j] > max) && (cuoi[j] <= dau[k+1]))
            max = L[j];
    return max;
}                    
    
void phuongan ()
{
     int i;
     L[1] = 1;
     for(i=2; i<=n; i++)
        L[i] = max(i-1) + 1;
}

void ketqua ()
{
    int i, k=1, max, j;
    
    for (i=1; i<=n; i++)
    	if (L[i] > L[k])
            k=i;
    max = L[k];
    j = max - 1;
    while (L[k] != 1 && j>=0)
	{
        h[j] = k;      
        j--;
        for (i=k-1; i>0; i--)
            if ((L[i]+1 == L[k]) && (cuoi[i] <= dau[k]))
			{
                k = i;
                break;         
            }       
    }
    h[j] = k;
    printf ("\nSo cuoc hop duoc to chuc la: %d\n\n", max);
	printf ("STT         Batdau         Ketthuc\n\n");
	for (i=0; i<max; i++)
		printf("%d\t   %4d \t  %4d \n", i+1, dau[h[i]], cuoi[h[i]]);	 
}                        
     
int main()
{
	int i;
	printf ("\n---------BAT DAU BAI TOAN---------\n");
	nhap ();
    
	puts ("");
	
	quick_sort();
    
    printf ("STT         Bat dau         Ket thuc\n\n");
    for (i=1; i<=n; i++)
    	printf ("%d\t    %4d\t    %4d\n", i, dau[i], cuoi[i]);
    	
    phuongan ();
    ketqua ();
    printf ("\n__________(*_*)Chuc vui ve va thanh cong (^_^)___________");
    getch ();
}
     
     
