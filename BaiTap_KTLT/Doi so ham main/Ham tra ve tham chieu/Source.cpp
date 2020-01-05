#include <iostream>
using namespace std;



int& Getx(int& x)
{
	return x;
}

int main()
{
	int x;
	Getx(x) = 5; // x = 5
	cout<<Getx(x);
	system("pause");
	return 0;
}