/*
 * bubleSort.c
 *
 *  Created on: Jul 8, 2013
 *      Author: student
 */

#include<stdio.h>
void swap(int *x, int *y){
	int temp= *x;
	*x=*y;
	*y=temp;
}

void nhap_mang(int *a, int n){
	int i;
	for(i=0;i<n;i++){
		printf("a[%d]=\t",i);
		scanf("%d",a+i);
	}

}
void in_mang(int *a, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",*(a+i));
	}
}

void bubleSort(int *a, int n){
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(*(a+i)>*(a+j))
				swap(a+i,a+j);
}
int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	int *a, n;
	a = (int*) malloc (n* sizeof(int));
	printf("nhap n:\t");
	scanf("%d",&n);
	nhap_mang(a,n);
	printf("mang nhap vao la:\t");
	in_mang(a,n);
	bubleSort(a,n);
	printf("\nMang sau khi sap xep la:");
	in_mang(a,n);
	return 0;

}
