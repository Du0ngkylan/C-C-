#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

float *a;//Mang can xet
int n;//so phan tu trong mang
float max,min;
//Ham nhap phan tu 
float *nhap()
{
   int i;
   float *x;
   x=(float *)malloc(n*sizeof(float));
   if(!x)
   {
        puts("Loi ve cap phat bo nho: ");
        getch();
        exit(0);
   }
   for(i=0;i<n;i++)
   {
        printf("Nhap phan tu %d     ",i+1);
        scanf("%f",x+i);
   }
   return x;
}

//ham tim max,min
void maxmin(int i, int j)
{
	float max1, min1, mid;
	if(i==j)//truong hop mang mot phan tu
	{
		max = min = a[i];
	}
	else
	{
		if(i == j-1)//truong hop mang 2 phan tu
		{
			if(a[i] <a[j])
			{
				max = a[j];
				min = a[i];
			}
			else
			{
				max = a[i];
				min = a[j];
			}
		}
		else//truong hop mang co so phan tu >2
		{
			mid = (i+j)/2;
			maxmin(i, mid);
			max1 = max;	min1 = min;
			maxmin(mid+1, j);
			if(max <max1)
				max = max1;
			if(min > min1)
				min = min1;
		}
	}
}
           

int main()
{
    printf("\nNhap so phan tu n:=  ");
    scanf("%d",&n);
    a=nhap();
    max=-1;
    min=-1;
    maxmin(0,n-1);
    printf("Min & max la: %f va %f",min,max);
    getch();
    return 0;
}



      
