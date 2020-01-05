#pragma pack(1)
#include <iostream>
using namespace std;
//1/ Xây dựng lớp Array1D trong thư viện tự tạo ARRAY1D.h ,áp dụng kỹ thuật tham số hóa với các chức năng chính sau:
//+ Khởi tạo mảng rổng
//+ Khởi tạo mảng có k phần tử
//+ Phương thức Add  để thêm 1 phần tử
//+ Phương thức at(int index) để truy xuất đến phần tử tại chỉ số index
//+ PT size để trả ra số lượng phần tử trong mảng
//+ Phương thức sumbyte để trả ra tổng số byte đang dùng trong mảng
//+ Toán tử == so sánh 2 mảng
//+ Phương thức swap để hoán vị 2 mảng
//+ Phương thức Insert(const int index,  int count = 1) để chèn count phần tử vào chỉ số index.
//Chú ý tham số count mặc định là 1
//+ Phương thức Erase(const int index) để xóa  phần tử tại chỉ số index
//+ Phướng thức Erase(const  int start,const  int end): để xóa phần tử tại chỉ số từ start đến end
//+ Phương thức Reverse để đảo ngược mảng
//+ Phương thức Clear để xóa hết mảng

template <class T = int>
class ARRAY1D 
{
private:
	T *a;
	int size;
public:
	ARRAY1D()
	{
		a = NULL;
		size = 0;
	}
	ARRAY1D(int k)
	{
		a = (T*)malloc(k * sizeof(T));
		size = k;
	}
	int Size();
	T at(int index);
	int sumbyte();
	 T& operator[](int index);
	friend bool operator==(ARRAY1D a, ARRAY1D b);
	friend bool operator!=(ARRAY1D a, ARRAY1D b);
	void Add(T item);
	void Resize(int newsize);
	void Insert(const int index , T value, int count = 1);
	void Erase(const int index);
	void Erase(const int start, const int end);
	void Reverse();
	void Clear();
};

template <class T>
T  ARRAY1D<T>::at(int index)
{
	return a[index];
}

template <class T>
T& ARRAY1D<T>::operator[]( int index)
{
	return this->at(index);
}

template <class T>
int ARRAY1D<T>::sumbyte()
{
	return size * sizeof(T);
}

template <class T>
int ARRAY1D<T>::Size()
{
	return size;
}
template <class T>
void ARRAY1D<T>::Add(T x)
{
	a = (T*)realloc(a, ++size * sizeof(T));
	a[size - 1] = x;
}

template <class T>
void ARRAY1D<T>::Resize(int newsize)
{
    a = (T*)realloc(a, newsize * sizeof(T));
	size = newsize;
}

template <class T>
bool operator==(ARRAY1D<T> x, ARRAY1D<T> y) 
{
	for(int i = 0; i < x.size; i++)
	{
		if(x.at(i) != y.at(i))
			return false;
	}
	return true;
}
template <class T>
bool operator!=(ARRAY1D<T> x, ARRAY1D<T> y) 
{
	return !(x == y);
}
template <class T>
void ARRAY1D<T>::Insert(const int index ,T value, int count = 1)
{
	int i = 0;
	while(i < count)
	{
	  a = (T*)realloc(a, ++size * sizeof(T));
	  for(int i = size - 1; i > index; i--)
	  {
		  a[i] = a[i - 1];
	  }
	  a[index] = value;
	  i++;
	}
}
template <class T>
void ARRAY1D<T>::Erase(const int index)
{
	for(int i = index; i < size - 1; i++)
	  {
		  a[i] = a[i + 1];
	  }
	a = (T*)realloc(a, (--size) * sizeof(T));
}
template <class T>
void ARRAY1D<T>::Erase(const int start, const int end)
{
	int n = end - start + 1;
	for(int i = 0 ; i < n ; i++)
	{
		Erase(start);
	}
}
template <class T>
void ARRAY1D<T>::Reverse()
{
	for(int i = 0; i < size / 2; i++)
	{
		T temp = a[i];
		a[i] = a[size - 1 - i];
		a[size - 1 - i] = temp;
	}
}

template <class T>
void ARRAY1D<T>::Clear()
{
	while(size != 0)
	{
		Erase(0);
	}
	a = NULL;
}