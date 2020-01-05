/*
 * timkiemnhiphan.c
 *
 *  Created on: Sep 28, 2012
 *      Author: Student
 */
#include<stdio.h>
#include <conio.h>
#include <stdlib.h>

void nhapmang(int a[],int n);
void dichchuyen(int a[],int n);
void sapxep(int a[],int n);
int *tknp(int *a,int n,int t);

int main() {
	setvbuf(stdout,NULL,_IONBF,0);
	int n, i, t;
	printf("nhap so phan tu cua mang:\t");
	scanf("%d", &n);
	int *a;
	a = (int *) malloc(n * sizeof(int));
	nhapmang(a, n);
	int chon;
	do {
		printf("lua chon:\n");
		printf("1- sap xep:\n");
		printf("2- timkiem:\n");
		printf("3-ket thuc:\n");
		scanf("%d", &chon);
		switch (chon) {
		case 1:
			sapxep(a, n);
			printf("day moi la:\n");
			for (i = 0; i < n; i++) {
				printf("%d", a[i]);
			}
			break;
		case 2:
			printf("nhap phan tu can tk:\t");
			scanf("%d", &t);
			sapxep(a, n);
			if( tknp(a,n,t) == NULL ) {
				printf("Khong co\n");
			} else {
				printf("Co\n");
			}
			break;
		case 3:
			exit(0);
			break;
		}
	} while (chon > 0 && chon < 4);
	return 0;
}

void nhapmang(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("nhap phan tu thu %d:", i + 1);
		scanf("%d", &a[i]);
	}
}

void dichchuyen(int a[], int i) {
	int y = a[i];
	while ((i > 0) && a[i - 1] > y) {
		a[i] = a[i - 1];
		i--;
	}
	a[i] = y;
}

void sapxep(int a[], int n) {
	int i;
	for (i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			dichchuyen(a, i);
		}
	}
}

int *tknp(int *a, int n, int t) {
	int i, j, m;
	i = 0;
	j = n - 1;
	while (i < j) {
		m = (i  + j ) / 2;
		if (a[m] == t) {
			return a + m;
		} else {
			if (a[m] < t) {
				i = m + 1;
			} else {
				j = m - 1;
			}
		}
	}
	return NULL;
}

