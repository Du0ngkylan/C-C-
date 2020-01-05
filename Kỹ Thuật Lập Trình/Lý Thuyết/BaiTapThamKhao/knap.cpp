#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <string.h>

int a[100];

int s[] = {2,4,3,5};
int n = 3;

void printArray()
{
	for(int i =0; i<=n; i++)
		printf("%d", a[i]);
	printf("\n");	
}

void knapsack(int m, int t) {
	if (m < 0) {
		if (t == 0)
			printArray();
	} else {
		a[m] = 0;
		knapsack(m-1, t);
		if (s[m] <= t) {
			a[m] = 1;
			knapsack(m-1, t-s[m]);
		}
	}
}

int main() {
	knapsack(n, 6);
	getch();
	return 0;
}
