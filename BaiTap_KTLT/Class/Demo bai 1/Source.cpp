#pragma pack(1)
#include "ARRAY1D.h"

typedef struct 
{
	int x, y;
}DIEM;

void XuatDiem(DIEM point)
{
	cout<<"("<<point.x<<" , "<<point.y<<")  ";
}

void main()
{
	ARRAY1D<DIEM> list;
	for(int i = 0; i < 5; i++)
	{
		DIEM x;
		x.x = i;
		x.y = i + 1;
		list.Add(x);
	}

	// (0 ,1)  (1,2)  (2,3)  (3,4)  (4,5)
	//list.Reverse();
	list.Erase(1, 3);

	
	for(int i = 0; i < list.Size(); i++)  
	{
		XuatDiem(list[i]);
	}

	list.Clear();
	
	system("pause");
}