#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <string.h>

void swap(char a[], int i, int j) {
	char c;
	c = a[i];
	a[i] = a[j];
	a[j] = c;
}

void enumerate(char a[], int n) {
	int i;
	if (n == 0)
	{
		for(int k = 0; k<strlen(a); k++)
			printf("%c", a[k]);
		printf("\n");
	}
	else {
		for (i = 0; i < n; i++) {
			swap(a, i, n - 1);
			enumerate(a, n - 1);
			swap(a, i, n - 1);
		}
	}
}

int main() {
	char a[] = "abcde";
	enumerate(a, 5);
	getch();
	return 0;
}
