/*
 * bai4.c
 *
 *  Created on: Oct 30, 2012
 *      Author: Student
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "TreeAncestor.h"
//kiem tra p co phai la to tien cua q hay ko?

/*
 Tree *addNode(Tree *root, int data){
 if(*root ==NULL){
 Tree *a= createNode(data);
 *root = NULL;
 return root;
 }
 if(data < (*root)->data){
 addNode(&(*root)->left, data);
 }else {
 addNode(&(*root)->right, data);
 }
 }*/

int main(int argc, char **argv) {
	setbuf(stdout, NULL);
	typedef struct Node *Tree;
	int a[] = { 3, 1, 8, 0, 2, 6, 9, 5 };
	Tree root = NULL;
	int i;
	for (i = 0; i < 8; i++) {
		root = addNode(root, a[i]);
	}
	ancestor(root, 5, 3);
	return 0;
}
