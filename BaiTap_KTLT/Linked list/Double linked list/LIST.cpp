#include "LIST.h"

NODE* LIST::SearchNode(string hotencantim)
{
	for(NODE*p = pHead; p != NULL; p = p->pNext)
	{
		if(p->Data.HoTen == hotencantim)
		{
			return p;
		}
	}
	return NULL;
}
NODE* LIST::SearchNode2(string IDcantim)
{
	for(NODE*p = pHead; p != NULL; p = p->pNext)
	{
		if(p->Data.ID == IDcantim)
		{
			return p;
		}
	}
	return NULL;
}
bool LIST::IsEmpty()
{
	return pHead == NULL;
}
void LIST::AddHead(SINHVIEN x)
{
	NODE* p  = NODE::CreateNode(x);
	if(IsEmpty())
	{
		pHead = pTail = p;
	}
	else
	{

		p->pNext = pHead;
		pHead->pPred = p;    // Khác biệt so với DSLK đơn
		pHead = p;
	}
}
void LIST::AddTail(SINHVIEN x)
{
	NODE* p  = NODE::CreateNode(x);
	if(IsEmpty())
	{
		pHead = pTail = p;
	}
	else
	{
		p->pPred = pTail;
		pTail->pNext = p;       // Nhớ thêm dòng này
		pTail = p;
	}
}

void LIST::DeleteHead()
{
	if(IsEmpty())
	{
		return;
	}
	else if(pHead == pTail)
	{
		delete pHead;
		pHead = pTail = NULL;
	}
	else 
	{
		NODE* p = pHead;
		pHead = pHead ->pNext;
		pHead->pPred = NULL;
		delete p;
	}
}
void LIST::DeleteTail()
{
	if(IsEmpty())
	{
		return;
	}
	else if(pHead == pTail)
	{
		delete pHead;
		pHead = pTail = NULL;
	}
	else 
	{
		pTail = pTail ->pPred;
		pTail->pNext = NULL;
	}
}
void LIST::DeleteNodeX(string maso)
{
	NODE* q = SearchNode2(maso);

	if(q == pHead)
	{
		DeleteHead();
	}
	else if(q == pTail)
	{
		DeleteTail();
	}
	else 
	{
		NODE* z = q->pPred;
		z->pNext = q->pNext;
		NODE* z2 = q->pNext;
		z2->pPred = z;
		delete q;
	}

}

void LIST::Display()
{
	for(NODE* p = pHead; p != NULL; p = p->pNext)
	{
		p->Data.Xuat();
	}
}

/*
   void LIST::XuatNguoc()
   {
      for(NODE* p = pTail; p != NULL; p = p ->pPred)
	   cout<<p->data<<" ";
   }
*/

NODE* LIST::GetHead()
{
	return this->pHead;
}

NODE* LIST::GetTail()
{
	return this->pTail;
}

LIST::LIST(void)
{
	pHead = pTail = NULL;
}


LIST::~LIST(void)
{
}
