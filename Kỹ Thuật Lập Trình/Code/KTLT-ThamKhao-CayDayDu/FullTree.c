/*
 * FullTree.c
 *
 *  Created on: Nov 12, 2012
 *      Author: ADMIN
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "FullTree.h"

Tree root = NULL;

Tree createNode(int data) {
	Tree a = (Tree) malloc(sizeof(struct Node));
	if (a != NULL) {
		a->data = data;
		a->left = NULL;
		a->right = NULL;
	}
	return a;
}
Tree addNode(Tree root, int data) {
	Tree a = createNode(data);
	if (a == NULL) {
		return root;
	} else {
		if (root == NULL) {
			return a;
		} else {
			Tree p = root;
			while (p != NULL) {
				if (p->data == data) {
					return root;
				} else if (data < p->data) {
					if (p->left == NULL) {
						p->left = a;
						return root;
					} else {
						p = p->left;
					}
				} else {
					if (p->right == NULL) {
						p->right = a;
						return root;
					} else {
						p = p->right;
					}
				}
			}
		}
	}
	return NULL;
}
int isFull(Tree root) {
	if (root != NULL) {
		if (root->left == NULL && root->right != NULL)
			return 1;
		else if (root->left != NULL && root->right == NULL) {
			return 1;
		}else if (root->left != NULL && root->right != NULL) {
			return isFull(root->left) + isFull(root->right);
		}
	} else
		return 0;
}
