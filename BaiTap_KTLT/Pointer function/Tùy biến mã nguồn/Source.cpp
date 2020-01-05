#include <iostream>
using namespace std;

void NhapMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Nhap vao a["<<i<<"]:\n";
		cin>>a[i];
	}
}
void XuatMang(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<"\t";
	}
}

bool LonHon(int x, int y)
{
	return x > y;      // x > y thì return true
}
bool NhoHon(int x, int y)
{
	return x < y;     // x < y thì return true
}

void SapXepTuyChon(int* a, int n,bool (*SoSanh)(int , int) )
{
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(SoSanh(a[i], a[j])) //<=>if(LonHon(a[i], a[j]) <=>  if(a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int TimMaxOrMin(int* a, int n, bool (*SoSanh)(int , int))
{
	int M = a[0];
	for(int i = 1; i < n; i++)
	{
		if(SoSanh(a[i], M)) // if(a[i] > M) 
		{
			M = a[i];
		}
	}
	return M;
}
int main()
{
	int n = 5;
	int* a = NULL;
	a = new int[n];

	NhapMang(a, n);
	XuatMang(a, n);

	SapXepTuyChon(a, n, LonHon );
	cout<<endl;
	XuatMang(a, n);

	SapXepTuyChon(a, n, NhoHon);
	cout<<endl;
	XuatMang(a, n);

	int Max = TimMaxOrMin(a, n, LonHon);
	int Min = TimMaxOrMin(a, n, NhoHon);
	cout<<endl<<"Max = "<<Max<<endl;
	cout<<endl<<"Min = "<<Min<<endl;
	if(a != NULL)
		delete []a;
	system("pause");
	return 0;
}