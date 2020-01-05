/*
 * caidat_tree.c
 *
 *  Created on: Nov 7, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

typedef struct Node *Tree;
//Tree ...=NULL......

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

Tree addNode(Tree root, int data)
{
	Tree a;
	a = createNode(data);
	if (a == NULL)
	{
		return root;
	}
	else
	{
		if (root == NULL)
		{
			return a;
		}
		else
		{
			Tree p;
			p = root;
			while (p != NULL)
			{
				/*if (p->data == data)
				{
					return root;
				}
				else
				{*/
					if(p->data >= data)
					{
						if (p->left != NULL)
							p = p->left;
						else
						{
							p->left = a;
							return root;
						}
					}
					else
					{
						if (p->right != NULL)
							p=p->right;
						else
						{
							p->right = a;
							return root;
						}
					}
				//}
			}
		}
	}
	return NULL;
}

Tree createTree(int n)
{
	Tree tree;
	tree = NULL;
	int i, data;
	for (i=0; i<n; i++)
	{
		//printf("Nhap dinh %d: ", i+1);
		scanf("%d", &data);
		tree  = addNode(tree, data);
	}
	return tree;
}

void visit(Tree tree)
{
	printf("%3d", (tree->data));
}

void inOrder(Tree tree)
{
	if (tree != NULL)
	{
		inOrder(tree -> left);
		visit(tree);
		inOrder(tree -> right);
	}
}

int main()
{
	setbuf(stdout, NULL);
	int n;
	printf("Nhap so node: ");
	scanf("%d", &n);
	Tree tree;
	//tree = NULL;
	tree = createTree(n);
	printf("\nCay la:\n");//tai sao ma no bi nguoc ?????=>khong nguoc
	inOrder(tree);
	return 0;
}
