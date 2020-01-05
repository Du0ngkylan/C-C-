#include <iostream>
using namespace std;

inline void HoanVi(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

int main()
{
	int x = 1, y = 2;
	HoanVi(x, y);
	system("pause");
}