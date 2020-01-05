/*
 * tree.h
 *
 *  Created on: Nov 7, 2012
 *      Author: student
 */

#ifndef TREE_H_
#define TREE_H_

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node *Tree;

void addNode(Tree *, int);
void visit(Tree);
void preOrder(Tree);
void postOrder(Tree);
void inOrder(Tree);

//void NLR(Tree);
void NRL(Tree);
//void LNR(Tree);
//void LRN(Tree);
void RNL(Tree);
void RLN(Tree);

int dem_nut_la(Tree);
int dem_nut_tg(Tree, Tree);
int dem_nut_rong(Tree);
int dem_nut(Tree);
int dem_nut_day_du(Tree);

int chieucao(Tree, int);
int compare(int, int);

void ancestor(Tree, int, int);
Tree find(Tree, int);

int sizeOfNode(Tree, int);
int sizeOfTree(Tree);
Tree find(Tree, int);
#endif /* TREE_H_ */
