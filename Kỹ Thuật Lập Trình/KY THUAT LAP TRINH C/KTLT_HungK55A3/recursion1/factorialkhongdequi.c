/*
 * factorialkhongdequi.c
 *
 *  Created on: Aug 6, 2013
 *      Author: hung
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void factorial(int n){
	int i;
	int value=1;
	for(i=1;i<=n;i++){

		value=value*i;
	}
	printf("%d",value);
}


int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	int n;
	printf("nhap vao n: ");scanf("%d",&n);
	factorial(n);
	return 0;
}
