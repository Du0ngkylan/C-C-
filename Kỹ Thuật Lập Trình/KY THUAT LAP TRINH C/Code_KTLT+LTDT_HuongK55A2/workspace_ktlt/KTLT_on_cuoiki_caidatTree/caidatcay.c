/*
 * caidatcay.c
 *
 *  Created on: Jan 6, 2013
 *      Author: NgoHuong
 */
//tinh , kt to tien, tinh nut, ktr cay day du, kt cay hoan hao...

#include <stdlib.h>
#include <stdio.h>

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
		(*root) = a;
		return ;
	}
	if ((*root)->data > data)
	{
		addNode(&(*root)->left, data);
	}
	else
	{
		addNode(&(*root)->right, data);
	}
}

Tree createTree()
{
	Tree tree;
	tree = NULL;
	int t;
	FILE *f;
	f = fopen("caycao.txt", "r");
	if (!f)
	{
		printf("\nLoi mo tep");
		exit(0);
	}
	while(!feof(f))
	{
		fscanf(f, "%d", &t);
		addNode(&tree, t);////////////////note
	}
	return tree;
}

void visitTree(Tree tree)
{
	printf("%5d", tree->data);
}

void inOrder(Tree tree)
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		visitTree(tree);
		inOrder(tree->right);
	}
}
//xem co xuat hien gia tri data trong cay khong ,, tim kiem..xem ham o duoi nua
Tree Tim(Tree root, int data)//co the gan p = root
{
	if (root != NULL)
	{
		Tree p;
		p = root;
		if (p->data == data)
			return root;
		if (p->data > data)
			return Tim(p->left, data);
		else
			return Tim(p->right, data);
	}
	return NULL;
}
//tim xem p co gia tri data co trong cay khong

Tree find(Tree root, int data)
{
	Tree p;
	p = root;
	while (p != NULL)
	{
		 if (p->data == data)
			 return p;
		 else
		 {
			 if (p->data < data)
				 p = p->right;
			 else
				 p = p->left;
		 }
	}
	return NULL;
}

//kiem tra xem p co la to tien cua q hay khong

void ancestor(Tree root, int p, int q)
{
	Tree pHead  = find(root, p);
	if (pHead == NULL)
		printf("\nKhong co p trong cay");
	else{
		Tree qHead = find(pHead, q);
		if (qHead == NULL)
			printf("\n%d khong la to tien cua %d", p, q);
		else
			printf("\n%d la to tien cua %d", p, q);
	}
}
//tinh kich thuoc cua cay hay tinh tong so nut cua cay

int sizeofTree(Tree root)
{
	if (root != NULL)
	{
		int a = sizeofTree(root->left);
		int b = sizeofTree(root->right);
		return 1 +a +b;
	}
	return 0;
}
//hay tinh kich thuoc cua 1 node

int sizeofNode(Tree root, int p)
{
	Tree pNode = find(root, p);
	if (pNode != NULL)
	return sizeofTree(pNode);
}

//kiem tra cay day du va cay hoan hao

int isFull(Tree root)
{
	if (root != NULL)
	{
		if (root->left != NULL ||root->right != NULL)
			return 0;
		isFull(root->left);
		isFull(root->right);
	}
	return 1;
}
// ham tinh chieu cao cua cay

int chieuCao(Tree root)
{
	if (root != NULL)
	{
		int a = chieuCao(root->left);
		int b = chieuCao(root->right);
		if (a > b)
			return 1+a;
		return 1+b;
	}
	return 0;
}

//kiem tra cay hoan hao

int perfect(Tree root)
{
	if (root != NULL)
	{
		if (chieuCao(root->left) == chieuCao(root->right))
			return (perfect(root->left) && perfect(root->right));
	}
	return 1;
}

int main()
{
	setbuf(stdout, NULL);
	Tree tree;
	int p, q;
	tree = createTree();
	printf("\nCay da doc duoc tu tep la:\n");
	inOrder(tree);
	printf("\nNhap p = ");
	scanf("%d", &p);
	printf("\nNhap q = ");
	scanf("%d", &q);

	if (find(tree,p) == NULL)
		printf("\nKhong xuat hien %d trong cay", p);
	else
		printf("\nco xuat hien %d trong cay", *find(tree,p));

	ancestor(tree, p, q);

	int k = sizeofNode(tree, p);
	printf("\nKich thuoc cua mot nut trong cay la: %d", k);

	int tim;
	printf("\n\ntim = ");scanf("%d", &tim);
	if (Tim(tree, tim) != NULL)
		printf("\nCo %d", *Tim(tree, tim));
	else
		printf("\nKhong %d", *Tim(tree, tim));
	return 0;
}
