/*
 * caidatTree.c
 *
 *  Created on: Nov 21, 2012
 *      Author: NgoHuong
 */
//cai dat cay bang de quy

#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

typedef struct Node *Tree;

//Tree root = NULL;

Tree createNode(int data)
{
	Tree a;
	a = (Tree)malloc(sizeof(struct Node));
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
		return;
	}
	if (data < (*root)->data)
	{
		addNode(&(*root)->left, data);
	}
	else
	{
		addNode(&(*root)->right, data);
	}
}

Tree createTree(int n)
{
	Tree tree;
	tree = NULL;
	int i, data;
	for (i=0; i<n; i++)
	{
		scanf("%d", &data);
		addNode(&tree, data);//saoooo
	}
	return tree;
}

void visit(Tree tree)
{
	printf("%5d", tree->data);
}

void inOrder(Tree tree)
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		visit(tree);
		inOrder(tree->right);
	}
}

int main()
{
	setbuf(stdout, NULL);
	int n;
	printf("\nNhap n= ");scanf("%d", &n);
	Tree tree;
	tree = createTree(n);
	printf("\nCay la:\n");
	inOrder(tree);
	return 0;
}
