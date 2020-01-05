#include <iostream>
using namespace std;

void GiaiPTBac1(float a, float b)
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
void GiaiPTBac2(float a, float b, float c)
{
	if(a == 0)
	{
		if(b == 0)
		{
			if(c == 0)
			{
				cout<<"PT VSN";
			}
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
		float delta = b * b - 4 * a * c;
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
			cout<<"PT CO 2 NGHIEM x1 = "<<x1<<", x2 = "<<x2;
		}
	}
}
int main(int argc, char** argv) // argc: argument count, argv: argument value
{
	if(argc != 3 && argc != 4)
	{
		cout<<"Ko the thuc hien CT";
		system("pause");
		return 0;
	}
	else if(argc == 3)
	{
		float a, b;
		a = atof(argv[1]);
		b = atof(argv[2]);
		GiaiPTBac1(a, b);
		system("pause");
	}
	else if(argc == 4)
	{
		float a, b, c;
		cout<<"Ten CT "<<argv[0];
		a = atof(argv[1]);
		b = atof(argv[2]);
		c = atof(argv[3]);
		GiaiPTBac2(a, b, c);
	}
	return 0;
}