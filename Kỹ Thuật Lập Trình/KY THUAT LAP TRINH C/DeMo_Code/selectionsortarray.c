/*
 * selectionsortarray.c
 *
 *  Created on: Jul 15, 2013
 *      Author: hung
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void nhapmang(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);
	}
}
void inmang(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%5d",a[i]);
	}
	puts("");
}
void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void selectionsort(int a[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(&a[i],&a[j]);
			}
		}
	}
}

int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	int a[100],n;
	printf("nhap vao so phan tu cua mang: ");scanf("%d",&n);
	nhapmang(a,n);
	inmang(a,n);
	selectionsort(a,n);
	inmang(a,n);
	return 0;
}
