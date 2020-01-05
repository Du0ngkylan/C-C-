#include <iostream>
using namespace std;

void GiaiPtBacHai(float a = 0, float b = 0, float c = 0)
{
	if(a == 0)
	{
		if(b == 0)
		{
			if(c == 0)
				cout<<"PT VSN";
			else 
				cout<<"PT VN";
		}
		else 
		{
			float x = -c / b;
			cout<<"PT CO NGHIEM KEP X1 = X2 = "<<x;
		}
	}
	else 
	{
		double delta = b * b - 4 * a * c;
		if(delta < 0)
			cout<<"PT VN";
		else if(delta == 0)
		{
			float x = -b / (2 * a);
			cout<<"PT CO NGHIEM KEP X1 = X2 = "<<x;
		}
		else 
		{
			float x1 = (-b + sqrt(delta)) / (2 * a);
			float x2 = (-b - sqrt(delta)) / (2 * a);
			cout<<"PT CO 2 NGHIEM X1 = "<<x1<<" , X2 = "<<x2;
		}
	}
}

int main()
{
	GiaiPtBacHai(1, 2);

	system("pause");
	return 0;
}