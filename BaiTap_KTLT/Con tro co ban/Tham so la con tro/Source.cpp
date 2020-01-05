#include <iostream>
using namespace std;

void HoanVi(int* x, int* y) // int* x = &a;  int* y = &b;
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void main()
{
	int a = 1;
	int b = 2;
	HoanVi(&a, &b);
	cout<<"a = "<<a<<" ,b = "<<b;
	system("pause");
}