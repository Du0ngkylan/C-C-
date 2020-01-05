#include <stdio.h>
#include <conio.h>
#include <Windows.h>   
#include <math.h>
void main()
{
	system("color 1f");
	// Bài 6
	//int namsinh;
	//printf("Nhap nam sinh cua ban:\n");
	//scanf("%d",&namsinh);
	//if(namsinh < 0)
	//	exit(0);         // Hàm thoát luôn CT
	//int tuoi = 2015 - namsinh;
	//printf("tuoi cua ban la %d",tuoi);


	// Bài 8
	/*int soluong, dongia;
	printf("Nhap vao so luong va don gia:\n");
	scanf("%d%d",&soluong, &dongia);

	if(soluong < 0 || dongia < 0)
		return;
    int tien = soluong * dongia;
	float thue = tien * 0.1;
	printf("Tien la %d, thue la %.3f",tien,thue);*/

	// Bài 10
	/*const double PI = 3.1415;
	float r;
	printf("Nhap ban kinh:\n");
	scanf("%f",&r);
	float chuvi = 2 * PI * r;
	float dientich = 2 * pow(r , 2);
	printf("Chu vi  = %.2f, dien tich = %.2f",chuvi, dientich);*/

	//Bài 11
	int soxe = 65189;
	int tong = 0;
        tong += soxe % 10;       // tong = 5
        soxe /= 10;                 // tong = 12345 / 10 = 1234
        tong += soxe % 10;       // tong = 9 ,
        soxe /= 10;
		tong += soxe % 10;
        soxe /= 10;   
		tong += soxe % 10;
        soxe /= 10;   
		tong += soxe % 10;
        soxe /= 10;   

		// tong = 29
	printf("so xe cua ban la %d",tong % 10);
	getch();  
}