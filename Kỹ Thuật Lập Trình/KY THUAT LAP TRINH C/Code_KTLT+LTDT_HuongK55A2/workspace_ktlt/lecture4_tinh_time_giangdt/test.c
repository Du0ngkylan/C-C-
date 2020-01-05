/*
 * test.c
 *
 *  Created on: Oct 13, 2012
 *      Author: Student
 */
#include<stdio.h>
#include<stdlib.h>
#include "time.h"
struct node {
	int datum;
	struct node *next;
};

struct node *creatElement(int datum) {
	struct node *element = (struct node *) malloc(sizeof(struct node));
	if (element != NULL) {
		element->datum = datum;
		element->next = NULL;
	}
	return element;
}
struct node *addNode(struct node *list, int datum) {
	struct node *element = creatElement(datum);
	if (element == NULL) {
		return list;
	} else {
		element->next = list;
		return element;
	}
}
int fib(int k){
	if(k<2){
		return k;
	}
	else{
		return fib(k-1)+fib(k-2);
	}
}
void inds(struct node *list) {
	struct node *p;
	if (list == NULL) {
		printf("danh sach rong");
		exit(0);
	}
	for (p = list; p != NULL; p = p->next) {
		printf("%d\t", p->datum);
	}
}
struct node *fibonaci(struct node *list,int n){
	int c,d;
	c=0;
	d=1;
	list=addNode(list,c);
	list=addNode(list,d);
	while(1){
		int t=c+d;
		if(t<n){
			list=addNode(list,t);
		}
		else{
			break;
		}
		c=d;
		d=t;

		}
	return list;
	}
int main(){
	setbuf(stdout,NULL);
	int n=40;
	struct node *list=NULL;
	//printf("nhap n: ");
	//scanf("%d",&n);

	clock_t start = clock();
	fib(n);
	clock_t end = clock();

	printf("%ld tt ~ %f s\n", end - start, (float)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	list=fibonaci(list,n);
	end = clock();
	printf("%ld tt ~ %f s\n", end - start, (float)(end - start) / CLOCKS_PER_SEC);
	return 0;

}
