#pragma once
#include "NODE.h"
#include "SINHVIEN.h"
class LIST
{
	NODE* pHead;
	NODE* pTail;
public:
	NODE* GetHead();
	NODE* GetTail();
	NODE* SearchNode(string tencantim);
	NODE* SearchNode2(string IDcantim);
	void AddHead(SINHVIEN x);
	void AddTail(SINHVIEN x);
	void DeleteHead();
	void DeleteTail();
	void DeleteNodeX(string maso);
	void Display();
	bool IsEmpty();
	LIST(void);
	~LIST(void);
};

