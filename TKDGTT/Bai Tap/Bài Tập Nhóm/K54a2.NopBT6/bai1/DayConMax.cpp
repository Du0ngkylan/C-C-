#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
void nhap(int a[], int n)
{
	int i;	
	for(i=0;i<n;i++)
	{
		printf("\na[%d] = ",i);	scanf("%d",&a[i]);
	}
}
void in(int a[], int n)
{
	int i;
	
	for(i=0;i<n;i++)
		printf("\na[%d] = %d",i,a[i]);	
}
//liet ke day con dai nhat
void lietke(int a[], int n)
{
	int i,j, l[100],t[100],max;
	l[0]=1;t[0]=-1;
	for(i=1;i<n;i++)
	{
		max=1;
		for(j=0;j<i;j++)
		if(a[i]> a[j] && max < l[j]+1)
		{
			 max=l[j]+1;
			 t[i]=j;	
		}
	l[i]=max;
	}
	int lMax = 0;
    int viTriMax = 0; 
    for (int i=1; i<n; i++)
        if (l[i] > lMax)
        {
            lMax = l[i];
            viTriMax = i;
        }
    int kq[100]; 
    int k = lMax-1;
    do {
        kq[k] = a[viTriMax];
        k--;
        viTriMax = t[viTriMax];
    }while (k>=0);
	printf("\n- Day con don dieu tang dai nhat: ");
    for (int i=0; i<lMax; i++) printf("%d ", kq[i]);
}

int main()
{
	int a[100],n;
	printf("\Nhap n = ");scanf("%d",&n);
	nhap(a,n);
	in(a,n);
	lietke(a,n);
	getch();
	return 0;	
}
