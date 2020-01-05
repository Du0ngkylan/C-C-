#include <iostream>
#include <string>        // Include đến thư viện string của C++
using namespace std;

int main()
{
	string s1, s2;
	cout<<"Nhap chuoi s1:\n";
	getline(cin, s1);
	cout<<"Nhap chuoi s2:\n";
	getline(cin, s2);
	if(s1 > s2)
		cout<<"s1 > s2";
	else if(s1 == s2)
	  cout<<"s1 == s2";
	else 
		cout<<"s1 < s2";

	cin.get();
	return 0;
}