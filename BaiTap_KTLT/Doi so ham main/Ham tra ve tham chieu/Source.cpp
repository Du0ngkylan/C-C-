#include <iostream>
using namespace std;

int& Getx(int& x) {
  	return x;
}

int main() {
	int x = 5;
	auto x1 = Getx(x); // x1= 5
	Getx(x) = 10; // x = 10 vì sao lại vậy nhể?
	cout<<Getx(x);
	system("pause");
	return 0;
}
