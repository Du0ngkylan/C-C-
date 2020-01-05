/*
 * bai6slide4.c
 *
 *  Created on: Aug 11, 2013
 *      Author: hung
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Tree{
	int datum;
	struct Tree*left;
	struct Tree*right;
};

struct Tree*root=NULL;

struct Tree*creatNode(int datum){
	struct Tree*node;
	node=(struct Tree*)malloc(sizeof(struct Tree));
	node->datum=datum;
	node->left=NULL;
	node->right=NULL;
	return node;
}

void addNode(struct Tree**root,int datum){
	if(*root==NULL){
		struct Tree*node=creatNode(datum);
		*root=node;
		return;
	}
	else{
		if(datum<(*root)->datum){
			addNode(&(*root)->left,datum);
		}
		else{
			addNode(&(*root)->right,datum);
		}
	}
}

void in(struct Tree*root){
	struct Tree*p;
	for(p=root;p!=NULL;p=p->left){
		printf("%d ",p->datum);
	}
	for(p=root;p!=NULL;p=p->right){
		printf("%d ",p->datum);
	}
	p=root;
	if(p->left!=NULL){
		in(p->left);
	}
	if(p->right!=NULL){
		in(p->right);
	}

}

/*int isFull(struct Tree*root){
	if(root!=NULL){
		if(root->left==NULL&&root->right!=NULL){
			return 1;
		}
		else if(root->left!=NULL&&root->right==NULL){
			return 1;
		}
		else if(root->left==NULL&&root->right==NULL){
			return isFull(root->left)+isFull(root->right);
		}
	}
	else
		return 0;

}*/

int isFull(struct Tree* root) {
	if (root != NULL) {
		if (root->left == NULL && root->right != NULL)
			return 1;
		else if (root->left != NULL && root->right == NULL) {
			return 1;
		}else if (root->left != NULL && root->right != NULL) {
			return isFull(root->left) + isFull(root->right);
		}
	}
	return 0;
}
int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	int a[]={3,1,8,0,2,6,9,5,7};
	int i;
	for(i=0;i<9;i++){
		addNode(&root,a[i]);
	}
	in(root);
	int check=isFull(root);
	if(check==0){
		printf("la cay day du");
	}
	else{
		printf("ko la cay day du");
	}
	return 0;

}
