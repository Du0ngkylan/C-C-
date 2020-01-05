/*
 * countNode.c
 *
 *  Created on: Nov 28, 2012
 *      Author: ADMIN
 */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "tree.h"


int dem_nut_la(Tree tree) {
	if (tree == NULL )
		return 0;
	else if (tree->left != NULL || tree->right != NULL )
		return dem_nut_la(tree->left) + dem_nut_la(tree->right);
	else
		return 1;
}

int dem_nut_tg(Tree parent, Tree tree) {
	if (tree == NULL )
		return 0;
	else if (tree->left == NULL && tree->right == NULL )
		return 0;
	else {
		if (parent != NULL )
			return dem_nut_tg(tree, tree->left) + dem_nut_tg(tree, tree->right)
					+ 1;
		else
			return dem_nut_tg(tree, tree->left) + dem_nut_tg(tree, tree->right);
	}
}

int dem_nut(Tree tree) {
	if (tree == NULL )
		return 0;
	else
		return dem_nut(tree->left) + dem_nut(tree->right) + 1;
}

int dem_nut_rong(Tree tree) {
	if (tree == NULL )
		return 1;
	else
		return dem_nut_rong(tree->left) + dem_nut_rong(tree->right);
}

int dem_nut_day_du(Tree tree) {
	if (tree == NULL )
		return 0;
	else if (tree->left != NULL && tree->right != NULL )
		return dem_nut_day_du(tree->left) + dem_nut_day_du(tree->right) + 1;
	else
		return dem_nut_day_du(tree->left) + dem_nut_day_du(tree->right);
}
