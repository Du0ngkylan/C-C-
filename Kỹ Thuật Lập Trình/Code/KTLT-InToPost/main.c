/*
 * main.c
 *
 *  Created on: Nov 14, 2012
 *      Author: ADMIN
 */
#include <stdio.h>
#include <conio.h>
#include "IntoPost.h"

int main(int argc, char **argv) {
	setvbuf(stdout,NULL,_IONBF,0);
	int n;
	n = DocDuLieu("input.txt");
	Change(n);
	return 0;
}

