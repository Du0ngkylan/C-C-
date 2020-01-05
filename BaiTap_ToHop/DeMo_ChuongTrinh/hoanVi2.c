/*
	sinh tat ca cac hoan vi cua n phan tu
	+ xay dung bang chi so cua thuat toan de quy
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int array[100][100];
int count;

void swap(int a[], int i, int j);
void khoitao(int n);
void inKetQua(int n);
void inMang(int a[], int n);
void lietKe(int a[], int n, int k);
void tinhChiSo(int a[], int n);

void swap(int a[], int i, int j) {
	int c;
	c = a[i];
	a[i] = a[j];
	a[j] = c;
}

void khoitao(int n) {
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			array[i][j] = 0;
	for (i = 1; i <= n; i++)
		array[i][i] = i;

	array[1][1] = 1;
	array[2][1] = 1;
	array[3][1] = 1;
	array[3][2] = 1;
//	array[4][1] = 1;
//	array[4][2] = 2;
//	array[4][3] = 3;
//	array[5][1] = 3;
//	array[5][2] = 1;
//	array[5][3] = 3;
//	array[5][4] = 1;

}

void inKetQua(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++)
			printf("%d ", array[i][j]);
		puts("");
	}
}

void inMang(int a[], int n) {
	int i;
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	puts("");
}

void lietKe(int a[], int n, int k) {
	if (k == 1) {
//		Neu in bang chi so thi k can
//		printf("%d: ", ++count);
//		inMang(a, n - 1);
		return;
	} else {
		int i;
		for (i = 1; i <= k; i++) {
			lietKe(a, n, k - 1);
			swap(a, array[k][i], k);
		}
	}
}

void tinhChiSo(int a[], int n) {
	int i, j, k;

	khoitao(n);
	for (i = 4; i <= n; i++) {
		// sau khi sinh xong mot hang cua bang chi so thi dat lai mang theo thu tu ban dau
		for (j = 1; j <= n; j++)
			a[j] = j;

		for (k = 1; k < i; k++) {
			lietKe(a, n, i - 1);
			for (j = 1; j < i; j++)
				if (a[j] == a[i] - 1)
					break;
			swap(a, i, j);
			array[i][k] = j;
		}
	}
}

int main() {
//	setvbuf(stdout, NULL, _IONBF, 0);
	int a[100];
	int n = 20;
	int j;
	
	for(j = 0; j<n; j++)
		a[j] = j;
	count = 0;
	khoitao(n);
	
	// sinh bang chi so gom n hang
	tinhChiSo(a, n);
	puts("bang chi so:\n");
	inKetQua(n);
	
	// sinh cac hoan vi cua n-1 phan tu
//	count = 0;
//	for (j = 1; j <= n; j++)
//		a[j] = j;
//	printf("\n\ncac hoan vi cua %d phan tu: \n\n", n-1);
//	lietKe(a, n, n - 1);
	
	getch();
	return 0;
}
