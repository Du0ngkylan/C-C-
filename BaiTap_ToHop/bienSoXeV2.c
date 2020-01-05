/*
 * bienSoXeV2.c
 *
 *  Created on: Aug 12, 2013
 *      Author: BlueWhale
 */

/*
 * Yeu cau: sinh cac bien so xe co n+1 ki tu
 * trong do ki tu dau tien la mot chu cai tu 'A' den 'Z'
 * n ki tu tiep theo la cac chu so co the giong nhau
 */

#include<stdio.h>
#include<stdlib.h>

int n = 4; //So chu so trong bien so xe
char chuCai; //Chu cai dau tien trong bien so xe
int chuSo[30]; //Cac chu so trong bien so xe,
				//do so chu so n co the lon nen minh
				//khoi tao mang co kich thuoc 30
int soBienSo = 0; //So bien so xe

//Ham in bien so xe
void inBS() {
	printf("\n");
	printf("%c", chuCai); //in chu cai dau tien
	//In cac chu so tiep theo
	int j;
	for (j = 0; j < n; j++) {
		printf("%d", chuSo[j]);
	}
}

//Sinh chu so thu i trong bien so
void sinhChuSo(int i) {
	if (i == n) { //Neu i = n nghia la ta da sinh du n chu so
		soBienSo++; //Tang so bien so len 1
		inBS(); //In bien so xe ra
	} else { //Trai lai ta gan cac gia tri co the cho chu so thu i
		for (chuSo[i] = 0; chuSo[i] <= 9; chuSo[i]++) {
			sinhChuSo(i + 1);
		}
	}
}

int main() {
	setbuf(stdout, NULL);

	for (chuCai = 'A'; chuCai <= 'Z'; chuCai++) { //Cac gia tri co the cua chu cai dau tien
		sinhChuSo(0); //Voi moi gia tri cua chu cai,
					  //bat dau bang viec sinh chu so dau tien (chuSo[0]).
	}
	printf("\nSo bien so la %d", soBienSo);
	return 0;
}


