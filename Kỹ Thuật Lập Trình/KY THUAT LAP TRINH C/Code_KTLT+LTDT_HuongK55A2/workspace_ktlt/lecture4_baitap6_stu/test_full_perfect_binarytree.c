/*
 * test_full_perfect_binarytree.c
 *
 *  Created on: Nov 16, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

typedef struct Node *Tree;

Tree createNode(int data)
{
	Tree a;
	a = (Tree*)malloc(sizeof(struct Node));
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
		return root;
	else
	{
		if (root == NULL)
			return a;
		else
		{
			Tree p;
			p = root;
			while (p != NULL)
			{
				/*if (p->data == data)
					return root;
				else
				{*/
					if (p->data >= data)
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
							p = p->right;
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

Tree createTree( int n)
{
	int i, data;
	Tree tree;
	tree = NULL;
	for (i=0; i<n; i++)
	{
		//printf("nut %d: ", i+1);
		scanf("%d", &data);
		tree = addNode(tree, data);
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

/*int isFull(Tree root)
{
	if (root != NULL)
	{
		if ((root->left != NULL) && (root->right == NULL))
				return 0;
		if ((root->left == NULL) && (root->right != NULL))
				return 0;
		if ((root->left != NULL) && (root->right != NULL))
				return (isFull(root->left) + isFull(root->right));
	}
	else
		return 1;// return 0;
}*/
int isFull(Tree root)
{
	if (root != NULL)
	{
		if (root->left==NULL || root->right==NULL)
			return 0;
		isFull(root->left);
		isFull(root->right);
	}
	return 1;
}

/*int isFull(Tree root) cung dc
{
	if (root == NUL)
		return 1;
	if (root->left == NULL || root->right == NULL)
		return 0;
	isFull(root->left);
	isFull(root->right);
}*/

int ChieuCao(Tree root)
{
    if (root!=NULL)
    {
        int a = ChieuCao(root->left);
        int b = ChieuCao(root->right);
        int max = (a>b)?a:b;
        return 1 + max;
    }
    return 0;
}
// ham tinh chieu cao(can)
/*int ChieuCao(Tree root)
{
	if (root == NULL)
		return 0;
	int a = ChieuCao(root->left);
	int b = ChieuCao(root->right);
	if (a > b)
		return (a+1);
	return (b+1);
}*/
//tinh tong so nut// mang
/*int Tinh(Tree root)
{
    if (root!=NULL)
    {
        int a = Tinh(root->left);
        int b = Tinh(root->right);
        return root->data + a + b;
    }
    return 0;
}*/

// ham tinh tong so nut
int sumNode(Tree root)
{
	if (root == NULL)
		return 0;
	int a = sumNode(root->left);
	int b = sumNode(root->right);
	return 1 + a +b ;
}
/*void perfect(Tree root)===>sai
{
	int k, h, a;
	if (root != NULL)
	{
		h = ChieuCao(root);
		k = sumNode(root);

		if (h == 0 || k == 0)
			return;
		a = pow(2, h+1);
		if (k == a)
			printf("\nCay hoan hao");
		else
			printf("\nCay khong phai la cay hoan hao");
	}
}*/
int isPerfect(Tree root)
{
	if (root == NULL)
		return 1;
	if (ChieuCao(root->left) == ChieuCao(root->right))
		return (isPerfect(root->left) && isPerfect(root->right));
	else
		return 0;
}

int main()
{
	setbuf(stdout, NULL);
	int n;
	printf("Nhap so nut: ");
	scanf("%d", &n);
	Tree tree;
		//tree = NULL;  ==>==> sao k dc vay nhi???
	tree = createTree(n);
	printf("\nCay la:\n");
	inOrder(tree);
	int k = isFull(tree);
	/*if (k == 1)
		printf("Cay day du");
	else if (k == 0)
		printf("Cay k day du");
	else
		printf("Cay hoan hao");*/
	if (k!=0)
		printf("\nCay day du");
	else
		printf("\nCay khong day du");
	int p;
	p = isPerfect(tree);
	if (p != 0)
		printf("\nCay hoan hao");
	else
		printf("\nCay khong hoan hao");
	int t;
	t = sumNode(tree);
	if (t!=0) printf("\nTong so nut cua cay la: %d\n", t);
	else printf("khong");
	int h;
	h = ChieuCao(tree);
	if (h!=0) printf("\ncjieu cao cua cay la: %d", h);
	return 0;
}


