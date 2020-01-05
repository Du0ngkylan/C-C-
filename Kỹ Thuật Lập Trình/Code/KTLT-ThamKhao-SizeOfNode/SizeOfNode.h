/*
 * SizeOfNode.h
 *
 *  Created on: Nov 12, 2012
 *      Author: ADMIN
 */

#ifndef SIZEOFNODE_H_
#define SIZEOFNODE_H_

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node *Tree;
int sizeOfNode(Tree, int);
int sizeOfTree(Tree);
Tree find(Tree, int);
Tree addNode(Tree, int);
Tree createNode(int);

#endif /* SIZEOFNODE_H_ */
