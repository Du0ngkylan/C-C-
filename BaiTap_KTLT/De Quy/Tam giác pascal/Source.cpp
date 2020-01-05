#include <iostream>
using namespace std;

void TamGiacPascal(int a[][20],int h,  int i, int j)
{
	// ĐK Dừng
	if(i == h)
		return;

	if (j == 0 && i != j)
	{
		a[i][j] = 1;
		cout<<a[i][j]<<" ";
		TamGiacPascal(a, h, i, j  + 1);
	}
	else if(i == j)
	{
		a[i][j] = 1;
		cout<<a[i][j]<<endl;
		TamGiacPascal(a,h, i + 1, 0);
	}
	else if(j > 0 && j < h)
	{
		a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		cout<<a[i][j]<<" ";
		TamGiacPascal(a,h, i , j + 1);
	}
}

int main()
{
	int a[20][20];
	int h;
	cout<<"Nhap chieu cao tam giac:\n";
	cin>>h;
	TamGiacPascal(a, h, 0, 0);
	system("pause");
	return 0;
}