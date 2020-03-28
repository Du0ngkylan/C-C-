/*
 * Yeu cau: so Fibonacci thoa man tinh chat sau:
 * lim(n->oo) F_(n+1)/F_n = phi, voi phi = (1+sqrt(5))/2.
 * tinh chat tren tuong duong voi cong thuc sau:
 * cho so epsilon bat ki thi: |F_(n+1)/F_n - phi| <= epsilon, voi moi n >= N nao do.
 * 1/ Tim so N nho nhat thoa man cong thuc tre
 * 2/ Kiem tra xem cong thuc co dung voi n1 <= n <= n2 voi n1, n2 la
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float epsilon;
float phi;

//Ham tinh so Fibonacci thu n
int fib(int n) {
	if (n < 2) //Neu n < 2 ta co F_0 = 0, F_1 = 1 nghia la F_n = n voi n < 2.
		return n;
	else {
		return (fib(n - 1) + fib(n - 2));
	}
}

//Ham nhap so epsilon tu ban phim
void nhap() {
	printf("Nhap so epsilon: ");
	scanf("%f", &epsilon);
}

//Ham tinh |a/b - phi|
float tinh(int a, int b) {
	float kq = a/((float)b) - phi; //Phai chuyen a hoac b ve dang float
								   //thi phep tinh a/b moi chinh xac.
								   //Vi du: neu khong chuyen ve dang float thi
								   //phep chia 5/2 se bang 2.0
								   //trong khi do, neu chuyen ve dang float:
								   //5.0 / 2 = 5 / 2.0 = 5.0 / 2.0 = 2.5
	if (kq >= 0) {
		return kq;
	} else {
		return -kq;
	}
}

//Ham tim so N nho nhat thoa man cong thuc:
//|F_(n+1)/F_n - phi| <= epsilon, voi moi n >= N
int timNNhoNhat(float epsilon) {
	int n = 2;
	while (tinh(fib(n), fib(n-1)) > epsilon) {
		n++;
	}
	return n;
}

//Ham nhap 2 so n1 va n2 tu ban phim, sau do kiem tra:
//Cong thuc |F_(n+1)/F_n - phi| <= epsilon co dung voi n1 <= n <= n2 hay khong
void kiemTra() {
	int n1, n2;
	printf("\nNhap hai so n1 va n2:\n");
	printf("n1 = ");
	scanf("%d", &n1);
	printf("n2 = ");
	scanf("%d", &n2);
	int n;
	for (n = n1; n <= n2; n++) {
		if (tinh(fib(n), fib(n - 1)) > epsilon) {
			printf("Cong thuc khong thoa man voi %d <= n <= %d", n1, n2);
			return;
		}
	}
	printf("Cong thuc thoa man voi %d <= n <= %d", n1, n2);
}

int main() {
	phi = (1+sqrt(5.0))/2;
	nhap();
	printf("So N nho nhat thoa man la %d", timNNhoNhat(epsilon));

	kiemTra();

	return 0;
}

