#include <iostream>
using namespace std;

// Tạo 1 struct là NODE(đó là kiểu dữ liệu tượng trưng cho 1 phần tử trong DSLK)
struct NODE
{
	int data;            // Dữ liệu 
	NODE* pNext;         // Liên kết chỉ đến Node kế
};

// Tạo 1 struct là LIST
struct LIST 
{
	NODE* pHead;
	NODE* pTail;
};

// Tạo hàm khởi tạo 
void Init(LIST& L)
{
	L.pHead = L.pTail = NULL;    // Node đầu và cuối trỏ vào NULL vì chưa có NODE nào trong DSLK
};

// Hàm CreateNode dùng để khởi tạo bộ nhớ cho 1 NODE trước khi thêm vào DSLK
NODE* CreateNode(int x)
{
	NODE* p = new NODE;
	p->data = x;
	p->pNext = NULL;
	return p;
}

// Hàm IsEmty để kiểm tra DSLK có rỗng hay ko? Trả về true nếu rỗng ngược lại trả về false
bool IsEmpty(LIST L)
{
	if(L.pHead == NULL)
		return true;        // Rỗng
	else
		return false;
}
// Tạo hàm AddHead để thêm 1 NODE vào đầu DSLL
void AddHead(LIST& L,int x)
{
	NODE* p = CreateNode(x);     //NODE muốn thêm là NODE p
	if(IsEmpty(L))        // Nếu DS đang rỗng
	{
		L.pHead = L.pTail = p;
	}
	else              // Nếu DS có phần tử
	{
		p ->pNext = L.pHead;         // Gắn NODE p lên trước NODE pHead
		L.pHead = p;              // Và nhớ cập nhật NODE pHead giờ thành NODE p
	}
}
// Tạo hàm AddTail để thêm 1 NODE vào cuối DSLK
void AddTail(LIST& L, int x)
{
	NODE* p = CreateNode(x);
	if(IsEmpty(L))        // Nếu DS đang rỗng
	{
		L.pHead = L.pTail = p;
	}
	else 
	{
		L.pTail ->pNext = p;        // Gắn NODE p vào sau NODE pHead hiện tại
		L.pTail = p;
	}
}
// Tạo hàm SearchNode để tìm kiếm 1 NODE trong DS
NODE* SearchNode(LIST L, int phantucantim)
{
	for(NODE* p = L.pHead; p != NULL; p = p ->pNext)
	{
		if(p->data == phantucantim)
			return p;
	}
	return NULL;
}

// Tạo hàm AddFirstNode để thêm 1 NODE p vào trước 1 NODE q
void AddFirstNode(LIST& L,int x, int y)
{
	NODE* q = SearchNode(L, y);
	NODE* p = CreateNode(x);

	if(q == NULL)
	{
		cout<<"Not found\n\n";
	}
	if(q == L.pHead)
	{
		AddHead(L, x);
		return;
	}
	else 
	{
		NODE* z;
		for(z = L.pHead; z ->pNext != q; z = z ->pNext) ;// Vòng for rỗng

		// Sau khi ra khỏi vòng for. z -> pNext = q;
		z->pNext = p;
		p->pNext = q;
	}
}
// Tạo hàm AddLastNode để thêm 1 NODE p vào trước 1 NODE q
void AddLastNode(LIST& L,int x, int y)
{
	NODE* q = SearchNode(L, y);
	NODE* p = CreateNode(x);

	if(q == NULL)
	{
		cout<<"Not found\n\n";
	}
	if(q == L.pTail)
	{
		AddTail(L, x);
	}
	else 
	{
		
		p->pNext = q ->pNext;   
		q ->pNext = p;
	}
}
// Hàm Display để xuất DS ra xem
void Display(LIST L)
{
	for(NODE* p = L.pHead; p != NULL; p = p ->pNext)   // <=> for(int i = 0; i < n; i = i + 1)
	{
		cout<<p->data<<"\t";
	}
}
// Bổ sung 2 hàm SumNode, CountNode, InterchangeSort

int SumNode(LIST L)
{
   int sum = 0;
   for(NODE* p = L.pHead; p != NULL; p = p ->pNext)   // <=> for(int i = 0; i < n; i = i + 1)
	{
		sum += p->data;
	}
   return sum;
}
int CountNode(LIST L)
{
   int dem = 0;
   for(NODE* p = L.pHead; p != NULL; p = p ->pNext)   // <=> for(int i = 0; i < n; i = i + 1)
	{
		dem++;
	}
   return dem;
}
void InterchangeSort(LIST L)
{
	for(NODE* p = L.pHead; p != L.pTail; p = p ->pNext)
	{
		for(NODE* q = p ->pNext; q != NULL; q = q ->pNext)
		{
			if(p->data > q->data)
			{
				swap(p->data, q->data);
			}
		}
	}
}
// Hàm DeleteHead để xóa NODE đầu trong DS
void DeleteHead(LIST& L)
{
	if(IsEmpty(L) == true)
		return;
	else if(CountNode(L) == 1)  // else if(L.pHead == L.pTail)
	{
		delete L.pHead;
		Init(L);       // Khởi tạo lại
	}
	else 
	{
		NODE* temp;
		temp = L.pHead;
		L.pHead = L.pHead ->pNext;
		delete temp;
	}
}
// Hàm DeleteTail để xóa NODE cuối
void DeleteTail(LIST& L)
{
	if(IsEmpty(L) == true)
		return;
	else if(CountNode(L) == 1)  // else if(L.pHead == L.pTail)
	{
		delete L.pHead;
		Init(L);       // Khởi tạo lại
	}
	else 
	{
		NODE* p;
		for(p = L.pHead; p ->pNext != L.pTail; p = p->pNext)   ;

		p->pNext = NULL; // Hiểu như xóa di NODE cuối
		L.pTail = p;
	}
}

