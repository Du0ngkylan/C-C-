#include<stdio.h>
#include <stdlib.h>
#include <conio.h>


int factorial(int n){
	if(n <= 0){
		return 1;
	}
	else{
		return factorial(n-1) * n;
	}
}

void factorial_1(int n){
	int value = 1;
	for(int i = 1; i <= n;i++){
		value=value*i;
	}
	printf("%d",value);
}

int fib(int k){
	if(k < 2){
		return k;
	} else{
		return fib(k - 2) + fib(k - 1);
	}
}

void towerofhanoi(int k, char a, char b, char c){
	if(k == 1){
		printf("%c ===> %c\n", a, c);
	}
	else{
		towerofhanoi(k-1, a, c, b);
		towerofhanoi(1, a,' ', c);
		towerofhanoi(k-1, b, a, c);
	}
}

int main(){
	int n,a;
	printf("nhap n: ");scanf("%d",&n);
	a = factorial(n);
	printf("n!= %d",a);
  printf("\nThap Ha Noi: \n");
  towerofhanoi(n,'A','B','C')
	return 0;
}