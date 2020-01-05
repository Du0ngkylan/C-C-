/*
 * caynhiphan1.c
 *
 *  Created on: May 26, 1981
 *      Author: HongMo
 */

// xem lai
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
	int datum;
	struct Node *left;
	struct Node *right;

};
typedef struct Node *tree;
tree creatnode(int datum) {
	tree a;
	a = (tree) malloc(sizeof(struct Node));
	if (a != NULL) {
		a->datum = datum;
		a->left = NULL;
		a->right = NULL;
	}
	return a;
}
tree addnode(tree root, int datum) {
	tree a;
	a = creatnode(datum);
	if (a == NULL) {
		return root;
	} else {
		if (root == NULL)
			return a;
		else {
			tree p = root;
			while (p != NULL) {
				if (p->datum == datum)
					return root;
				else if (datum < p->datum) {
					if (p->left != NULL)
						p = p->left;
					else {
						p->left = a;
						return root;
					}
				} else {
					if (p->right != NULL)
						p = p->right;
					else {
						p->right = a;
						return root;
					}
				}
			}
		}
	}
	return NULL;
}
tree creattree() {
	tree cay;
	cay = NULL;
	int t;
	FILE *f;
	f = fopen("cay.txt", "r");
	if (!f) {
		puts("loi doc tep");
		exit(0);
	}
	while (!feof(f)) {
		fscanf(f, "%d", &t);
		cay = addnode(cay, t);
	}
	return cay;
}
void visit(tree cay) {
	printf("%5d", cay->datum);
}
void preoder(tree cay) {
	if (cay != NULL) {
		//visit(cay);
		preoder(cay->left);visit(cay);
		preoder(cay->right);
	}
}
tree find(tree root, int datum) {
	if (root != NULL) {
		tree p = root;
		while (p != NULL) {
			if (p->datum == datum)
				return p;
			else if (datum < p->datum)
				p = p->left;
			else
				p = p->right;
		}
	}
	return NULL;
}
void ancestor(tree root, int p, int q) {
	tree pNode = find(root, p);
	if (pNode == NULL) {
		printf("\n%d khong co trong cay", p);
	} else {
		tree qNode = find(pNode, q);
		if (qNode == NULL) {
			printf("\n%d khong la tt cua %d", p, q);
		} else
			printf("\n%d la tt cua %d", p, q);
	}
}
int sizeoftree(tree root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return 1+sizeoftree(root->left)+sizeoftree(root->right);
	}
}

int sizeOfNode(tree root, int p) {
	tree pNode = find(root, p);
	return sizeoftree(pNode);
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	tree cay;
	int p, q,kt,ktnode;
	printf("nhap p=");
	scanf("%d", &p);
	printf("\nnhap q=");
	scanf("%d", &q);
	cay = creattree();
	printf("\ncay la:\n");
	preoder(cay);
	ancestor(cay, p, q);
	kt=sizeoftree(cay);
	printf("\nkich thuoc cua cay la:%d",kt);
	ktnode=sizeOfNode(cay,p);
	printf("\nkich thuoc cua node %d la %d",p,ktnode);
	return 0;
}

