/*
 * test_ancestor.c
 *
 *      Author: NgoHuong
 */

/*cho 2 nut p, q
  kiem tra xem p co phai tien boi cua q khong
  */

//KHI NHAP 2 SO GIONG NHAU THI CAY CHI IN RA 1!! WHY???

#include <stdio.h>
#include <stdlib.h>

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

Tree find(Tree root, int data)
{
	if (root != NULL)
	{
		Tree p;
		p=root;
		while (p != NULL)
		{
			if (p->data == data)
				return p;
			else
			{
				if (p->data > data)
					p = p->left;
				else
					p = p->right;
			}
		}
	}
	return NULL;
}

void ancestor(Tree root, int p, int q)
{
	Tree pHead = find(root, p);
	if (pHead == NULL)
	{
		printf("p Khong co trong cay");
	}
	else
	{
		Tree qHead = find (pHead, q);
		if (qHead == NULL)
			printf("p khong la to tien cua q");
		else
		{
			printf("p la to tien cua q");
		}
	}
}
//kich thuoc cua cay nhi phan

int sizeofTree(Tree root)
{
	if (root == NULL)
		return 0;
	else
	{
		return 1+sizeofTree(root->left) + sizeofTree(root->right);
	}
}

// kich thuoc 1 node

int sizeofNode(Tree root, int p)
{
	Tree pNode = find(root, p);
	return sizeofTree(pNode);
}

int main()
{
	setbuf(stdout, NULL);
	int n, p, q;
	printf("Nhap so nut: ");
	scanf("%d", &n);
	Tree tree;
	//tree = NULL;  ==>==> sao k dc vay nhi???
	tree = createTree(n);
	printf("\nCay la:\n");
	inOrder(tree);
	printf("\nNhap p= ");scanf("%d", &p);
	printf("\nNhap q= ");scanf("%d", &q);
	ancestor(tree, p, q);
	int k;
	k = sizeofTree(tree);
	printf("\nKich thuoc cua cay la: %d\n", k);

	int h = sizeofNode(tree, p);
	printf("Kich thuoc 1 nut la: %d", h);

	return 0;
}
