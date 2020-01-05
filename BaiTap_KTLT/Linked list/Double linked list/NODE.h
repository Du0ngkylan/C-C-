#pragma once
#include "SINHVIEN.h"

class NODE
{
private:
	SINHVIEN Data;           // Dữ liệu của NODE
	NODE* pNext;        // Node để trỏ sang NODE kế tiếp 
	NODE* pPred;        // Node để trỏ sang Node trước nó       	
public:
	friend class LIST;
	SINHVIEN GetData()
	{
		return this->Data;
	}
	NODE* GetNext();
	NODE* GetPred();
	static NODE* CreateNode(SINHVIEN Data);
	NODE(void);
	~NODE(void);
};






