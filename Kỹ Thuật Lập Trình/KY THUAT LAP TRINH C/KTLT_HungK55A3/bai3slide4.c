/*
 * bai3.c
 *
 *  Created on: Aug 12, 2013
 *      Author: VuHuuHanh
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f(int n) {
	if (n <= 1)
		return n;
	else
		return f(n - 1) + f(n - 2);
}
float abs1(float x) {
	if (x >= 0)
		return x;
	else
		return -x;
}

int main(int argc, char **argv) {
	setbuf(stdout, NULL);
	float esp;
	printf("nhap esp: ");
	scanf("%f", &esp);
	int n = 1;
	float lim = (1 + sqrt(5)) / 2;
	while(abs1(f(n+1)/(float)f(n)-lim)>=esp) {
		n++;
	}
	printf("f(%d)=%d\n", n+1, f(n + 1));
	printf("f(%d)=%d\n", n, f(n));
	printf("f(%d+1)/f(%d)-%f=%f<%f", n, n,lim, (f(n + 1) / (float) f(n)) - lim,esp);
	return 0;
}

