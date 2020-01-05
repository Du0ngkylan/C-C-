/*
 * SizeOfNode.c
 *
 *  Created on: Nov 12, 2012
 *      Author: ADMIN
 */
#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <stddef.h>
#include "SizeOfNode.h"

Tree root = NULL;

Tree createNode(int datum) {
	Tree node = (Tree) malloc(sizeof(struct Node));
	node->data = datum;
	node->left = NULL;
	node->right = NULL;
	return node;
}
Tree addNode(Tree root, int data) {
	Tree a = createNode(data);
	if (a == NULL ) {
		return root;
	} else {
		if (root == NULL ) {
			return a;
		} else {
			Tree p = root;
			while (p != NULL ) {
				if (p->data == data) {
					return root;
				} else if (data < p->data) {
					if (p->left == NULL ) {
						p->left = a;
						return root;
					} else {
						p = p->left;
					}
				} else {
					if (p->right == NULL ) {
						p->right = a;
						return root;
					} else {
						p = p->right;
					}
				}
			}
		}
	}
	return NULL ;
}
Tree find(Tree root, int data) {
	if (root == NULL ) {
		return NULL ;
	} else {
		Tree p = root;
		while (p != NULL ) {
			if (p->data == data) {
				return p;
			} else {
				if (data < p->data) {
					p = p->left;
				} else {
					p = p->right;
				}
			}
		}
	}
	return NULL ;
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
