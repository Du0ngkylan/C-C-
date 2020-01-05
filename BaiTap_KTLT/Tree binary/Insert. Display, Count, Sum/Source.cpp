#include <iostream>
using namespace std;

struct NODE
{
	int data;
	NODE* pLeft;
	NODE* pRight;
};

void Init(NODE*& root)
{
	root = NULL;
}

NODE* CreateNode(int data)
{
	NODE* p = new NODE;
	p->data = data;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
};

void Insert(NODE*& root, NODE* p)
{
	if(root == NULL)
	{
		root = p;
	}
	if(p->data == root->data)
		return;
	if(p->data > root->data)
		Insert(root ->pRight, p);
	else 
		Insert(root ->pLeft, p);
}

// Duyệt trước: NLR

void NLR(NODE* root)
{
	if(root == NULL)
		return;
	else 
	{
		cout<<root->data<<" ";
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}
// Duyệt giữa: LNR
void LNR(NODE* root)
{
	if(root == NULL)
		return;
	else 
	{
		LNR(root->pLeft);
		cout<<root->data<<" ";
		LNR(root->pRight);
	}
}
// Duyệt sau: LRN
void LRN(NODE* root)
{
	if(root == NULL)
		return;
	else 
	{
		LRN(root->pLeft);
		LRN(root->pRight);
		cout<<root->data<<" ";
	}
}

bool TimKiemNode(NODE* root, int x)
{
	if(root == NULL)
		return false;
	while(root != NULL)
	{
		if(x == root->data)
			return true;           // Tìm thấy
		if(x > root->data)
		{
			root = root->pRight;
		}
		else 
		{
			root = root->pLeft;
		}
	}
	return false;
}

void DeleteNODE(NODE*& root, int x)               
{
	NODE *p;
	if(root==NULL)
		return;
	else
	{
		if(x < root->data)
			DeleteNODE(root->pLeft,x);
		else if(x > root->data)
			DeleteNODE(root->pRight,x);
		else
		{
			p = root;
			 if(p->pLeft==NULL)
			{
				root = p->pRight;
				delete p;
			}
			 else if(p->pRight==NULL)
			{
				root=p->pLeft;
				delete p;
			}
			 else
			 {
				 NODE* q = root ->pLeft;
				 NODE* z = NULL;
				 while( q->pRight != NULL)
				 {
					  z = q;
					  q = q->pRight;
				 }
				 // Ra đây q -> pright == NULL
				 // z là node "trái trên" của node q
				 // Thay giá trị node root thành gia tri phan tu the mang
				 p->data = q->data;
				 // Cập nhật z -> pright thành node bên trái phần tử thế mạng
				 if(z != NULL)                 
				 z ->pRight = q->pLeft;
				 else                           // Nếu bên nhánh trái ko có cây con bên phải nào
				 {
					 p ->pLeft = q->pLeft;
				 }
			 }
			 
		}
	}
}
// DeleteAll 
void DeleteAll(NODE*& root)
{
	if(root != NULL)
	{
		LRN(root->pLeft);
		LRN(root->pRight);
		delete root;
		root=NULL;
	}
}

int main()
{
    NODE* root;
	Init(root);
	int a[] = {2,  5, 0, 10, 8, -9};
	for each (int element in a)
	{
		NODE* p = CreateNode(element);
		Insert(root, p);
	}
	cout<<"=============> NLR <==============\n";
	NLR(root);
	cout<<"\n=============> LNR <==============\n";
	LNR(root);
	cout<<"\n=============> LRN <==============\n";
	LRN(root);

	int x = -9;

	if(TimKiemNode(root, x))
		cout<<endl<<"Tree has node "<<x<<endl;
	else 
		cout<<endl<<"Not find"<<endl;
	x = 2;
	DeleteNODE(root, 2);
	DeleteNODE(root, 8);
	cout<<"\n=============> LNR <==============\n";
	LNR(root);
	/*DeleteAll(root);*/
	system("pause");
}