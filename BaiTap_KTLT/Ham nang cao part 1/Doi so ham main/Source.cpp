#include <iostream>
using namespace std;

void GiaiPtBacNhat(float a, float b)
{
	if(a == 0)
	{
		if(b == 0)
		{
			cout<<"PT VSN";
		}
		else 
			cout<<"PT VN";
	}
	else 
	{
		float x = -b / a;
		cout<<"PT co nghiem X = "<<x;
	}
}

void GiaiPtBacHai(float a, float b, float c)
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
int main(int argc, char** argv)
{
	if(argc == 3)
	{
		float a =  atof(argv[1]);
		float b = atof(argv[2]);
		GiaiPtBacNhat(a, b);
	}
	if(argc == 4)
	{
		float a = atof(argv[1]);
		float b = atof(argv[2]);
		float c = atof(argv[3]);
		GiaiPtBacHai(a, b, c);
	}
	system("pause");
	return 0;
	// argc: argument count (số lượng tham số)
	// argv: argument value (giá trị tham số)
}