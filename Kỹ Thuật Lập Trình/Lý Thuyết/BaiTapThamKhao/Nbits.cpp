#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <string.h>

int a[100];
int n = 3;

void printArray() {
	int i;
	for (i = 0; i < n; i++)
		printf("%d", a[i]);
	printf("\n");
}

void binaryStrings(int m) {
	if (m < 0) {
		printArray();
	} 
	else {
		a[m] = 0;
		binaryStrings(m-1);
		a[m] = 1;
		binaryStrings(m-1);
	}
}

int main() {
	binaryStrings(n-1);
	getch();
	return 0;
}
