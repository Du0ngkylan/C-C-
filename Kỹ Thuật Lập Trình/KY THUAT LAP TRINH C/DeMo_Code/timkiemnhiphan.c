#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int n, a[50];

void nhapmang() {
	int i;
	for (i = 0; i < n; i++) {
		printf("a[%d]=", i + 1);
		scanf("%d", &a[i]);
	}
}

void inmang() {
	int i;
	for (i = 0; i < n; i++) {
		printf("%5d", a[i]);
//		printf("/n");
	}
}

void shiftElement(int i) {
	int iValue = a[i];
	while ((i > 0) && (a[i - 1] > iValue)) {
		a[i] = a[i - 1];
		i--;
	}
	a[i] = iValue;
}

void insertionSort() {
	int i;
	for (i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			shiftElement(i);
		}
	}
}
int comparator(const void *a, const void *b) {
	if (*(int*) a > *(int*) b) {
		return 1;
	}
	if (*(int*) a == *(int*) b) {
		return 0;
	}
	if (*(int*) a < *(int*) b) {
		return -1;
	}
}
int* binarySearch(int *a, int n, int value) {
	int i, j, m;
	i = 0;
	j = n - 1;
	while (i <= j) {
		m = (i + j) / 2;
		if (a[m] == value) {
			printf("phan tu thu %d",m);
			return a + m;
		} else {
			if (a[m] < value) {
				i = m + 1;
			} else {
				j = m - 1;
			}
		}
	}
	return NULL;
}
int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
//		int *a,n;
	int *tg;
	printf("nhap phan tu n=");
	scanf("%d", &n);
	nhapmang();
	inmang();
	puts("");
	insertionSort();
	inmang();
	int value = 6;
	tg = binarySearch(a, n, value);
	int *result = (int*) bsearch(&value, a, n, sizeof(int), comparator);
	if (result != NULL) {
		printf("\n%d is found in the array.\n", *result);
	} else {
		printf("\n%d is not found in the array.\n", *result);
	}
	return 0;
}

