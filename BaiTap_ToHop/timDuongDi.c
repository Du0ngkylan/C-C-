/*
 * Tim so duong di tu o tren cung goc ben trai den o duoi cung goc ben phai
 * trong mot hinh chu nhat co kich thuoc nxm
 */

#include<stdio.h>
#include<stdlib.h>

int n, m; //kich thuoc cua bang hinh chu nhat
int count = 0; //So duong di

//Do duong tu vi tri (i, j)
void doDuong(int i, int j) {
	if ((i == n) || (j == m)) { //Neu i = n chung to dang o hang cuoi cung, luc do chi
							    //con cach re phai mot mach cho toi dich
								//Neu j = m chung to dang o cot cuoi cung, luc do chi
								//con cach di xuong cho toi khi den dich.
		count++;
	} else {
		doDuong(i + 1, j); //Di xuong
		doDuong(i, j + 1); //Sang phai
	}
}

int main() {
	//Nhap kich thuoc cua hinh chu nhat
	printf("n = ");
	scanf("%d", &n);
	printf("m = ");
	scanf("%d", &m);
	//Bat dau do duong di tu o (1,1)
	doDuong(1, 1);
	//In so duong di
	printf("So duong di la %d", count);

	return 0;
}