// Hàm DeleteNodex để xóa Node x
void DeleteNodex(LIST& L, int x)
{
	NODE* q  =  SearchNode(L, x);
	if(q == NULL)
	{
		cout<<"Not found Node x in Linked List\n\n";
		system("pause");
		return;
	}
	else 
	{
		if(q == L.pHead)
		{
			DeleteHead(L);
		}
		else if(q == L.pTail)
		{
			DeleteTail(L);
		}
		else // Node x nằm ở giữa 
		{
			NODE* p;
			for(p = L.pHead; p ->pNext != q; p = p->pNext);

			p->pNext = q->pNext;
			delete q;
		}
	}
}
// Hàm DeleteAll để xóa hết NODE 
void DeleteAll(LIST& L)
{
	while(IsEmpty(L) == false)
	{
		DeleteHead(L);
	}
}
// Hàm ReverseList để đảo ngược DSLK. Cài đặt giống hàm InterchangeSort chỉ khác bỏ đk if trong vòng lặp
void ReverseList(LIST L)
{
	for(NODE* p = L.pHead ; p != L.pTail; p = p->pNext)
	{
		for(NODE* q = p ->pNext; q != NULL; q = q ->pNext)
		{
			swap(p->data, q->data);
		}
	}
}
// Hàm JoinList để nối 2 DSLK thành 1 DSLK. Ví dụ nối DSLK L1, L2 thành DSLK L3

LIST JoinList(LIST L1, LIST L2)
{
	LIST L3;
	Init(L3);
	for(NODE* p = L1.pHead; p != NULL; p = p ->pNext)
	{
		AddTail(L3, p->data);
	}
	for(NODE* p = L2.pHead; p != NULL; p = p->pNext)
	{
		AddTail(L3, p->data);
	}
	return L3;
}
int main()
{
	LIST L;
	Init(L);

	int select, x;
	system("color b");
	do 
	{
		system("cls");
		cout<<"0. Exit\n\n";
		cout<<"1. Add Head\t\t\t";
		cout<<"2. Add Tail\n\n";
		cout<<"3. Add Firt Node\t\t";
		cout<<"4. Add Last Node\n\n";
		cout<<"5. Display\t\t\t";
		cout<<"6. Sum Node\n\n";
		cout<<"7. Count Node\t\t\t";
		cout<<"8. Interchange Sort\n\n";
		cout<<"9. Delete Node Head\t\t";
		cout<<"10. Delete Node Tail\n\n";
		cout<<"11. Delete Node x\t\t";
		cout<<"12. Delete All\n\n";
		cout<<"13. Reverse List\n\n";
		cout<<"Make you choice:\n";
		cin>>select;
		switch (select)
		{
		case 0: break; 
		case 1:
			{				
				cout<<"Input data:\n";
				cin>>x;
				AddHead(L, x);
				break;
			}
		case 2:
			{
				cout<<"Input data:\n";
				cin>>x;
				AddTail(L, x);
				break;
			}
		case 3:
			{
				int y;
				cout<<"Input Node q:\n";
				cin>>y;
				cout<<"Input Node p:\n";
				cin>>x;
				AddFirstNode(L, x, y);
				break;
			}
		case 4:
			{
				int y;
				cout<<"Input Node q:\n";
				cin>>y;
				cout<<"Input Node p:\n";
				cin>>x;
				AddLastNode(L, x, y);
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
				int sum = SumNode(L);
				cout<<"Sum Node = "<<sum;
				system("pause");
				break;
			}
		case 7:
			{
				int count = CountNode(L);
				cout<<"Count node = "<<count;
				system("pause");
				break;
			}
		case 8:
			{
				InterchangeSort(L);
				Display(L);
				system("pause");
				break;
			}
		case 9:
			{
				DeleteHead(L);
				Display(L);
				system("pause");
				break;
			}
		case 10:
			{
				DeleteTail(L);
				Display(L);
				system("pause");
				break;
			}
		case 11:
			{
				int x;
				cout<<"Input Node x:\n";
				cin>>x;
				DeleteNodex(L, x);
				Display(L);
				system("pause");
				break;
			}
		case 12:
			{
				DeleteAll(L);
				break;
			}
		case 13:
			{
				ReverseList(L);
				Display(L);
				system("pause");
				break;
			}
		case 14:
			{
				LIST L1,L2;
				Init(L1);
				Init(L2);
				for(int x = 1; x <= 3; x++)
				{
					AddTail(L1, x);
				}
				for(int x = 4; x <= 5; x++)
				{
					AddTail(L2, x);
				}
				LIST L3;
				Init(L3);
				L3 = JoinList(L1, L2);
				Display(L3);
				system("pause");
				break;
			}
		default:
			break;
		}
	}
	while(select != 0);
	if(IsEmpty(L) == false)
	{
		DeleteAll(L);
	}
	return 0;
}