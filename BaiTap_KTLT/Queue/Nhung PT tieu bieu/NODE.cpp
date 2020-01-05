#include "NODE.h"

NODE* NODE::CreateNode(int x)
{
	NODE* p = new NODE;
	if(p == NULL)        // Nếu cấp phát thất bại
		return NULL;
	p->data = x;
	p->pNext = NULL;
	return p;
}
NODE::NODE(void)
{

}


NODE::~NODE(void)
{
}
