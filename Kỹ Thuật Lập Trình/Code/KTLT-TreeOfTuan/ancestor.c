/*
 * ancestor.c
 *
 *  Created on: Nov 28, 2012
 *      Author: ADMIN
 */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "tree.h"

void ancestor(Tree tree, int p, int q) {
	Tree pNode = find(tree, p); //tim trong cay co p hay ko?
	if (pNode == NULL ) {
		printf("%d ko co trong cay", p);
	} else {
		Tree qNode = find(pNode, q);
		if (qNode != NULL ) {
			printf("%d la to tien cua %d", p, q);
		} else {
			printf("%d khong phai la to tien cua %d", p, q);
		}
	}
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
