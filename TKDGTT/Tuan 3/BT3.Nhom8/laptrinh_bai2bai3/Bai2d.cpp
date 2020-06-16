#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void ChuyenThap(int n,char A,char B,char C)
{
     if (n==1)
        printf("\n\t%c ->%c",A,B);
     else{
        ChuyenThap(n-1,A,C,B);
        ChuyenThap(1,A,B,C);
        ChuyenThap(n-1,C,B,A);
    }
}
int main()
{
	int n;
	printf("\nNhap n = ");
	scanf("%d",&n);
	ChuyenThap(n,'A','B','C');
	getch();
	return 0;
		
}
