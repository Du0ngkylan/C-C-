/*
 * caynhiphan.h
 *
 *  Created on: Oct 20, 2012
 *      Author: MSS THUY
 */

#ifndef CAYNHIPHAN_H_
#define CAYNHIPHAN_H_
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
} node;
typedef struct node *Tree;
Tree createTree(int data);
void addTree(Tree *,int  );
void visit(Tree root);
void postorder(Tree root);
int ancestor(Tree,int ,int);
int sizeofnode(Tree ,int);
int depthofTree(Tree);
int fullTree(Tree);
int checkPerfect(Tree,int ,int);
int perfect(Tree);
int isLeaf(Tree );
int sizofTree(Tree);
#endif /* CAYNHIPHAN_H_ */
