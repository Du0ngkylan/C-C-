#pragma once
#include <iostream>
using namespace std;
class NODE
{
private:
	friend class QUEUE;
	int data;
	NODE* pNext;
public:
	static NODE* CreateNode(int x);
	NODE(void);
	~NODE(void);
};

