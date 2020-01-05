#include <stdio.h>
#include <conio.h>
#include <math.h>       // Thư viện toán học
void main()
{
	////Hàm pow để tính lũy thừa
	/*int x = 2;
	printf("x^3 = %.1f",pow((float)x, 3));*/
	////Hàm sqrt để tính căn bậc 2
	/*int a = 9;
	printf("can bac 2 cua %d la %lf",a,sqrt(double(a)));*/
	// Hàm abs để lấy trị tuyệt đối của 1 số nguyên
	/*int a = -8;
	a = abs(a);
	printf("a = %d",a);*/
	// fabs để láy trị tuyệt đối của số thực

	//log là logarit cơ số e <=> ln
	
	float x = 3.56;
	x = ceil(x); // x = 4
	//printf("x = %f",x);
	//x = floor(x); // x = 3
	printf("x = %f",x);
	getch();
}