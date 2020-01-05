#include <iostream>
using namespace std;


void XuatMang(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<"\t";
	}
}
int main()
{
	int a[3] = {1,2,3};
	
	int b[3]; 

	//b = a; compile error vì c/c++ ko hỗ trợ toán tử = mảng qua mảng

	for(int i = 0; i < 3; i++)
	{
		b[i] = a[i];
	}
	XuatMang(b, 3);
 	system("pause");
	return 0;
}