#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <string.h>

int a[100];
int n = 4;
int k = 2;

void printArray() {
	int i;
	for (i = 0; i < n; i++)
		printf("%d", a[i]);
	printf("\n");
}

void karyStrings(int m) {
	if (m < 0) {
		printArray();
	} 
	else {
		int i = 0;
		for (i = 0; i < k; i++) {
			a[m] = i;
			karyStrings(m-1);
		}
	}
}

int main() {
	karyStrings(n-1);
	getch();
	return 0;
}

