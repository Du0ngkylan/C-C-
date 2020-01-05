#include "NODE.h"


NODE* NODE::CreateNode(SINHVIEN x)
{
	NODE* p = new NODE;
	if(p == NULL)
		return NULL;
	p->Data = x;
	p->pNext = NULL;
	p->pPred = NULL;
	return p;
}
NODE* NODE::GetNext()
{
	return this->pNext;
}
NODE* NODE::GetPred()
{
	return this->pPred;
}
NODE::NODE(void)
{
}


NODE::~NODE(void)
{
}
