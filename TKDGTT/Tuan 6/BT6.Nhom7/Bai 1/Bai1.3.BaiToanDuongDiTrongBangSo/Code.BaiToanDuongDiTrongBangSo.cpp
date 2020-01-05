#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int A[100][100], C[100][100], n, m;

void nhap()
{
    int i, j;
    FILE *f;
    f = fopen("bangso.dat","r");
    if (!f)
    {
          puts("Loi mo tep!");
          getch ();
          exit (0);      
    }     
    fscanf(f,"%d%d", &n, &m);
    for(i=1; i<=n; i++)
    	for(j=1; j<=m; j++)
    		fscanf(f, "%d", &A[i][j]);
    fclose(f);
}

void in()
{
	int i, j;
	for(i=1; i<=n; i++)
	{
		printf("\n");
		for(j=1; j<=m; j++)
			printf("%4d", A[i][j]);
	}
	printf("\n");	
}

int max(int x, int y, int z)
{
    int max = x;
    
    if(max<y)
        max = y;
    if(max<z)
        max = z;
    return max;
} 

void phuongan()
{
	int i, j;
	//co so quy hoach dong
	for(i=1; i<=n; i++)
		C[i][0]=0;
	for(j=1; j<=m; j++)
		C[0][j]=0;
		
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			C[i][j]= max(C[i-1][j-1], C[i][j-1], C[i+1][j-1]) + A[i][j];	
}

void luocdo()
{
    int i=n, j=m, k;
    printf("\nDuong di can tim la:\n\n");
    while(j>0)
	{
        printf ("%d-%d", i, j);
        if(i>1)
            printf(" <--- ");
        if(j>1)
		{
            k = C[i][j] - A[i][j];
            if(C[i-1][j-1] == k)
			{
                i--;
                j--;    
            } 
			else if(C[i][j-1] == k)
                j--;
            else
                i--;
        }
		else
            j--;    
    }
}

int main()
{
	nhap();
	printf("Ma tran cua bai toan: \n");
	in();
	phuongan();
	luocdo();
	getch();	
}
