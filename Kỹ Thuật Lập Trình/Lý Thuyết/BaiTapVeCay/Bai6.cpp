#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
	int datum;
	struct Node *left;
	struct Node *right;
};

typedef struct Node *Tree;

Tree root = NULL;

Tree createNode(int datum) 
{
	Tree node = (Tree)malloc(sizeof(struct Node));
	node->datum = datum;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void addNode(Tree *root, int datum) 
{
	if ((*root) == NULL) 
	{
		Tree node = createNode(datum);
		*root = node;
		return;
	}
	if (datum < (*root)->datum) 
	{
		addNode(&(*root)->left, datum);
	} 
	else 
	{
		addNode(&(*root)->right, datum);
	}
}

void visit(Tree tree) 
{
	printf("%3d", tree->datum);
}

void preOrder(Tree tree) 
{
	if (tree != NULL) {
		visit(tree);
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

int kiemtra(Tree tree)
{
	if(tree == NULL)
		return 1;
	if((tree -> left != NULL && tree -> right == NULL) || (tree -> left == NULL && tree -> right != NULL))
		return 0;
	return 1;
}

int inFullTree(Tree tree)
{
	if(tree == NULL)
		return 1;
	
	if(kiemtra(tree) == 0)
		return 0;
	else
	{
		if(inFullTree(tree->left)==0 || inFullTree(tree->right)==0)
		return 0;
	}	
	return 1;			
}

//int depth(node *tree)
//{
//	if(tree==NULL) 
//		return 0;
//	int ld=depth(tree->left);
//	int rd=depth(tree->right);
//	return 1+(ld>rd ? ld:rd);
//}

//bool isPerfect(node *root)
//{
//	if(root==NULL) 
//		return true;
//	if(depth(root->left)==depth(root->right))
//		return inFullTree(root->left) && isPerfect(root->right);
//	else if(depth(root->left)==depth(root->right)+1)
//		return isPerfect(root->left) && inFullTree(root->right);
//	else return false;
//}

int main() 
{
	int a[] = {3, 1, 8, 2, 6, 9};
	Tree root = NULL;
	int i;
	for (i = 0; i < 6; i++) {
		addNode(&root, a[i]);
	}
	
	preOrder(root);
	
	int dem = 0;
	
	if(inFullTree(root)==1)
		printf("\nCay day du");
	else
		printf("\nCay khong day du");
	

	getch();
	return 0;
}
