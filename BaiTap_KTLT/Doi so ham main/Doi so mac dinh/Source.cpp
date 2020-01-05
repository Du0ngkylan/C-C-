#include <iostream>
using namespace std;

void GiaiPTBac1( float a = 5,  float b = 5)
{
	if(a == 0)
	{
		if(b == 0)
			cout<<"PT VSN";
		else 
			cout<<"PT VN";
	}
	else 
	{
		float x = -b / a;
		cout<<"PT CO NGHIEM X = "<<x;
	}
}
int main()
{
	GiaiPTBac1(1,2);
	system("pause");
	return 0;
}