/* 
   BAI 2
   In Hoan vi cua n phan tu
   */

#include <stdio.h>
#include <conio.h>

int a[100],b[100],n; 


void in(int dem)
{
     int i;
          for(i=1;i<=dem;i++)
          printf("%d ",a[i]);
          printf("\n");
}

void hoanvi(int i,int dem) // i là buoc thu i cua mang a[]
{
       
	for (int j=1;j<=n;j++)
	if (b[j]==1)
	{
		a[i]=j;
		b[j]=0; // ghi nhan trang thái moi 
		if(i<n)
			{
                dem=dem+1;
                hoanvi(i+1,dem);
                }
		else
		    {
                            in(dem);
		                    dem=dem-1;
                           }
        //in ra hoán vi;
        dem=dem-1;
		b[j]=1;
	}
}
void nhap()
{
   int i;
    printf("nhap n = ");
    scanf("%d",&n);
    while (n<1)
    {
          printf("nhap lai n = ");
          scanf("%d",&n);
    }
    for(i=0;i<=n;i++)
    b[i]=1;
}  

int main()
{
    int t;
    do
    {
     nhap();
     printf("hoan vi la :\n");
     hoanvi(1,1);
     printf("Ban muon thuc hien tiep?\nAn:\t1. Neu co\n\t0. Neu khong\n");
     scanf("%d",&t);
    }
    while(t==1);
    printf("bye bye");
    getch();
}
