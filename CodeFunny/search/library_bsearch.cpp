// void *bsearch(const void *key, const void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
// Tham số
// key: Đây là con trỏ tới đối tượng mà đóng vai trò như là key để tìm kiếm, được ép kiểu dưới dạng một void*.
// base : Đây là con trỏ tới đối tượng đầu tiên của mảng, nơi cuộc tìm kiếm được thực hiện, được ép kiểu dưới dạng một void*.
// nitems: Đây là số phần tử trong mảng được trỏ tới bởi base.
// size: Đây là kích cỡ (giá trị byte) của mỗi phần tử trong mảng.
// compare: Đây là hàm để so sánh hai phần tử.

#include <iostream>
using namespace std;

int comparator(const void *a, const void *b){
  return (*(int *)a - *(int *)b);
}

int main(){
  int array[] = {1, 2, 5, 7, 12, 19, 22};
  int key = 22;
  int nitems = sizeof(array) / sizeof(array[0]);
  int size = sizeof(array[0]);
  int *result = (int *)bsearch(&key, array, nitems, size, comparator);

  if (result != NULL){
    cout << *result << " is found in the array.\n";       
  } else {
    cout << key << " is not found in the array.\n";
  }
  
  return 0;
}
