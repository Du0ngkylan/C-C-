/*
 * xepHau.c
 *
 *  Created on: Aug 12, 2013
 *      Author: BlueWhale
 */

/*
 * Cho ban co kich thuoc nxn,
 * hay xep n quan hau len do sao cho
 * khong co hai quan hau nao an lan nhau
 */

#include<stdio.h>
#include<stdlib.h>

int n = 8; //So quan hau va cung la kich thuoc ban co nxn
int hang[30]; //Chi so hang cua cac quan hau
int cot[30]; //Chi so cot cua cac quan hau
int soCachXep = 0; //So cach xep hau

//Ham in cach xep hau. Quan hau thu i duoc dang trung
//boi vi tri hang hang[i] ca cot cot[i]
void inCachXep() {
	printf("\n");
	int j;
	for (j = 0; j < n; j++) {
		printf("(%d,%d)", hang[j], cot[j]);
	}
}

//Kiem tra xem quan hau thu i co khac cot voi cac quan hau dung truoc no
//hay khong
int kiemTraKhacCot(int i) {
	int j;
	for (j = 0; j < i; j++) {
		if (cot[j] == cot[i]) {
			return 0;
		}
	}
	return 1;
}

//Kiem tra xem quan hau thu i co khac duong cheo voi cac quan hau
//dung truoc no hay khong
//Chu y: quan hau i o vi tri (hang[i],cot[i]) va quan hau j
//o vi tri (hang[j],cot[j]) cung nam tren mot duong cheo neu
//|hang[i]-hang[j]| = |cot[i]-cot[j]|
int kiemTraKhacDuongCheo(int i) {
	int j;
	int hieuHang;
	int hieuCot;
	for (j = 0; j < i; j++) {
		hieuHang = hang[i] - hang[j];
		hieuCot = cot[i] - cot[j];
		if ((hieuHang == hieuCot) || (hieuHang == -hieuCot)) {
			return 0;
		}
	}
	return 1;
}

//Tim cot de dat quan hau o hang thu i
void datHauVaoCot(int i) {
	if (i == n) { //Neu dieu kien if thoa man la ta da xep du n quan hau
		soCachXep++;
		inCachXep();
	} else {
		for (cot[i] = 0; cot[i] < n; cot[i]++) { //Dat quan hau thu i vao cac cot khac nhau
			if ((kiemTraKhacCot(i) == 1) && (kiemTraKhacDuongCheo(i) == 1)) { //Kiem tra xem cot vua dat co thoa man khong bi quan hau khac an hay khong
				datHauVaoCot(i + 1);
			}
		}
	}
}

int main() {
	setbuf(stdout, NULL);

	int j;
	//Ban dau gan cac quan hau theo thu tu hang
	for (j = 0; j < n; j++) {
		hang[j] = j;
	}
	datHauVaoCot(0);
	printf("\nSo cach xep la %d", soCachXep);

	return 0;
}

