#include <iostream>
using namespace std;

// 1 2 3 4 5

int GetElement(int a[], int index)
{
	return a[index - 1];
}

int main()
{
	int a[5] = {5, 2, 5, 7, 0};

	cout<<GetElement(a, 2); // 5
	system("pause");
	return 0;
}