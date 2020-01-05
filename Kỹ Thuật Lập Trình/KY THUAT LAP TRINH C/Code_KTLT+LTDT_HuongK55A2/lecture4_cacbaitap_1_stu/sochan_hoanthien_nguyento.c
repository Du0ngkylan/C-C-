/*
 * sochan_hoanthien_nguyento.c
 *
 *  Created on: Nov 22, 2012
 *      Author: NgoHuong
 */

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
//ham tinh chieu cao cua cay
int chieuCao(Tree root)
{
	if (root != NULL)
	{
		int a = chieuCao(root->left);
		int b = chieuCao(root->right);
		if (a > b)
			return 1 +a;
		return 1 + b;
	}
	return 0;
}
//ham kiem tra so nguyen to

int kt_snto(int k)
{
	int i;
	if (k<2)
		return 0;
	for (i=2; i<=(k/2); i++)
	{
		if (k % i == 0)
			return 0;
	}
	return 1;
}

//ham dem so luong nut co dung 1 nut con ma thong tin tai do la sn to

int dem_songuyento(Tree root)
{
	if (root != NULL)
	{
		int a = dem_songuyento(root->left);
		int b = dem_songuyento(root->right);
		if (kt_snto(root->data) == 1)
		{
			if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL) )
				return (1+a+b);
		}
		return (a+b);
	}
	return 0;
}
//dem so luong nut co 2 nut con ma thong tin tai do la so nguyen to

int dem_snguyento(Tree root)
{
	if(root != NULL)
	{
		int a = dem_snguyento(root->left);
		int b = dem_snguyento(root->right);
		if(kt_snto(root->data)==1)
		{
			if (root->left == NULL && root->right == NULL)
				return 1+a+b;
		}
		return a+b;
	}
	return 0;
}
// ham in ra cac so chan cua cay==========

void so_chan(Tree root)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			so_chan(root->left);
		if (root->data % 2 == 0)
			printf("%5d", root->data);
		if (root->right != NULL)
			so_chan(root->right);
	}
}

//dem so luong cac nut chan trong cay

int dem_so_chan(Tree root)
{
	if (root != NULL)
	{
		int a = dem_so_chan(root->left);
		int b = dem_so_chan(root->right);
		if (root->data % 2 == 0)
			return (1+a+b);
		else
			return (a+b);
	}
	return 0;
}

//dem so luong node co dung 1 node con
//co dung 2 con thi khac o dieu kien thoi
int dem_oneNode(Tree root)
{
	if (root != NULL)
	{
		int a = dem_oneNode(root->left);
		int b = dem_oneNode(root->right);
		if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
			return 1+a +b;
		return a+b;
	}
	return 0;
}

//

// ham kiem tra so hoan thien

int kt_sht(int k)
{
	int i, s = 0;
	for (i=1; i<=(k/2); i++)
	{
		if (k % i == 0)
			s =s+i;
	}
	if (k == s)
		return 1;
	else
		return 0;
}

//ham in ra cac so hoan thien trong cay

void sohoanthien(Tree root)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			sohoanthien(root->left);
		if (kt_sht(root->data) == 1)
			printf("%5d", root->data);
		if (root->right != NULL)
			sohoanthien(root->right);
	}
}

//ham dem so hoan thien

int dem_sohoanthien(Tree root)
 {
	 if (root != NULL)
	 {
		 int a = dem_sohoanthien(root->left);
		 int b = dem_sohoanthien(root->right);
		 if (kt_sht(root->data) == 1)
			 return (1+a+b);
		 else
			 return (a+b);
	 }
	 return 0;
 }

//in ra nut nam tren tang thu k cua cay
void in_tangK(Tree root, int k)
{
	if (root != NULL)
	{
		k--;
		if (root->left != NULL)
			in_tangK(root->left, k);
		if (k == 0)
			printf("%5d", root->data);
		if (root->right != NULL)
			in_tangK(root->right, k);
	}
}
//in ra tat ca cac nut tren cay theo thu tu tu tang 0 den tang h-1(h la chieu cao cua cay)

void in_K(Tree root)
{
	int h = chieuCao(root);
	int i;
	for (i=0; i<h; i++)
	{
		printf("\ncac nut cua tang thu %d la:\n", i);
		in_tangK(root, i+1);
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

	printf("\nCac gia tri chan cua cay la:\n");
	so_chan(tree);
	if (dem_so_chan(tree) != 0)
		printf("\nCo %d so chan trong cay", dem_so_chan(tree));
	else
		printf("\nKhong co so chan trong cay");

	printf("\nCac so hoan thien co trong cay la:\n");
	sohoanthien(tree);
	if (dem_sohoanthien(tree) != 0)
		printf("\nCo %d so hoan thien trong cay", dem_sohoanthien(tree));
	else
		printf("\nKhong co so hoan thien trong cay");

	if (dem_songuyento(tree) != 0)
		printf("\nCo %d nut co 1 con ma la so nguyen to trong cay", dem_songuyento(tree));
	else
		printf("\nKhong co nut nao co 1 con ma tai do la so nguyen to trong cay");

	if (dem_oneNode(tree) != 0)
		printf("\nCo %d nut ma co 1 nut con trong cay", dem_oneNode(tree));
	else
		printf("\nKhong co nut ma trong do co 1 nut con");

	int k;
	printf("\n\nNhap k = ");scanf("%d", &k);
	in_tangK(tree, k);
	printf("\nCac nut tren cac tang cua cay la:\n");
	in_K(tree);
	return 0;
}

