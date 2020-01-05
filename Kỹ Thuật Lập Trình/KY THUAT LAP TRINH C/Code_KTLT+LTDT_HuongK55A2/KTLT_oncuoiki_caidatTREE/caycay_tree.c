/*
 * caycay_tree.c
 *
 *  Created on: Jan 11, 2013
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
}Node;

typedef struct Node *Tree;

Tree createNode(int data)
{
	Tree a;
	a = (Tree)malloc(sizeof (struct Node));
	if (a != NULL)
	{
		a->data = data;
		a->left = NULL;
		a->right = NULL;
	}
	return a;
}

void addNode(Tree *root, int data)
{
	if ((*root) == NULL)
	{
		Tree a = createNode(data);
		*root = a;
		return ;
	}
	if ((*root)->data > data)
	{
		addNode(&(*root)->left, data);
	}
	else
		addNode(&(*root)->right, data);
}

Tree createTree(int n)
{
	int data, i;
	Tree tree;
	tree = NULL;
	for (i=0; i<n; i++)
	{
		fscanf("%d", &data);
		addNode(&tree, data);
	}
	return tree;
}
//neu ma create bang cahc doc teo thi lam nhu sau

Tree creTree()
{
	Tree tree;
	tree = NULL;
	int data;
	FILE *f;
	f = fopen("dl.txt", "r");
	if (!f)
	{
		printf("loi");
		exit(0);
	}
	while (!feof(f))
	{
		fscanf(f, "%d", &data);
		addNode(&tree, data);
	}
	return tree;
}

void visitTree(Tree tree)
{
	printf("%d", tree->data);
}

void inOrder(Tree tree)
{
	if(tree != NULL)
	{
		inOrder(tree->left);
		visitTree(tree);
		inOrder(tree->right);
	}
}

Tree find(Tree root, int data)
{
	if (root != NULL)
	{
		Tree p;
		p = root;
		while (p != NULL)
		{
			if (p->data == data)
				return p;
			if (p->data > data)
				p = p->left;
			else
				p=p->right;
		}
	}
	return NULL;
}

void ancestor(Tree root, int p, int q)
{
	Tree pHead = find(root, p);
	if (pHead == NULL)
		printf("\n%d khong xuat hien trong cay", p);
	else
	{
		Tree qHead = find (pHead, q);
		if (qHead == NULL)
			printf("\n%d khong la to tien cua %d", p, q);
		else
			printf("\n%d la to tien cua %d", p, q);
	}
}

int isFull(Tree root)
{
	if (root != NULL)
	{
		if (root->left != NULL || root->right != NULL)
			return 0;
		isFull(root->left);
		isFull(root->right);
	}
	return 1;
}

int chieuCao(Tree root)
{
	if (root != NULL)
	{
		int a = chieuCao(root->left);
		int b = chieuCao(root->right);
		if (a > b)
			return 1+a;
		else
			return 1+b;
	}
	return 0;
}
int isPerfect(Tree root)
{
	if (root != NULL)
	{
		if (chieuCao(root->left) == chieuCao(root->right))
		{
			return (isPerfect(root>left) && isPerfect(root->right));
		}
		else
			return 0;
	}
	return 1;
}

int nguyento(int k)
{
	if (k<2)
		return 0;
	for (i=2; i<=k/2; i++)
		if (k %2 == 0)
			return 0;
	return 1;
}

