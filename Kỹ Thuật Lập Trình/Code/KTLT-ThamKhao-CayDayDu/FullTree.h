/*
 * FullTree.h
 *
 *  Created on: Nov 12, 2012
 *      Author: ADMIN
 */

#ifndef FULLTREE_H_
#define FULLTREE_H_

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node *Tree;
int isFull(Tree);
Tree addNode(Tree, int);
Tree createNode(int);

#endif /* FULLTREE_H_ */
