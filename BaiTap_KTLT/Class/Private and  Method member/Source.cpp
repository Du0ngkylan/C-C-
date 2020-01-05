#include <iostream>
#include <string>
using namespace std;
//Lớp(class): là 1 khuôn mẫu để từ khuôn mẫu đó ta có thể tạo ra các đối tượng từ lớp đó.
//	VD: Lớp Xe, Person, HocSinh, NhanVien.
//
//Đối tượng(object): Là 1 thể hiện của 1 lớp nào đó.
//VD: Học sinh có mã số 114 là 1 đối tượng của class HocSinh , con mèo Catok là đối tượng của lớp Mèo.

//4 tính chất của OOP:
//+ Tính đóng gói
//+ Tính trừu tính
//+ Tính kế thừa
//+ Tính đa hình

// Từ khóa phạm vi trong class
//- private: Khi khai báo thuộc tính hay phương thức có phạm vi là private. Thì 
//	những thuộc tính này sẽ được đóng gói trong class. Ta chỉ có thể sử dụng được nếu đang ở trong 
//	phạm vị của class ( tức là trong dấu { } )
//- public: Là từ khóa thể hiện sự chia sẽ ra ngoài. Những phương thức hay thuộc tính ở phạm vi 
// public thì sẽ có thể sử dụng bên ngoài dấu { } của class.


/* Có 3 dạng PT khởi tạo:
- Phương thức khởi tạo mặc định , PT này ko có tham số.
- Phướng thức khởi tạo có truyền tham số, PT này sẽ có tham số. 
- Phương thức khởi tạo sao chép, PT này có 1 tham số là 1 đối tượng của class đó luôn. Mục đích là gán đối tượng này qua
đối tượng khác.
*/

/* Hàm bạn là 1 hàm trong lớp đó nhưng ko phải là hàm thành viên của lớp đó. Hàm bạn có khả năng truy xuất được đến các
thuộc tính trong phạm vi private của lớp đó. 

CÚ PHÁP: khai báo hàm như bt nhưng  thêm từ khóa friend trước .

Lớp bạn là 1 lớp mà trong đó các phương thức của lớp bạn này có thể truy xuất đến các thuộc tinh, phương thức của lớp mà nó coi
là bạn cho dù ở phạm vị private.

VD: Khai báo class A là bạn của class B
class B
{
   friend class A;
}


CÚ PHÁP: 

*/
class HocSinh 
{
	// Khai báo thuộc tính
private:
	string ID, HoTen;
	float* DiemTB;
	// Khai báo các phương thức
public:
	float GetDTB()  const;
	void SetDTB(float );
	void Nhap();
	void Xuat();
	// Phương thức khởi tạo (Constructor) và phương thức hủy (Destructor)
	
	HocSinh()   // PT khởi tạo mặc định (Default Constructor)
	{
		DiemTB = new float();
		ID = "0";
		HoTen = "Chua Co";
		DiemTB = 0;
	}
	HocSinh(const string id,const string ht,const float dtb)
	{
		DiemTB = new float();
		ID = id;
		HoTen = ht;
		*DiemTB = dtb;
	}
	HocSinh(const HocSinh& x)
	{
		this->ID = x.ID;
		this->HoTen = x.HoTen;
		DiemTB = new float();
		*(this->DiemTB) = *(x.DiemTB);       // Con trỏ trỏ tới con trỏ
	}
};

float HocSinh::GetDTB() const
{
	return *(DiemTB);
}
void HocSinh::SetDTB(float newdtb)
{
	*(this->DiemTB) = newdtb;
}
void HocSinh::Nhap()
{
	cout<<"Nhap ID:\n";
	cin>>ID;
	fflush(stdin);
	cout<<"Nhap Ho Ten:\n";
	getline(cin, HoTen);
	do 
	{
		cout<<"Nhap diem tb:\n";
		cin>>*(this->DiemTB);
		if(DiemTB < 0)
			cout<<"Diem tb ko hop le. Nhap lai!\n";
	}while(DiemTB < 0);
}

void HocSinh::Xuat()
{
	cout<<endl<<"ID: "<<this->ID<<endl;
	cout<<"Ho ten: "<<this->HoTen<<endl;
	cout<<"Diem tb : "<<*(this->DiemTB)<<endl;
}

void main()
{
	HocSinh b("12","Tuan",5);
	HocSinh* a = new HocSinh(b); // khai báo con trỏ đối tượng a của class HocSinh
	//a->Nhap();
	a->Xuat();

	b.SetDTB(10);
	a->Xuat();
	delete a;
	system("pause");
}