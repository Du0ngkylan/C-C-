#pragma once
#include "NODE.h"
class QUEUE
{
	NODE* front;
	NODE* back;
public:
	bool IsEmpTy();
	int size();
	void Push(const int x);
	void Pop();
	int WatchFront();
	int WatchBack();
	void Display();
	QUEUE(void);
	~QUEUE(void);
};

