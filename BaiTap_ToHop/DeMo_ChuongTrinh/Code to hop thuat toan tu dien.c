/*
 * 1-12.c
 *
 *  Created on: 23-09-2012
 *      Author: NQTUAN
 */
//Chuong trinh sinh cac hoan vi theo thu tu tu dien
#include <stdio.h>
#include <conio.h>

#define max 20

int P[max];
int n;
int j;
int i;
int Pt;

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Nhap n = "); scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		P[i] = i;
	}
	printf("\n");
	do {
		for (i = 1; i <= n; i++)
			printf("%2d", P[i]);
		printf("\n");
		j = n - 1;
		while (P[j] > P[j+1])
			j--;
		if (j > 0) {
			i = j + 1;
			while (P[i] > P[j])
				i++;
			Pt = P[j]; P[j] = P[i-1]; P[i-1] = Pt;
			j++; i = n;
			while (j < i) {
				Pt = P[j]; P[j] = P[i]; P[i] = Pt;
				j++;
				i--;
			}
		}
	} while (j > 0);
	getch();
	return 0;
}

/*
 * void nhap()
{
	FILE *f;

	f = fopen("input.txt", "r");
	if (f == NULL) {
		printf("Loi mo tep");
		getch();
		exit(0);
	}
	fscanf(f, "%d", &n);
	P = (int *)calloc(n+1, sizeof(int));
	fclose(f);
}



void doicho(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void in()
{
	int i;

	for (i = 1; i <= n; i++)
		printf("%d", P[i]);
	printf("\n");

}
 * */
