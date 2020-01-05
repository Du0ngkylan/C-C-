/*
 * caynhiphan.c
 *
 *  Created on: Oct 20, 2012
 *      Author: MSS THUY
 */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"caynhiphan.h"
Tree createTree(int data) {
	Tree root = (Tree) malloc(sizeof(Tree));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}
void addTree(Tree *root, int data) {
	if ((*root) == NULL) {
		Tree node = createTree(data);
		*root = node;
		return;
	}
	if (data < (*root)->data) {
		addTree(&(*root)->left, data);
	} else {
		addTree(&(*root)->right, data);
	}
}
void visit(Tree root) {
	printf("%5d", root->data);
}
void postorder(Tree root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		visit(root);
	}
}
int ancestor(Tree root, int parent, int child) {
	if (root == NULL) {
		return 0;
	}
	while (root != NULL) {
		if ((root->data) == parent) {
			return 1;
		}
		if ((root->data) == child) {
			return 0;
		} else if ((root->data) < child) {
			root = root->left;
		} else
			root = root->right;
	}
	return 0;
}
int depthofTree(Tree root) {
	if (root == NULL) {
		return 0;
	}
	int a = depthofTree(root->left);
	int b = depthofTree(root->right);
	int max = (a > b) ? a : b;
	return 1 + max;
}
int fullTree(Tree root) {
	if (root == NULL) {
		return 1;
	} else if (root->left == NULL && root->right == NULL) {
		return 1;
	} else if (root->left == NULL || root->right == NULL) {
		return 0;
	} else
		return fullTree(root->left) & fullTree(root->right);
}
int isLeaf(Tree root) {
	if (root == NULL) {
		return 1;
	} else
		return root->right && root->left;
}
int checkPerfect(Tree root, int depth, int maxDepth) {
	if (root == NULL) {
		return 1;
	} else {
		if (isLeaf(root)) {
			if (depth == maxDepth) {
				return 1;
			} else
				return 0;
		} else {
			return checkPerfect((root->left), depth + 1, maxDepth)
					& checkPerfect(root->right, depth + 1, maxDepth);
		}
	}
}
int perfect(Tree root){
	if(fullTree(root)==0){
		return 0;
	}
	int maxDepth=depthofTree(root);
	return checkPerfect(root,1,maxDepth);
}
int sizeofTree(Tree root){
	if(root==NULL){
		return 0;
	}
	else{
		return 1+sizeofTree(root->left)+sizeofTree(root->right);
	}
}
int sizeofnode(Tree root, int data) {
	if(root==NULL){
		return 0;
	}
	while(root!=NULL){
		if(root->data==data){
			return sizeofTree(root);
		}
		else if(root->data<data){
			root=root->left;
		}
		else
			root=root->right;
	}
	return 0;

}

