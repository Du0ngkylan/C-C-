#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}*TREE;

TREE create(int data){
	TREE node=(TREE)malloc(sizeof(struct node));
	if(node!=NULL){
		node->data=data;
		node->left=NULL;
		node->right=NULL;
	}
	return node;
}

TREE add(TREE root,int data){
	TREE node=create(data);
	if(node==NULL)
		return root;
	else{
		if(root==NULL)
			return node;
		else{
			TREE p=root;
			while(p!=NULL){
				if(data==p->data)
					return root;
				else{
					if(data<p->left){
						if(p->left==NULL){
							p->left=node;
							return root;
						}
						else{
							p=p->left;
						}
					}
					else{
						if(p->right==NULL){
							p->right=node;
							return root;
						}
						else
							p=p->right;
					}
				}
			}
		}
	}
	return root;
}

TREE createTree(TREE root){
	int n,i,data;
	FILE *f;
	f=fopen("tep.txt","r");
	if(!f){
		puts("loi mo tep");
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
		visitTree(root->right);
		printf("%4d",root->data);
		visitTree(root->left);
	}
}

int main(){
	TREE root=NULL;
	createTree(root);
	visitTree(root);
	return 0;
}
