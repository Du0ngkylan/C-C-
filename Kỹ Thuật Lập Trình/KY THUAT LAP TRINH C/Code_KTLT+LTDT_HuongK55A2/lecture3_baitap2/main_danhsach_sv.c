/*
 * main_danhsach_sv.c
 *
 *  Created on: Oct 11, 2012
 *      Author: NgoHuong
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "danhsach_sv.h"

int main ()
{
	setbuf(stdout, NULL);
	struct Node *list, *p, *q;
	list == NULL;
	p= readList(list);
	printf("\nDanh sach sinh vien co trong tep la:\n");
	in_ds(p);
	sortList(p);
	printf("\nDanh sach sinh vien sau khi sap xep la:\n");
	in_ds(p);
	list = insertNode(list);
	printf("\nDanh sach khi them vao la:\n");
	list = deleteNode(list);
	printf("\nDanh sach khi xoa la:\n");
	in_ds(list);
	return 0;
}
