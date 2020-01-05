/*
 * bublesortarray.c
 *
 *  Created on: Jul 15, 2013
 *      Author: hung
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void nhapmang(int n,int a[]){
	int i;
	for(i=0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);
	}
}

void inmang(int n,int a[]){
	int i;
	for(i=0;i<n;i++){
		printf("%2d",a[i]);
	}
	puts("");
}

void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void bubblesort(int n,int a[]){
	int i,j;
	for(i=(n-1);i>0;i--){
		for(j=1;j<=i;j++){
			if(a[j-1]>a[j]){
				swap(&a[j-1],&a[j]);
			}
		}
	}
}

int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	int a[100],n;
	printf("nhap vao so phan tu cua mang: ");scanf("%d",&n);
	nhapmang(n,a);
	inmang(n,a);
	bubblesort(n,a);
	inmang(n,a);
	return 0;
}
