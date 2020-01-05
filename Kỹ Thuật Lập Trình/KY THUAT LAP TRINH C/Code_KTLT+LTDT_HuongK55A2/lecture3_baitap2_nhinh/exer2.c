/*
 * exer2.c
 *
 *  Created on: Oct 10, 2012
 *      Author: vannhinh
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
struct Node {
	char name[30];
	struct Node *next;
};
void tb(char *s) {
	puts(s);
	exit(0);
}
struct Node *doctep() {
	FILE *f;
	int i, n;
	char s[100];
	f = fopen("ds.txt", "r");
	if (!f)
		tb("loi mo tep");
	struct Node *p, *list;
	fscanf(f, "%d", &n);
	list = NULL;
	for (i = 0; i < n; i++) {
		fgets(s, 100, f);
		if(s[strlen(s)-1]=="\n"){
			s[strlen(s)-1]=0;
		}
		p = (struct Node*) malloc(sizeof(struct Node));
		strcpy(p->name, s);
		p->next=list;
		list = p;
	}
	return list;
	fclose(f);
return 0;

}

void inds(struct Node* list) {
	struct Node *p;
	if (list == NULL) {
		printf("ds rong\n");
		return;
	} else {
		for (p = list; p != NULL; p = p->next)
			printf("%20s\n", p->name);
	}
}

void sapxep(struct Node *list) {
	char t[100];
	struct Node *p, *q;

	for (p = list; p->next != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next) {
			if (strcmp(p->name, q->name) >= 0) {
				strcpy(t, p->name);
				strcpy(p->name, q->name);
				strcpy(q->name, t);
			}
		}
	}
}
struct Node *themnode(struct Node* list, char ten[]) {
	struct Node *p;
	p = (struct Node*) malloc(sizeof(struct Node));
	if (p == NULL) {
		printf("Cap phat lai\n");
		exit(0);
	}
	strcpy(p->name, ten);
	p->next = list;
	list = p;
	return list;
}
struct Node *them(struct Node *list, char ten[30]) {
	struct Node *p, *q;
	q = (struct Node*) malloc(sizeof(struct Node));
	strcpy(q->name, ten);
	if (list == NULL) {
		p = (struct Node*) malloc(sizeof(struct Node));
		list = themnode(p, q->name);
		return list;

	} /*else {
	 if (strcmp(ten, list->name) <= 0) {
	 p = themnode(list, ten);
	 p->next = list;
	 return list;
	 } else {
	 for (p = list; p != NULL; p = p->next) {
	 if (strcmp(q->name, p->name) >= 0) {
	 p->next = q;
	 q->next = p->next;
	 }
	 }
	 }
	 }*/
	for (p = list; p != NULL; p = p->next)
		if (strcmp(p->name, q->name) < 0
				&& strcmp(p->next->name, q->name) > 0) {
			q->next = p->next;
			p->next = q;
		}
	return list;

	return 0;
}
struct Node* tim(struct Node* list, char ten[]) {
	struct Node *p;
	if (list == NULL) {
		printf("ds rong\n");
	}
	for (p = list; p != NULL; p = p->next) {
		if (strcmp(p->name, ten) == 0)
			return p;
	}
	return 0;
}
struct Node* deleteNode(struct Node *list) {
	struct Node *p; char ten[50];
	printf("nhap ten can xoa:");
	fflush(stdin);
		gets(ten);
	if (list == NULL)
		return NULL;
	while (strcmp(ten, list->name) == 0) {
		printf("co\n");
		list = list->next;
		free(list);

	}
	/*for (p = list; p->next!= NULL;) {
	 if (strcmp(ten, p->name) == 0) {
	 q = p->next;
	 p->next = q->next;
	 } else
	 p = p->next;

	 }
	 return list;
	 //return 0;*/
	for (p = list; p->next != NULL;) {
		if (strcmp(ten, p->next->name) == 0) {
			struct Node*q;
			//q = (struct Node*) malloc(sizeof(struct Node));
			q=p->next;
			p->next=q->next;
			free(q);
		}
		else
			p=p->next;
	}
return list;

}

int main() {
	setbuf(stdout, NULL);
	char s[100];
	struct Node *list;
	list = NULL;
	list = doctep();
	inds(list);
	printf("\ndanh sach sau khi sap xep la:\n");
	sapxep(list);
	inds(list);
	printf("nhap ten sv can chen:");
	fflush(stdin);
	gets(s);
	list = them(list, s);
	printf("\ndanh sach sau khi them pt la:\n");
	inds(list);
	printf("nhap ten sv can tim:");
	//fflush(stdin); //xoa phan con lai cua dong//
	gets(s);
	struct Node*vt = tim(list, s);
	if (vt != NULL)
		printf("\ncon tro vt dang tro toi sv \"%s\" dau tien duoc tim thay\n",
				s);
	else
		printf("ko tim thay sv nao co ten nhu vay\n");

	list = deleteNode(list);
	printf("ds sau  khi xoa\n");
	inds(list);

	return 0;
}
