/*
 * bt_tree.c
 *
 *  Created on: Dec 21, 2012
 *      Author: NgoHuong
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node *right;
	struct Node *left;
}Node;

typedef struct Node *Tree;

Tree createNode(int data)
{
	Tree a;
	a = (Tree)malloc(sizeof(struct Node));
	if (a != NULL)
	{
		a->data = data;
		a->right = NULL;
		a->left = NULL;
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
	if ((*root)->data < data)
	{
		addNode(&(*root)->right, data);
	}
	else
	{
		addNode(&(*root)->left, data);
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

//ham tinh chieu cao cua cay

int height(Tree root)
{
	if (root != NULL)
	{
		int a = height(root->left);
		int b = height(root->right);
		if (a > b)
			return a+1;
		else
			return b+1;
	}
	return 0;
}

//ham tinh tong cua cac nut trong cay

int sumNode(Tree root)
{
	if (root != NULL)
	{
		int a = sumNode(root->left);
		int b = sumNode(root->right);
		return (1+a+b);
	}
	return 0;
}

//ham tinh tong gia tri cac nut trong cay

int sumValue(Tree root)
{
	if (root != NULL)
	{
		int a = sumValue(root->right);
		int b = sumValue(root->left);
		return (root->data + a + b);
	}
	return 0;
}

//ham dem so luong nut co dung 1 con

int dem_mot(Tree root)
{
	if (root != NULL)
	{
	int a = dem_mot(root->left);
	int b = dem_mot(root->right);
	if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
		return 1+a+b;
	return a+b;
	}
	return 0;
}

//ham dem so luong nut co 2 con

int dem_hai(Tree root)
{
	if (root != NULL)
	{
		int a = dem_hai(root->left);
		int b = dem_hai(root->right);
		if ((root->left != NULL && root->right != NULL) || (root->left != NULL && root->right != NULL))
			return 1+a+b;
		return a+b;
	}
	return 0;
}

//ham dem so luong nut co gia tri chan

int dem_nut_chan(Tree root)
{
	if (root != NULL)
	{
		int a = dem_nut_chan(root->left);
		int b = dem_nut_chan(root->right);
		if (root->data % 2 == 0)
		{
			return 1 + a + b;
		}
		return a + b;
	}
	return 0;
}
// ham in ra cac nut co gia tri chan

void chan(Tree root)
{
	if (root != NULL)
	{
		chan(root->left);
		chan(root->right);
		if (root->data % 2 == 0)
		{
			printf("%d\t", root->data);
		}
		//return a + b;
	}
	return ;
}
int main()
{
	setbuf(stdout, NULL);
	int n;
	printf("Nhap vao n = ");
	scanf("%d", &n);
	Tree tree;
	tree = createTree(n);
	printf("\nCay la:\n");//tai sao ma no bi nguoc ?????=>khong nguoc
	inOrder(tree);
	printf("\nTong so nut cua cay la:  %d", sumNode(tree));
	printf("\nTong so gia tri cua cay la:  %d", sumValue(tree));
	printf("\nTong so nut cua cay co dung 1 nut con la:  %d", dem_mot(tree));
	printf("\nTong so nut cua cay co 2 nut la:  %d", dem_hai(tree));
	//int c = dem_nut_chan(tree);
	printf("\nTong so nut cua cay cos gia tri chan la: %d\n", dem_nut_chan(tree));
	chan(tree);
	return 0;
}
