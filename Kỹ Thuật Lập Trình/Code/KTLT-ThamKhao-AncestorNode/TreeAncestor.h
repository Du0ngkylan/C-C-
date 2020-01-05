/*
 * TreeAncestor.h
 *
 *  Created on: Nov 12, 2012
 *      Author: ADMIN
 */

#ifndef TREEANCESTOR_H_
#define TREEANCESTOR_H_

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node *Tree;

Tree createNode(int);
Tree addNode(Tree, int);
Tree find(Tree, int);
void ancestor(Tree, int, int);

#endif /* TREEANCESTOR_H_ */
