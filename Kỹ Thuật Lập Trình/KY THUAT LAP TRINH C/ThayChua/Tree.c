/*
 * Queue.c
 *
 *  Created on: Aug 10, 2013
 *      Author: Administrator
 */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node {
	int data;
	struct node *left; //con tro trai
	struct node *right; //con tro phai
};
typedef struct node *tree;
//ham tao mot node moi tra lai node vua tao
tree create(int data) {
	tree q = (tree) malloc(sizeof(struct node)); //cap phat
	q->data = data;
	q->left = NULL;
	q->right = NULL;
	return q; //tra ve 1 nut
}
//ham them node
void addNode(tree *root, int data) {
	if (*root == NULL) { //kiem tra cay,neu node con trong thi them vao
		tree q = create(data);
		*root = q; //nut p dc them vao cay
	} else { //neu ko,dung de quy de tim vi tri can add của nut q
		if ((*root)->data > data) //du lieu se nam o ben trai
			addNode(&(*root)->left, data);
		else
			//du lieu se nanm o ben phai
			addNode(&(*root)->right, data);
	} //tuong tu tim kiem nhi phan,de tim vi tri thich hop cho nut moi
}
//ham tim node con cuc trai,xoa va tra lai gia tri chua trong node do
int findReplace(tree *root) {
	if ((*root)->left == NULL) {
		int t = (*root)->data;
		(*root) = (*root)->right;
		return t;
	} else
		findReplace(&(*root)->left);
}
// ham xoa mot node bat ki
void deleteNode(tree *root, int x) {
	if ((*root)->data > x)
		deleteNode(&(*root)->left, x);
	else if ((*root)->data < x)
		deleteNode(&(*root)->right, x);
	else {
		if ((*root)->left == NULL && (*root)->right == NULL) //neu la la thi giai phong
			(*root) = NULL;
		else if ((*root)->left == NULL) //neu cay con trai bang null thay node bang cay phai
			(*root) = (*root)->right;
		else if ((*root)->right == NULL) //neu cay con phai bang null thay node bang cay trai
			(*root) = (*root)->left;
		else
			//thay node bang nut con trai nhat cua cay con phai
			(*root)->data = findReplace(&(*root)->right);
	}
}
//ham tim mot phan tu trong cay, co tra lai 1,khong co tra lai 0
int search(tree root, int x, int h) {
	if (root == NULL) {
		return 0;
	} else {
		if (root->data == x)
			return h;
		else if (root->data > x) {
			h++;
			search(root->left, x, h);
		} else {
			h++;
			search(root->right, x, h);
		}
	}
}

//ham tham cay
void visit(tree root) {
	if (root != NULL) {
		printf("%5d", root->data);
	}
}
//ham in cay dung de quy
void inOder(tree root) {
	if (root != NULL) {
		inOder(root->left);
		visit(root);
		inOder(root->right);
	}
}
//ham chinh
int main() {
//	setbuf(stdout, NULL);
	int i;
	tree root;
	root = NULL;
	int a[] = { 6, 8, 45, 67, 9, 34, 2, 1, 0, 7 };
	for (i = 0; i < 10; i++) {
		addNode(&root, a[i]);
	}
	paint(root);
	inOder(root);
	puts("");
	addNode(&root, 5);
	printf("cay sau khi them node la : \n");
	inOder(root);
	puts("");
//	if (search(root, 10) == 0)
//		printf("khong co so can xoa trong day!");
//	printf("%d\n", search(root, 34, 0));

	deleteNode(&root, 9);
	printf("cay sau khi xoa la : \n");
	inOder(root);
    getch();
	return 0;
}
