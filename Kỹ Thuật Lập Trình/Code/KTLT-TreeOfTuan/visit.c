/*
 * visit.c
 *
 *  Created on: Nov 28, 2012
 *      Author: ADMIN
 */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "tree.h"

void visit(Tree tree) {
	printf("%3d", tree->data);
}

void preOrder(Tree tree) {
	if (tree != NULL ) {
		visit(tree);
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

void postOrder(Tree tree) {
	if (tree != NULL ) {
		postOrder(tree->left);
		postOrder(tree->right);
		visit(tree);
	}
}

void inOrder(Tree tree) {
	if (tree != NULL ) {
		inOrder(tree->left);
		visit(tree);
		inOrder(tree->right);
	}
}

/*
 void NLR(Tree tree){
 if (tree != NULL)
 {
 printf("%d ", tree->data);
 NLR(tree->left);
 NLR(tree->right);
 }
 }*/

void NRL(Tree tree) {
	if (tree != NULL ) {
		visit(tree);
		NRL(tree->right);
		NRL(tree->left);
	}
}
/*
 void LNR(Tree tree){
 if (tree != NULL)
 {
 LNR(tree->left);
 printf("%d ", tree->data);
 LNR(tree->right);
 }
 }

 void LRN(Tree tree)
 {
 if (tree != NULL)
 {
 LRN(tree->left);
 LRN(tree->right);
 printf("%d ", tree->data);
 }
 }*/

void RNL(Tree tree) {
	if (tree != NULL ) {
		RNL(tree->right);
		visit(tree);
		RNL(tree->left);
	}
}

void RLN(Tree tree) {
	if (tree != NULL ) {
		RLN(tree->right);
		RLN(tree->left);
		visit(tree);
	}
}

