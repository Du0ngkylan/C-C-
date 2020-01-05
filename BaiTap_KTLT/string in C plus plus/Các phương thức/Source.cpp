#include <iostream>
#include <string>        // Include đến thư viện string của C++
using namespace std;

int main()
{
	string s = "Truong Thai An";
	cout<<s.length();   // Phương thức length() trả về độ dài của chuỗi
	//string s2 = s.substr(3, 5); // <=> s2 = "ong T"
	//cout<<endl<<"s2:"<<s2;

	s.insert(0, "Xin chao ");
	s.insert(5, 3, 'C');
	s.erase(s.length() - 2, 2);
	cout<<endl<<s;

	/*if((int)s.find("Truong") != -1)
	{
		cout<<"Tim thay ky tu T o vi tri thu "<<(int)s.find("Truong");
	}*/
	s.replace(0, 5, 2, 'A');
	cout<<endl<<s;

	string s2 = "alo 1 2 3";
	s.swap(s2);
	cout<<endl<<s<<endl<<s2;
	cin.get();
	return 0;
}