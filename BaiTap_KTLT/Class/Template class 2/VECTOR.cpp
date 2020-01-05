#pragma once
#include "VECTOR.h"

//template <class T>
//VECTOR<T>()
//{
//	count = 0;
//	a = NULL;
//}
template <class T>
T VECTOR<T>::at(int index)
{
	return this->a[index];
}

template <class T>
void VECTOR<T>::push_back(T x)
{
	count++;
	a = (T*) realloc(a, count * sizeof(T));
	a[count - 1] = x;
}

template <class T>
void VECTOR<T>::pop_back()
{
    count--;
	a = (T*) realloc(a, count * sizeof(T));
}

template <class T>
int VECTOR<T>::size()
{
	return count;
}

template <class T>
void VECTOR<T>::clear()
{
	count = 0;
	delete []a;
	a = NULL;
}
