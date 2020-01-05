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

Tree diachi(Tree tree, int p)
{
	if(tree != NULL){
		if(tree->datum == p){
			return tree;
		}
		else
		{
			if(tree->left!= NULL && tree->datum > p){
				return diachi(tree->left, p);
			}
			else if(tree->right!= NULL && tree->datum < p){
				return diachi(tree->right, p);
			}
		}
	}
	else
		return NULL;	
} 

int ancestor2(Tree tree, int p, int q)
{
		Tree node1 = (Tree)malloc(sizeof(struct Node));
		node1 = diachi(tree, p);
		
		Tree node2 = (Tree)malloc(sizeof(struct Node));
		node2 = diachi(node1, q);
		
		printf("\nnode = %d", node1->datum);
		if(node2-> datum == q)
		{
			printf("\nis ancestor");
			printf("\nnode = %d", node2->datum);
		}
		else
			printf("\n is not ancestor");		
		
}

int ancestor(Tree tree, int p, int q)
{
		Tree node1 = (Tree)malloc(sizeof(struct Node));
		node1 = diachi(tree, p);
		
		printf("\nnode = %d", node1->datum);
		
		if(node1 == NULL)
			return 0;
		if(node1 -> datum == q)
		{
			return 1;
		}
		else
		{
			if(node1->datum > q && node1-> left != NULL)
			{
				return	ancestor(node1->left, node1->left->datum, q);
			}
			else if(node1->datum < q && node1-> right != NULL)
			{
				return ancestor(node1->right, node1->right->datum, q);
			}
		}	
		return 0;
}

int main() 
{
	int a[] = {3, 1, 8, 0, 2, 6, 9, 5};
	Tree root = NULL;
	int i;
	for (i = 0; i < 8; i++) {
		addNode(&root, a[i]);
	}
	
	preOrder(root);
	
	ancestor2(root, 8, 5);
	
//	if(ancestor(root,1,9))
//		printf("\nis");
//	else
//		printf("\nnot");
	

	getch();
	return 0;
}
