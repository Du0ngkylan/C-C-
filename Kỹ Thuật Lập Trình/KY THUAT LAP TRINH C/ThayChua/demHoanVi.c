/*
 * demHoanVi.c
 *
 *  Created on: Aug 12, 2013
 *      Author: BlueWhale
 */

/* Yeu cau: nhap so phan tu n tu ban phim
 * sinh ra cac hoan vi n phan tu
 * va in cac hoan vi nay ra
 */

#include<stdio.h>
#include<stdlib.h>

int n; //So phan tu cua hoan vi
int a[50]; //Day luu lai hoan vi.
		   //Do dung mang nen minh dat la
		   //kich thuoc mang 50 phan tu de phong n nhap vao lon,
		   //vi du n = 49. :D
int soHV = 0; //bien dem so hoan vi

//Nhap n la so phan tu cua hoan vi
void nhap() {
	printf("Nhap so phan tu cua hoan vi: ");
	scanf("%d", &n);
}

//Kiem tra phan tu thu i co khac voi cac phan tu
//dung truoc no
int kiemTraHopLe(int i) {
	int j;
	for (j = 0; j < i; j++) {
		if (a[j] == a[i]) {
			return 0; //Neu phan tu thu i bang phan tu j nao do
					 //thi tra lai gia tri 0 va thoat ra
		}
	}
	return 1; //Truong hop phan tu thu i khac voi tat cac phan tu
			  //dung truoc no thi tra lai gia tri 1
}

//Ham in cac phan tu cua mot hoan vi
void inHV() {
	printf("\n");
	int j;
	for (j = 0; j < n; j++) {
		printf("%3d", a[j]);
	}
}

//Ham de quy sinh phan tu thu i cua hoan vi
void sinhHV(int i) {
	if (i == n) { //Khi i = n chung to da sinh du n phan tu
		inHV();
		soHV++; //Tang so phan tu len 1 don vi
	} else {
		for (a[i] = 1; a[i] <= n; a[i]++) { //Gan lan luot cac gia tri co the cho
											//phan tu a[i]
			if (kiemTraHopLe(i) == 1) { /*Kiem tra tinh hop le cua gia tri duoc gan
										*bang cach xem no co trung voi phan tu nao
										*dung truoc no hay khong
										*/
				sinhHV(i + 1); //Neu hop le thi sinh tiep phan tu thu i+1
			}
		}
	}
}

int main() {
	setbuf(stdout, NULL);

	nhap(); //Dau tien la nhap so phan tu cua hoan vi
	sinhHV(0); //Goi chuong trinh de quy sinh cac phan tu
			   // bat dau bang phan tu dau tien (a[0])
	printf("\n So hoan vi la %d", soHV);

	return 0;
}
