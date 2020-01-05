/*
 * towerofhanoi.c
 *
 *  Created on: Aug 6, 2013
 *      Author: hung
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void towerofhanoi(int k,char a,char b,char c){
	if(k==1){
		printf("%c ===> %c\n",a,c);
	}
	else{
		towerofhanoi(k-1,a,c,b);
		towerofhanoi(1,a,' ',c);
		towerofhanoi(k-1,b,a,c);
	}
}


int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	int n;
	printf("nhap so dia ban dau: ");scanf("%d",&n);
	towerofhanoi(n,'A','B','C');
	return 0;
}
