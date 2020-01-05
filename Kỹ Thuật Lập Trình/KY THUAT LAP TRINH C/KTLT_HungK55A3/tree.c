/*
 * tree5.c
 *
 *  Created on: Aug 11, 2013
 *      Author: hung
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

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

struct Tree*find(struct Tree*root,int datum){
	if(root==NULL){
		return NULL;
	}
	else{
		struct Tree*p=root;
		while(p!=NULL){
			if(p->datum==datum){
				return p;
			}
			else{
				if(datum<p->datum){
					p=p->left;
				}
				else{
					p=p->right;
				}
			}
		}
	}
	return NULL;
}

void ancester(struct Tree*root,int p,int q){
	if(find(root,p)==NULL){
		printf("ko co %d trong cay \n",p);
	}
	else{
		struct Tree*pNode=find(root,p);
		struct Tree*test=find(pNode,q);
		if(test==NULL){
			printf("%d ko phai la ancestor cua %d \n",p,q);
		}
		else{
			printf("%d la ancestor cua %d \n",p,q);
		}
	}

}
int isFull(struct Tree*root){
	if(root==NULL){
		return 0;
	}
	else if(root->left!=NULL&&root->right==NULL){
		return 1;
	}
	else if(root->left==NULL&&root->right!=NULL){
		return 1;
	}
	else{
		return isFull(root->left)+isFull(root->right);
	}
}

int sizeofTree(struct Tree*root){
	if(root==NULL){
		return 0;
	}
	else{
		return 1+sizeofTree(root->left)+sizeofTree(root->right);
	}
}

int sizeofNode(struct Tree*root,int nut){
	struct Tree*pNode=find(root,nut);
	return sizeofTree(pNode);
}

int depthofTree(struct Tree* root) {
	if (root == NULL) {
		return 0;
	}
	int a = depthofTree(root->left);
	int b = depthofTree(root->right);
	int max = (a > b) ? a : b;
	return 1 + max;
}
int isLeaf(struct Tree* root) {
	if (root->left == NULL&&root->right==NULL) {
		return 1;
	} else
		return 0;
}
int checkPerfect(struct Tree *root, int depth, int maxDepth) {
	if (root == NULL){
		return 1;
	}
	else{
		if(isLeaf(root)==1){
			if (depth == maxDepth){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return checkPerfect((root->left), depth + 1, maxDepth)
					&& checkPerfect(root->right, depth + 1, maxDepth);
		}
	}
}
int perfect(struct Tree *root){
	if(isFull(root)==1){
		return 0;
	}
	int maxDepth=depthofTree(root);
	return checkPerfect(root,1,maxDepth);
}


int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	int a[]={3,1,0,8,2,6};
	int i;
	for(i=0;i<6;i++){
		addNode(&root,a[i]);
	}
	in(root);
	int p,q;
	puts("");
	printf("nhap p: ");scanf("%d",&p);
	printf("nhap q: ");scanf("%d",&q);
	ancester(root,p,q);
	int daydu=isFull(root);
	if(daydu==0){
		printf("no la cay day du\n");
	}
	else{
		printf("ko phai cay day du\n");
	}
	int nut;
	printf("nhap vao nut can tim kich co: ");scanf("%d",&nut);
	printf("size of nut day la: %d\n",sizeofNode(root,nut));
	int maxdepth=depthofTree(root);
	printf("chieu cao cua cay la: %d \n",maxdepth);
	int hoanhao=perfect(root);
	printf("%d",hoanhao);
	if(hoanhao==0){
		puts("ko phai cay hoan hao");
	}
	else{
		puts("la cay hoan hao");
	}
	return 0;

}
