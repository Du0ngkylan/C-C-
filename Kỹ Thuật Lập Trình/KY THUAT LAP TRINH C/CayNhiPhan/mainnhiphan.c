#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}*TREE;

TREE create(int data) {
	TREE node = (TREE) malloc(sizeof(struct node));
	if (node != NULL) {
		node->data=data;;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}


TREE add(TREE root, int data) {
	TREE node = create(data);
	if (node == NULL)
		return root;
	else {
		if (root == NULL)
			return node;
		else {
			TREE p = root;
			while (p != NULL) {
				if (data == p->data)
					return root;
				else {
					if (data < p->data) {
						if (p->left == NULL) {
							p->left = node;
							return root;
						} else {
							p = p->left;
						}
					} else {
						if (p->right == NULL) {
							p->right = node;
							return root;
						} else
							p = p->right;
					}
				}
			}
		}
	}
	return root;
}

TREE creatTree(TREE root){
	int i,data, n;
	FILE *f;
	f=fopen("tep.txt","r");
	if(!f){
		puts("loi mo tep.");
		exit(0);
	}
	fscanf(f,"%d",&n);
	for(i=1;i<=n;i++){
		fscanf(f,"%d",&data);
		root=add(root,data);
	}
	fclose(f);
	return root;
}

void visitTree(TREE root){
	if(root!=NULL){
		printf("%4d\t",root->data);
		visitTree(root->left);
		visitTree(root->right);

	}
}

int find(TREE root,int data){
	TREE p=root;
	while(p!=NULL){
		if(data==p->data)
			return 1;
		else{
			if(data<p->data)
				p=p->left;
			else
				p=p->right;
		}
	}
	return 0;
}

int test(TREE root,int data){
	TREE p=root;
	int h=0;
	while(p!=NULL){
		if(data==p->data)
			return h;
		else{
			if(data<p->data)
				p=p->left;
			else
				p=p->right;
		}
		h++;
	}
	return -1;
}


int ancessor(TREE root,int p,int q){
	TREE dad=NULL;
	TREE x=root;
	int i,j;
	i=test(root,p);
	j=test(root,q);
	if(i==-1||j==-1||i==j)
		return 0;
	if(i<j){
		while(x!=NULL){
			if(x->data==p){
				dad=x;
				break;
			}
			else{
				if(x->data>p)
					x=x->left;
				else
					x=x->right;
			}
		}
		while(dad!=NULL){
			if(dad->data>q)
				return 1;
			else {
				if(q<dad->data)
					dad=dad->left;
				else
					dad=dad->right;
			}
		}
	}
	else{
		while(x!=NULL){
					if(x->data==q){
						dad=x;
						break;
					}
					else{
						if(x->data>q)
							x=x->left;
						else
							x=x->right;
					}
				}
				while(dad!=NULL){
					if(dad->data>p)
						return 1;
					else {
						if(p<dad->data)
							dad=dad->left;
						else
							dad=dad->right;
					}
				}
			}
	}


int main(){
	setbuf(stdout,NULL);
	int p=0;
	TREE root=NULL;
	root=creatTree(root);
	visitTree(root);
	p=ancessor(root,3 ,5);
	if(p==1)
		puts("ko");
	else
		puts("co");
	p=find(root,2);
	if(p==0)
		puts("khong tim thay");
	else
		puts("co ton tai trong tep");
	return 0;

}
