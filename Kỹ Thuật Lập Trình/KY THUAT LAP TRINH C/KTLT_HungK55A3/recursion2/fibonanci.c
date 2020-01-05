/*
 * fibonanci.c
 *
 *  Created on: Aug 6, 2013
 *      Author: hung
 */

#include <stdio.h>
#include<stdlib.h>
#include <conio.h>

int fib(int k){
	if(k<2){
		return k;
	}
	else{
		return fib(k-2)+fib(k-1);
	}
}



int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	int n,kq;
	printf("nhap vao so n: \n");scanf("%d",&n);
	kq=fib(n);
	printf("kq= %d",kq);
	return 0;
}
