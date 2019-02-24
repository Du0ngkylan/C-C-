// Bai 25: Viet chuong trinh nhap vao 2 so nguyen duong a va b.
// Tim uoc so chung lon nhat va boi so chung nho nhat cua a va b.

//=================================================================================


#include <iostream>
using namespace std;

int main() {
  unsigned int i, a, b, c, d;
  cout << "Nhap a: "; cin >> a;
  cout << "Nhap b: "; cin >> b;
  c = a;
  d = b;
  while (b != a) {
    if (a > b)
      a = a - b;
    else
      b = b - a;

    i = (c*d)/a;
  }
  cout << "USCLN cua a va b la: " << a << endl;
  cout << "BSCNN cua a va b la: " << i;
  cout << endl;
}
