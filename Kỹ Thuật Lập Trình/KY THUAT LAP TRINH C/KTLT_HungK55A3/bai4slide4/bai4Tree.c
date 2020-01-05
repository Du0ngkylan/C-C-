/*
 * thunghiem.c
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
	struct Tree*element;
	element=(struct Tree*)malloc(sizeof(struct Tree));
		element->datum=datum;
		element->left=NULL;
		element->right=NULL;
	return element;
}

void addNode(struct Tree**root,int datum){
	if(*root==NULL){
		struct Tree*element=creatNode(datum);
		*root=element;
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
// cai ham void in() nay chi la de to check xem no chay. co dung ra cay ko thoi nhe :D
// chu ko phai ham in ra chuan dau :D
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
	struct Tree*p;
	if(root==NULL){
		return NULL;
	}
	else{
		p=root;
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

void ancestor(struct Tree*tree,int p,int q){
	struct Tree*pNode=find(root,p);
	if(pNode==NULL){
		printf("%d khong co trong cay ",p);
	}
	else{
		struct Tree*qNode=find(pNode,q);
		if(qNode==NULL){
			printf("%d khong phai la ancestor cua %d",p,q);
		}
		else{
			printf("%d la ancestor cua %d",p,q);
		}
	}
}
int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	int a[] = {3, 1, 8, 0, 2, 6, 9,5};
	int i;
	for (i = 0; i < 8; i++) {
		addNode(&root, a[i]);
	}
	in(root);
	int p,q;
	puts("");
	printf("nhap p: ");scanf("%d",&p);
	printf("nhap q: ");scanf("%d",&q);
	ancestor(root,p,q);
	return 0;
}

