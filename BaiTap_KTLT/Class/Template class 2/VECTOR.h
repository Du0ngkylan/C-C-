#pragma once
#include <iostream>
using namespace std;

template<class T>
class VECTOR
{
private:
	T* a;
	int count;
public:
	VECTOR()
	{
		count = 0;
	    a = NULL;
	}
	T at(int );
	void push_back(T);
	void pop_back();
	int size();
	void clear();
};

