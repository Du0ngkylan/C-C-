#include <stdio.h>
#include <conio.h>

void CapPhat(int*& a, int n)  // Cách 1 dùng tham chiếu
{
	a = new int[n];
}

void CapPhat(int** p,int n)
{
	*p = new int[n];
}

void main()
{
	int n = 5;
	int* a = NULL;

	//CapPhat(a, n);      // Sử dụng hàm truyền đối số kiểu tham chiếu
	
	CapPhat(&a,n);        // Sử dụng hàm với tham số là con trỏ trỏ cấp n + 1
	if(a == NULL)
		printf("Cap phat thai bai!");
	else 
	{
			printf("Cap phat thanh cong");
			delete []a;
	}

	
	_getch();
}