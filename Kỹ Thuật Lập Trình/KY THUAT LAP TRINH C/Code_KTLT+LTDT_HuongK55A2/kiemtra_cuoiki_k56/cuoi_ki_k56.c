/*
 * cuoi_ki_k56.c
 *
 *  Created on: Jan 13, 2013
 *      Author: NgoHuong
 */

#include <stdio.h>
int n, m;

int duongdi(int i, int j)
{
	if ( i == n || j == m)
		return 1;
	else
		duongdi(i+1, j) + duongdi(i, j+1);
}

/*int duongdi(int m, int n)
{
	if (m+1 <= n || n+1<= m)
		return 1;
	else
		duongdi(m+1, n) + duongdi(m, n+1);
}*/
int main()
{
	setbuf(stdout, NULL);
	printf("m = ");
	scanf("%d", &m);
	printf("n = ");
	scanf("%d", &n);
	int k = duongdi(m, n);
	//if (k!=1)
	    printf("duong di la:%d", k);
	return 0;
}
