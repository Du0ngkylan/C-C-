#include <iostream>
#include <conio.h>
using namespace std;

void main()
{
	char chon;
	do 
	{
		chon = _getch();
		cout<<(int)chon<<endl;
	}while(chon != 27);
}