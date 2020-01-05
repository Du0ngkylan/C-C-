#include <list>            // Include đến thư viện list
#include <iostream>
using namespace std;



int main()
{ 
	list<int> L;
	for(int i = 1; i <= 5; i++)
	{
		L.push_back(i);           // Thêm phần tử vào cuối DSLK <=> Hàm AddTail
	}
	L.push_front(0);           // Thêm phần tử vào đầu DSLK  <=> Hàm AddHead
	L.push_back(0);

	list<int>::iterator  it = L.begin();        // Khai báo iterator và cho trỏ đến node đầu
	
	advance(it, 3);	// it trỏ đến Node thứ ở vị trí thứ 3
	L.insert(it, 100);        // Lúc này đang thêm 100 vào vị trí thứ 3
	
	// Duyệt DS
	
	for(it = L.begin(); it != L.end(); it++)      // 
	{
		cout<<*it<<"\t";
	}
	
	cout<<endl;
	// Duyệt ngược
	L.reverse();
	for(it = L.begin(); it != L.end(); it++)      // 
	{
		cout<<*it<<"\t";
	}
	// Kiểm tra ds rỗng hay ko
	if(L.empty() == true)
		cout<<endl<<"List empty";
	else 
		cout<<endl<<"List has node";
	
	cout<<endl;
	//// Duyệt ngược DSLK
	//list<int>::reverse_iterator rit;        // Để duyệt ngược dùng phương thức rbegin hay rend() thì phải cần đến reverse_iterator
	//// Duyệt ngược DS. rbegin viết tắt của từ reverse begin, rend viết tắt của từ reverse end
	//for(rit = L.rbegin(); rit != L.rend(); rit++)
	//{
	//	cout<<*rit<<"\t";
	//}

	cout<<endl<<"Count node la "<<L.size()<<endl;    // Dùng phương thức size để xem số node trong DS

	L.sort();            // Phương thức sort cũng được C++ hỗ trợ
	// Xuất ra xem DS sau khi sort
	for(it = L.begin(); it != L.end(); it++)      
	{
		cout<<*it<<"\t";
	}	
	cout<<endl;
	L.pop_front();      // <=> DeleteHead
	L.pop_back();       // <=> DeleteTail

	it = L.begin();
	for(int i = 0; i < 3; i++)
	{
		it++;
	}
	L.erase(it);           // Lúc này đang xóa node tai vi tri thứ 3
	for(it = L.begin(); it != L.end(); it++)      
	{
		cout<<*it<<"\t";
	}	
	L.clear();        // <=> DeleteAll

	
	system("pause");
	return 0;
}