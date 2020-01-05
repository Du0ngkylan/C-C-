#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
void NhapSoNguyenDuong(int& n)
{
	do 
	{
	  printf("Nhap vao so nguyen duong:\n");
	  scanf_s("%d",&n);
	  if(n < 0)
		  printf("Yeu cau nhap so nguyen duong! Nhap lai\n");
	}while(n < 0);
}
int TimSoDaoNguoc(int n)
{
	int sodaonguoc = 0;
	int temp = n;
	while(temp != 0)
	{
		sodaonguoc = sodaonguoc * 10 + (temp % 10);
		temp /= 10;
	}
	return sodaonguoc;
}
bool KiemTraDoiXung(int n)
{
	if(n == TimSoDaoNguoc(n))
		return true;             // n là số đối xứng
	else 
		return false;
}
bool KiemTraSoChinhPhuong(int n)
{
	int canbac2 = sqrt((float)n);
	if(canbac2 * canbac2 == n) 
		return true;
	else
		return false;
}
bool KiemTraNguyenTo(int n)
{
	if(n < 2)        // Ko có số NT nào < 2
		return false;
	if(n > 2)     // Ngược lại nếu n > 2
	{
		if( n % 2 == 0)       // Các số NT ngoài số 2 ra thì ko có số nào là số chẵn nữa
			return false;
		else 
		{
			for(int i = 3; i <= (int) sqrt((float)n); i += 2)
			{
				if(n % i == 0)      // Vi phạm đk chỉ chia hết cho 1 và chính nó nên ko phải số NT
					return false;
			}
		}
	}
	return true;         // Ta để return true ở cuối hàm. Nếu ko rơi vào 3 cái return false thì nó sẽ return true
}
int TimChuSoMax(int n)
{
	int temp = n;
	int chusomax = n % 10;       // Khởi tạo chusomax là chữ số cuối
	while(temp != 0)
	{
		int chuso = temp % 10;
		if(chuso > chusomax)     // Phát hiện có chữ số khác lớn hơn chusomax thì cập nhật lai chusomax
			chusomax = chuso;
		temp /= 10;
	}
	return chusomax; 
}
int TimChuSoMin(int n)
{
	int temp = n;
	int chusomin = n % 10;       // Khởi tạo chusomax là chữ số cuối
	while(temp != 0)
	{
		int chuso = temp % 10;
		if(chuso < chusomin)     // Phát hiện có chữ số khác nhỏ hơn chusomax thì cập nhật lai chusomax
			chusomin = chuso;
		temp /= 10;
	}
	return chusomin; 
}
bool KiemTraChuSoTangDanHoacGiamDan(int n) 
{
	if(n / 10 == 0)     // Nếu n là số có 1 chữ số thì coi như ko phải nhé
		return false;         
	
	int chusocuoi = n % 10;
	n /= 10;
	int chusokecuoi = n % 10;
	bool checktangdan, checkgiamdan;
	if(chusokecuoi < chusocuoi) // Lúc này ta cần phải kiểm tra và đảm bảo rằng các chữ số phải là tăng dần
	{
		int temp = n;
		while(temp > 9)       // Chỉ chạy khi temp còn >= 2 chữ số
		{
			if((temp / 10) % 10 > temp % 10) //Nếu phát hiện chữ số đằng trước lớn hơn chữ số đằng sau thì vi phạm
				 return false;                             // nên ta kết thúc hàm và trả về false
              temp /= 10;
		}
		return true;     // Nếu ko vi phạm thì chắc chắn sẽ chạy vào dòng này và trả về true. Hiểu là chữ số thỏa tăng dần hoặc giảm dần
		                 // . Chi tiết trong trường hợp này thì nó tăng dần ^^
	}
	else if( chusokecuoi > chusocuoi) // Lúc này ta cần phải kiểm tra và đảm bảo rằng các chữ số phải là giảm dần
	{
		int temp = n;
		while(temp > 9)   // Chỉ chạy khi temp còn >= 2 chữ số
		{
			printf("\n%d\n%d",(temp / 10) % 10, temp % 10);
			if((temp / 10) % 10 < temp % 10) //Nếu phát hiện chữ số đằng trước nhỏ hơn chữ số đằng sau thì vi phạm
				 return false;                             // nên ta kết thúc hàm và trả về false
              temp /= 10;
		}
		return true;     // Nếu ko vi phạm thì chắc chắn sẽ chạy vào dòng này và trả về true. Hiểu là chữ số thỏa tăng dần hoặc giảm dần
		                 // . Chi tiết trong trường hợp này thì nó giảm dần ^^
	}
	return false;       // Cứ để mặc định return false ở đây nhé.
}
void main()
{
	// Tụi em chú ý viết cách ra như a cho code rõ ràng
	int chon;
	int n = 0;
	system("color 1f"); 
	do 
	{
		system("cls");
		printf("0. Thoat\n\n");
		printf("1. Nhap So Nguyen Duong\n\n");
		printf("2. Kiem Tra So Doi Xung\n\n");
		printf("3. Kiem Tra So Chinh Phuong\n\n");
		printf("4. Kiem Tra Nguyen To\n\n");
		printf("5. Tim Chu So Max, Min\n\n");
		printf("6. Kiem Tra Chu So Tang Dan Hoac Giam Dan\n\n");
		printf("Moi ban chon menu:\n");
		scanf_s("%d",&chon);
		switch (chon)
		{
		case 1: NhapSoNguyenDuong(n); break;
		case 2: 
			{
				if(KiemTraDoiXung(n) == true)
				{
					printf("%d la so doi xung", n);
				}
				else 
					printf("%d khong phai so doi xung",n);
				_getch();
				break;
			}
		case 3:
			{
				if(KiemTraSoChinhPhuong(n) == true)
					printf("%d la so chinh phuong",n);
				else 
					printf("%d khong phai so chinh phuong",n);
			   _getch();
			    break;
			}
		case 4:
			{
				if(KiemTraNguyenTo(n))          // Ko để == gì cả thì mặc định trình biên dịch hiểu if(KiemTraNguyenTo(n) == true) đó nhé. Như nhau cả
					printf("%d la so nguyen to", n);
				else 
					printf("%d khong phai so nguyen to",n);
				_getch();
				break;
			}
		case 5:
			{
				int Chusomax = TimChuSoMax(n); //Nếu hàm trả về giá trị thì ta có thể gán qua 1 biến cùng kiểu trả về :)
				int Chusomin = TimChuSoMin(n); 
				printf("Chu so max = %d, chu so min = %d",Chusomax, Chusomin);
				_getch();
				break;
			}
		case 6:
			{
				if(KiemTraChuSoTangDanHoacGiamDan(n))
				{
					printf("Cac chu so co tang dan hoac giam dan");
				}
				else 
					printf("NOT OK!");
				_getch();
				break;
			}
		}
	}while(chon != 0);
}
