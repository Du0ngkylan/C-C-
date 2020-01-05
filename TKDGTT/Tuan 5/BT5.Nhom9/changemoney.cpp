//bài toán doi tien giai bang phuong phap tham
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void Changemoney(int n, int *d, int l)
{
	int i, dd=1;
	printf(" n = ");
	for(i=1; i<=l; i++)
	{
		if(n>=d[i]&&dd==1)
		{
			printf("%d", d[i]);
			n=n-d[i];
			dd=0;
		}
		while(n>=d[i])
		{
			printf("+%d", d[i]);
			n=n-d[i];
		}
		if (n==0)
			break;
	}
	if(n>0)
	{
		printf("I canot break this n dolar bill");
	}
}	
int main()
{
	int n, *d, l, i;
	printf("Nhap vao luong tien can doi n = "); scanf("%d", &n);
	printf("\nNhap vao so các loai menh gia l = "); scanf("%d", &l);
	d=(int*)malloc((l+1)*sizeof(int));
	printf("\nNhap cac loai menh gia tien");
	for(i=1; i<=l; i++)
	{
		printf("\nMenh gia %d = ", i); scanf("%d", &d[i]);
	}
	Changemoney(n, d, l);
	getch();
}

	