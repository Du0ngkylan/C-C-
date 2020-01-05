#include <iostream>   // input output stream 
using namespace std;
#define PI 3.1415        // Cách định nghĩa hàng số thứ 1

int main()
{
	//float r;
	// //float PI = 3.1415;  // Cách định nghĩa hàng số thứ 2

	//cout<<"Nhap vao ban kinh:\n";
	//cin>>r;
	//PI++;
	//float s = r * r * PI;

	//cout<<"s = "<<s;

	//float x = float(1) / 2;
	int x, y;
	cin>>x>>y;
	int max;
	x > y ? max = x : max = y;
	cout<<max;
	system("pause");
	return 0;
}