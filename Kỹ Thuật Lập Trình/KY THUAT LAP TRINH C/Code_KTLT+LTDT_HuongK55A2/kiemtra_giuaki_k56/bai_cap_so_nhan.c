/*
 * bai_cap_so_nhan.c
 *
 * Author: NgoHuong
 *
 *xay dung mot hang doi chua cac so nguyen tao thanh mot cap so nhan voi cong boi = 2
 * duoi dang mot danh sach moc noi, so dau tien duoc nhap tu ban phim, so phan tu
 * khong nho hon 8//laming theo stack
 */

#include <stdlib.h>
#include <stdio.h>
#define N 100

int stack[N];
int top = 0;

int cap_so_nhan(int u)
{
	int q = 2;
	if (u <= 0)
		return 0;
	return cap_so_nhan(u * q);
}

int ktstack_day()
{
	if (top == N-1)
		return 0;
	else
		return 1;
}

int ktstack_rong()
{
	if (top = 0)
		return 0;
	else
		return 1;
}

void push(int n)
{
	if (ktstack_day())
	{
		puts("\nDanh sach day, khong the them!!!");
		return;
	}
	stack[top++] = n;
}

int pop()
{
	if (ktstack_rong())
	{
		puts("\nDanh sach rong, khong lay dc");
		return 0;
	}
	if (top > 0)
	{
		return stack[top--];
	}
	else
		return 0;
}

int stack_csn(int n, int u)
{
	int i;
	//int u;
	push(u);
	for (i=u; i<n; i++)
	{
		if (cap_so_nhan(i) != 0)
		{
			push(cap_so_nhan(i));
		}
	}
	//return cap_so_nhan(i);
}

void in_kq(int stack[], int n)
{
	int i;
    int u;
    cap_so_nhan( u);
	for (i=0; i<n; i++)
	{
		printf("%d", cap_so_nhan(i));
	}

}

int main()
{
	setbuf(stdout, NULL);
	int n;
	printf("Nhap n= ");
	scanf("%d", &n);
	while (n < 8)
	{
		printf("Nhap lai:");
		scanf("%d", &n);
	}
	int u;
	printf("\nNhap u=");
	scanf("%d\n", &u);
	printf("%d", u);
	in_kq(stack, n);
	return 0;
}
