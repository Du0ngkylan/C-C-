/*
 * TreeAncesstor.c
 *
 *  Created on: Nov 12, 2012
 *      Author: ADMIN
 */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "TreeAncestor.h"

Tree root = NULL;

Tree createNode(int data) {
	Tree a = (Tree) malloc(sizeof(struct Node));
	if (a != NULL ) {
		a->data = data;
		a->left = NULL;
		a->right = NULL;
	}
	return a;
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
//tim trong cac cay nho co p hay ko
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
void ancestor(Tree root, int p, int q) {
	Tree pNode = find(root, p); //tim trong cay co p hay ko?
	if (pNode == NULL ) {
		printf("%d ko co trong cay", p);
	} else {
		Tree qNode = find(root, q);
		if (qNode != NULL ) {
			printf("%d la to tien cua %d", p, q);
		} else {
			printf("%d khong phai la to tien cua %d", p, q);
		}
	}
}
