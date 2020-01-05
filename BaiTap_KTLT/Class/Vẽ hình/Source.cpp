#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
class TamGiac 
{
private:
	int h;
public:
	TamGiac()
	{
		h = 10;
	}
	void Nhap();
	void VeTamGiac();
	void Quay();
	void PhongTo(int );
	void ThuNho(int );
	void Ve1();
	void Ve2();
	void Ve3();
	void Ve4();
};
void TamGiac::PhongTo(int h)
{
	h += 2;
}
void TamGiac::ThuNho(int h)
{
	h -= 2;
}
void TamGiac::Nhap()
{
	do
	{
	cout<<"Nhap chieu cao tam giac:\n";
	cin>>h;
	if(h < 0)
		cout<<"Chieu cao khong hop le. Nhap lai!\n";
	}while(h < 0);
}

void TamGiac::Ve1()
{
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < h * 2; j++)
		{
			if(j == h - i )
			{
				for(int k = j; k <= h + i; k++)
				{
					cout<<"* ";
				}

			}
			else 
				cout<<"  ";
		}
		cout<<endl;
	}
}

void TamGiac::Ve2()
{
	for(int i = 0; i < h ; i++)
	{	
		 for(int j = 0; j <= i; j++)
		  {
			   cout<<"* ";
		  }
		 cout<<endl;
		
	}
		for(int i = h - 2 ; i >= 0; i--)
	{
		
		 for(int j = 0; j <= i; j++)
		  {
			   cout<<"* ";
		  }
		 cout<<endl;
		
	}	
}

void TamGiac::Ve3()
{
		for(int i = h - 1; i >= 0; i--)
	{
		for(int j = 0; j < h * 2; j++)
		{
			if(j == h - i )
			{
				for(int k = j; k <= h + i; k++)
				{
					cout<<"* ";
				}

			}
			else 
				cout<<"  ";
		}
		cout<<endl;
	}
}
void TamGiac::Ve4()
{
	for(int i = 0; i < h ; i++)
	{	
		
		 for(int j = 0; j < h - i; j++)
		  {
			  
			   cout<<"  ";
		  }
		 for(int j = h - i; j < h  ; j++)
		 {
			 
			 cout<<" *";
		 }
		 
		 cout<<endl;
		
	}
		for(int i = 0; i < h ; i++)
	{	
		
		 for(int j = 0; j < i; j++)
		  {
			   cout<<"  ";
		  }
		 for(int j = i; j < h ; j++)
		 {
			 
			 cout<<" *";
		 }
		 
		 cout<<endl;
		
	}
}
void main()
{
	int h = 10;
	
	while(true)
	{
	TamGiac tg;
	tg.Ve1();
	Sleep(100);
	system("cls");
	tg.Ve2();
	Sleep(100);
	system("cls");
	tg.Ve3();
	Sleep(100);
	system("cls");
	tg.Ve4();
	Sleep(100);
	system("cls");
	}
	
	cin.get();
}