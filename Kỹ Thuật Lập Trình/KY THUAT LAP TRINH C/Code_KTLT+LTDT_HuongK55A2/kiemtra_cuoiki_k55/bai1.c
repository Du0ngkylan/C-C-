/*
 * bai1.c
 *
 *  Created on: Dec 3, 2012
 *      Author: NgoHuong
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
}Node;

typedef Node *Tree;

Tree createNode(int data)
{
	Tree p;
	p = (Tree)malloc(sizeof(Node));
	if (p != NULL)
	{
		p->data = data;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

void addNode(Tree *root, int data)
{
	if ((*root) == NULL)
	{
		Tree a = createNode(data);
		*(root) = a;
		return ;
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
	int i, data;
	Tree tree = NULL;
	for (i=0; i<n; i++)
	{
		scanf("%d", &data);
		addNode(&tree, data);
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
			else
			{
				if ( data < p->data)
					p = p->left;
				else
					p = p->right;
			}
		}
	}
	return NULL;
}

int main()
{
	setbuf(stdout, NULL);
	int n, p;
	printf("\nNhap vao n= ");
	scanf("%d", &n);
	Tree tree;
	tree = createTree(n);
	printf("\nCay da nhap la:\n");
	inOrder(tree);
	printf("\nNhap vao 1 so p = ");
	scanf("%d", &p);
	Tree k;
	k = find(tree, p);
	if (k != NULL)
		printf("\nSo %d co xuat hien trong cay", p);
	else
		printf("\nSo %d khong xuat hien trong cay", p);
	return 0;
}

