/*
 * main.c
 *
 *  Created on: Oct 20, 2012
 *      Author: MSS THUY
 */
#include<stdio.h>
#include<stdlib.h>
#include"caynhiphan.h"
int main(int argc, char **argv) {
	setvbuf(stdout,NULL,_IONBF,0);
	Tree root = NULL;
	int a[] = { 3, 1, 8, 0, 2, 6, 9, 5 };
	int i;
	puts("thuy");
	for (i = 0; i < 8; i++) {
		addTree(&(root), a[i]);
	}
	postorder(root);
	if (ancestor(root, 3, 8) != 0) {
		puts("co\n");
	} else
		puts("ko\n");
	int m = sizeofnode(root, 9);
	printf("%d", m);
	return 0;
}
