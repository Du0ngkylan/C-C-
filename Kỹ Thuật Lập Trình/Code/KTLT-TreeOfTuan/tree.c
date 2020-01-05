/*
 * tree.c
 *
 *  Created on: Nov 7, 2012
 *      Author: student
 */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "tree.h"

Tree root = NULL;

Tree createNode(int datum) {
	Tree node = (Tree) malloc(sizeof(struct Node));
	node->data = datum;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void addNode(Tree *root, int datum) {
	if ((*root) == NULL ) {
		Tree node = createNode(datum);
		*root = node;
		return;
	}
	if (datum < (*root)->data) {
		addNode(&(*root)->left, datum);
	} else {
		addNode(&(*root)->right, datum);
	}
}

int chieucao(Tree tree, int start) {
	int tam;
	if (tree == NULL )
		return 0;
	else
		tam = compare(chieucao(tree->left, start + 1),
				chieucao(tree->right, start + 1));
	tam = tam + 1;
	return tam;
	/*return max(chieucao(tree->left, start + 1),
	 chieucao(tree->right, start + 1)) + 1;*/
}

int compare(int n, int m) {
	if (n > m) {
		return n;
	} else {
		return m;
	}
}

int sizeOfTree(Tree root) {
	if (root == NULL ) {
		return 0;
	} else {
		return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
	}
}
int sizeOfNode(Tree root, int p) {
	Tree pNode = find(root, p);
	return sizeOfTree(pNode);
}

/*struct Tree* search(Tree tree, int p){
 struct Tree *q;
 q=tree;
 while(q->data!=p && q== NULL){
 if(q->data < p)
 q=q->right;
 else
 q=q->left;
 }
 return q;
 }*/
