#include <iostream>
using namespace std;

// Định nghĩa 1 cấu trúc NODE là 1 phần tử của DSLK
struct NODE 
{
	int data;         // Dữ liệu của NODE
	NODE* pNext;       // Liên kết để trỏ đến phần tử tiếp theo
};

// Định nghĩa 1 cấu trúc LIST là 1 DSLK. Gồm 2 thành phần đặc biệt là NODE đầu và NODE cuối.
struct LIST 
{
	NODE* pHead;
	NODE* pTail;
};

void Init(LIST& L)               // Hàm khởi tạo DSLK
{
	L.pHead = L.pTail = NULL;
} 
bool IsEmpty(LIST L)           // Kiểm tra DSLK có rỗng hay ko?
{
	if(L.pHead == NULL)       // Trả về true nếu rỗng
		return true;
	return false;
}

NODE* CreateNode(int x)      // Hàm này cần thiết trước khi Add vô DSLK
{
	NODE* p = new NODE;     // Nhớ cấp phát bộ nhớ cho con trỏ p
	p->data = x;           // Thành phần dữ liệu đã có
	p->pNext = NULL;       // Nhưng chưa gắn vô DSLK
	return p;
}
NODE* SearchNode(LIST L, int phantucantim)
{
	for(NODE*p = L.pHead; p != NULL; p = p ->pNext)
	{
		if(p->data == phantucantim)
			return p;
	}
	return NULL;
}
void AddHead(LIST& L,int x)
{
	NODE* p = CreateNode(x);      // Tạo ra NODE p trước khi gắn vào DSLK
	if(IsEmpty(L) == true)         // Nếu DSLK rỗng
	{
		L.pHead = L.pTail = p;
	}
	else 
	{
		p -> pNext = L.pHead;       // Cập nhật p liên kết với pHead
		L.pHead = p;               // Và pHead giờ chính là p
	}
}
void AddTail(LIST& L, int x)
{
	NODE* p = CreateNode(x);      // Tạo ra NODE p trước khi gắn vào DSLK
	if(IsEmpty(L) == true)         // Nếu DSLK rỗng
	{
		L.pHead = L.pTail = p;
	}
	else 
	{
		L.pTail ->pNext = p;      // Cập nhật pTail nối với p
		L.pTail = p;             // Và giờ pTail chính là p
	}
}
void AddLastNODE(LIST& L, int phantucanthem, int phantucantim)
{
	NODE*  q = SearchNode(L, phantucantim);
	NODE*  p = CreateNode(phantucanthem);
	if(q == NULL)
		return;
	if(q == L.pTail)            // Nếu q đúng là NODE cuối thì gọi hàm AddTail có sẵn
	{
		AddTail(L, phantucanthem);
	}
	else 
	{
		p->pNext = q->pNext;
		q->pNext = p;
		
	}
}
void AddFirstNode(LIST& L, int phantucanthem, int phantucantim)
{
	NODE*  q = SearchNode(L, phantucantim);
	NODE*  p = CreateNode(phantucanthem);
	if(q == NULL)
		return;
	if(q == L.pHead)            // Nếu q đúng là NODE cuối thì gọi hàm AddTail có sẵn
	{
		AddHead(L, phantucanthem);
	}
	else 
	{
		NODE* z;
		for(z = L.pHead; z ->pNext != q;z = z ->pNext);
		
		z->pNext = p;
		p->pNext = q;
	}
}
void Display(LIST L)
{
	for(NODE* p = L.pHead; p != NULL;p = p->pNext)
	{
		cout<<p->data<<"\t";
	}
}
void DeleteHead(LIST& L)
{
	if(IsEmpty(L))
		return;
	if(L.pHead == L.pTail)
	{
		delete L.pHead;
		Init(L);
	}
	else 
	{
		NODE* temp = L.pHead;
		L.pHead = L.pHead ->pNext;
		delete temp;
	}
}
void DeleteTail(LIST& L)
{
	if(IsEmpty(L))
		return;
	if(L.pHead == L.pTail)
	{
		delete L.pHead;   
		Init(L);
	}
	else 
	{
		NODE* temp;
		for(temp = L.pHead; temp ->pNext != L.pTail; temp = temp ->pNext);

		temp->pNext = NULL;         // Coi như đã mất pTail cũ
		L.pTail = temp;              // Cập nhật lại pTail mới
	}
}
void DeleteNodex(LIST&L , int x)
{
	NODE* q = SearchNode(L,x);
	if(q == NULL)
		return;
	if(q == L.pHead)
	{
		DeleteHead(L);
	}
	else if(q == L.pTail)
	{
		DeleteTail(L);
	}
	else 
	{
		NODE* z;
		for(z = L.pHead; z ->pNext != q; z =z->pNext);

		z->pNext = q->pNext;     // Cho node z luồn qua node q
		delete q;           // Đã thay đổi mối nối nên thu hồi q ok
	}
}
void DeleteALL(LIST& L)
{
	while(!IsEmpty(L))
	{
		DeleteHead(L);
	}
	Init(L);
}
void Swap(NODE*& p, NODE*& q)
{
	NODE* temp = p;
	p = q;
	q = temp;
}
void SelectionSort(LIST L)
{
	for(NODE* p = L.pHead; p != L.pTail; p = p ->pNext)
	{
		NODE* min = p;
		cout<<p->data<<endl;
		for(NODE* q = p->pNext; q != NULL; q = q->pNext)
		{
			if(q->data < min->data)
			{
				min = q;
			}
		}
		if(min != p)
		{
			swap(min->data, p->data);
		}
	}
}
int main()
{
	LIST L;
	Init(L);
	int select;
	do 
	{
		system("cls");
		cout<<"0. Exit\n\n";
		cout<<"1. Add Head\n\n";
		cout<<"2. Add Tail\n\n";
		cout<<"3. Add First Node q\n\n";
		cout<<"4. Add Last Node q\n\n";
		cout<<"5. Display\n\n";
		cout<<"6. Delete Head\n\n";
		cout<<"7. Delete Tail\n\n";
		cout<<"8. Delete Node x\n\n";
		cout<<"9. Delete All\n\n";
		cout<<"10. Selection Sort\n\n";
		cout<<"Make you choice:\n";
		cin>>select;
		switch (select)
		{
		case 0:
			{
				break;
			}
		case 1:
			{
				int x;
				cout<<"Input data:\n";
				cin>>x;
				AddHead(L, x);
				break;
			}
		case 2:
			{
				int x;
				cout<<"Input data:\n";
				cin>>x;
				AddTail(L, x);
				break;
			}
		case 3:
			{
				int phantucantim, x;
				cout<<"Input data of Node q:\n";
				cin>>phantucantim;
				cout<<"Input data of Node p:\n";
				cin>>x;
				AddFirstNode(L, x, phantucantim);
				break;
			}
		case 4:
			{
				int phantucantim, x;
				cout<<"Input data of Node q:\n";
				cin>>phantucantim;
				cout<<"Input data of Node p:\n";
				cin>>x;
				AddLastNODE(L, x, phantucantim);
				break;
			}
		case 5:
			{
				Display(L);
				system("pause");
				break;
			}
		case 6:
			{
				DeleteHead(L);
				Display(L);
				system("pause");
				break;
			}
		case 7:
			{
				DeleteTail(L);
				Display(L);
				system("pause");
				break;
			}
		case 8:
			{
				int x;
				cout<<"Input x:\n";
				cin>>x;
				DeleteNodex(L, x);
				system("pause");
				break;
			}
		case 9:
			{
				DeleteALL(L);
				break;
			}
		case 10:
			{
				SelectionSort(L);
				Display(L);
				system("pause"); break;
			}
		default:
			break;
		}
	}while(select != 0);
	DeleteALL(L);         // Thu hồi bộ nhớ khi kết thúc CT
}