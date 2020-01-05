/*
 * factorial.c
 *
 *  Created on: Aug 6, 2013
 *      Author: hung
 */

#include<stdio.h>
#include <stdlib.h>
#include <conio.h>


int factorial(int n){
	if(n<=0){
		return 1;
	}
	else{
		return factorial(n-1)*n;
	}
}



int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	int n,a;
	printf("nhap n: ");scanf("%d",&n);
	a=factorial(n);
	printf("n!= %d",a);
	return 0;
}
