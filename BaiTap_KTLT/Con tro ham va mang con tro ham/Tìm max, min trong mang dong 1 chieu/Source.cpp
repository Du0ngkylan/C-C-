#include <iostream>
#include <ctime>
#include <cmath>       // Thư viện toán học của C++
using namespace std;

void TaoNgauNhien(int* a, int n) {
	srand(time(0));
	for(int i = 0; i < n; i++) {
		a[i] = rand()% 50 + 0;
	}
}

void XuatMang(int* a, int n) {
	for(int i = 0; i < n; i++)
		cout<<a[i]<<"\t";
}

bool KiemTraLonHon(int x, int y) {
	return x > y;
}

bool KiemTraNhoHon(int x, int y) {
	return x < y;
}

int TimMaxOrMin(int* a, int n,bool (*p)(int, int)) {
	int M = a[0];
	for(int i = 1; i < n; i++) {
		if(p(a[i], M)) 
			M = a[i];
	}
	return M;
}

void HoanVi(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void SapXepTangOrGiam(int* a, int n, bool (*p)(int, int)) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(p(a[i], a[j]))
				HoanVi(a[i], a[j]);
		}
	}
}

// 1. Tính tổng các số nguyên tố
// 2. Tính tổng các số chính phương
// 3. Tính tổng các số có chữ số đầu là chữ số chẵn
bool KiemTraNguyenTo(int n)
{
	if(n < 2)
		return false;
	else if(n > 2)
	{
		if(n % 2 == 0)
			return false;
		else 
		{
			for(int i = 3; i <= (int)sqrt(n); i+= 2)
			{
				if(n % i == 0)
					return false;
			}
		}
	}
	return true;
}

bool KiemTraChinhPhuong(int n) {
	int canbac2 = sqrt(n);
	if(canbac2 * canbac2 == n)
		return true;
	return false;
}

bool KiemTraChuSoDauLaChan(int n) {
	int temp = n;
	while(temp >= 10) {
		temp /= 10;
	}
	return temp % 2 == 0;
}

int TongTuyChon(int* a, int n, bool (*p)(int)) {
	int tong = 0;
	for(int i = 0; i < n; i++) {
		if(p(a[i]) == true) {
			tong += a[i];
		}
	}
	return tong;
}

int main() {
	int n = 5;
	int* a = NULL;
	a = new int[n]; // Cấp phát 
	TaoNgauNhien(a, n);
	XuatMang(a,n);

	int Max = TimMaxOrMin(a, n, KiemTraLonHon );
	int Min = TimMaxOrMin(a, n, KiemTraNhoHon);
	cout<<endl<<"Max = "<<Max<<" , Min = "<<Min;
	SapXepTangOrGiam(a, n, KiemTraLonHon); // Sắp tăng dần
	cout<<endl;
	XuatMang(a,n);
	SapXepTangOrGiam(a, n, KiemTraNhoHon);
	cout<<endl;
	XuatMang(a,n);

	int TongNT = TongTuyChon(a, n, KiemTraNguyenTo);
	int TongCP = TongTuyChon(a, n, KiemTraChinhPhuong);
	int TongChuSoDauChan = TongTuyChon(a, n, KiemTraChuSoDauLaChan);
	cout<<endl<<"Tong so nguyen to = "<<TongNT<<endl;
	cout<<"Tong so chinh phuong = "<<TongCP<<endl;
	cout<<"Tong so co chu so dau la so chan = "<<TongChuSoDauChan <<endl;
	if( a != NULL)
		delete []a;
	system("pause");
	return 0;
}
//
//Hãy ứng dụng con trỏ cấp 1,con trỏ hàm để tùy biến mã nguồn CT sau.Qua đó ta có thể thấy sức mạnh của con trỏ hàm
//trong việc xây dựng mà nguỗn chất lượng, dễ bảo trì, code ngắn gọn.
//Trên mảng ''động'' 1 chiều với kiểu dữ liệu bất kỳ . Thực hiện các hàm sau:
//1/ Nhập , xuất mảng động
//2/ Tính tổng các số đối xứng trong mảng
//3/ Tính tổng các số dương trong mảng
//4/ Tính tổng các số âm trong mảng
//5/ Đếm các số nguyên tố trong mảng
//6/ Đếm các số đặc biệt trong mảng
//Số đặc biệt là số có tổng các chữ số lẻ = tổng các chữ số chẵn . VD số 2536 là số đặc biệt vì 2 + 6 = 5 + 3
//7/ Đếm các số có chữ số hàng chục là số lẻ
//8/ Tìm phần tử lớn nhất, nhỏ nhất
//9/ Xóa các số nguyên tố trong mảng
//10/ Xóa các số đặc biệt trong mảng
//11/ Sắp xếp các số chẵn tăng dần, số lẻ giảm dần
