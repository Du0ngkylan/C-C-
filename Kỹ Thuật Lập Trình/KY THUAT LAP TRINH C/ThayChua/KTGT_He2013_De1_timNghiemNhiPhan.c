/*
 * timNghiemNhiPhan.c
 *
 *  Created on: Aug 13, 2013
 *      Author: BlueWhale
 */

/*
 * Cho phuong trinh sau: f(x) = x^4+3*x^3+x-6 = 0
 * Hay tim nghiem cua phuong trinh tren doan [a,b] voi a,b nhap tu ban phim
 * thoa man |f(x)| < epsilon voi
 * epsilon nhap tu ban phim
 * tim nghiem bang phuong phap chia doi khoang
 */

#include<stdio.h>
#include<stdlib.h>

float epsilon; //Do chinh xac cua ham f(x) so voi 0
float a, b; //Khoang tim nghiem [a, b]

//Ham tinh f(x) = x^4+3*x^3+x-6
float tinh_f(float x) {
	return (x * x * x * x + 3 * x * x * x + x - 6 );
}

//Ham nhap epsilon, a, b
void nhap() {
	printf("Nhap sai so epsilon = ");
	scanf("%f", &epsilon);
	do {
		printf("Nhap a, b sao cho f(a)*f(b) <= 0 \n");
		printf("a = ");
		scanf("%f", &a);
		printf("b = ");
		scanf("%f", &b);
	} while (tinh_f(a) * tinh_f(b) > 0); //Nhap a, b cho den khi nao f(a)*f(b) <= 0
}

//Ham tim nghiem tren khoang [a, b]
float timNghiem(float a, float b){
	float mid; //Diem chia doi khoang tim nghiem
	int thoaMan = 0; //neu thoaMan = 1 la da tim thay nghiem
	while (thoaMan == 0) { //Trong khi chua tim thay nghiem
		mid = (a + b) / 2; //Diem chia doi khoang tim kiem
		if ((-epsilon <= tinh_f(mid)) && (tinh_f(mid) <= epsilon)) { //Neu
																	// |f(mid)| <= epsilon
																	// ta cong nhan mid
																	// la nghiem can tim
			thoaMan = 1;
		} else {
			if (tinh_f(a) * tinh_f(mid) <= 0) { //Neu f(a)*f(mid) <= 0 chung to nghiem
												//nam tren doan [a, mid]
				b = mid;
			} else { //trai lai nghiem nam tren doan [mid, b]
				a = mid;
			}
		}
	}
	return mid;

}

int main() {
	setbuf(stdout, NULL);

	nhap();
	printf("Nghiem cua bai toan la %f", timNghiem(a, b));

	return 0;
}
