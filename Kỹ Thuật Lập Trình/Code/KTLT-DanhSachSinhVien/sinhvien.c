/*
 * sinhvien.c
 *
 *  Created on: Oct 30, 2012
 *      Author: ADMIN
 */
#include "sinhvien.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

node *createElement(char data[20],int d) {
	node *element = (node *) malloc(sizeof(node));
	if (element != NULL) {
		strcpy(element->data, data);
		element->diem = d;
		element->tanso = 1;
		element->next = NULL;
	}
	return element;
}

node *addElement(node *head, char *data,int d) {
	node *element = createElement(data,d);
	if (element != NULL) {
		if (head != NULL) {
			node *p;
			//Tim trong head xem da co data?
			//Neu co roi, thi tang tan so lan va tra ve head
			for (p = head; p != NULL; p = p->next) {
				if (strcmp(p->data, data) == 0) {
					p->tanso++;
					return head;
				}
			}
			element->next = head;
		}
		return element;
	} else {
		return NULL;
	}
}

node *doctep(node *head) {
	//char z[30];
	char s[30];
	int d;
	//printf("nhap ten tep:\t");
	//gets(z);
	FILE *f;
	f = fopen("sv.txt", "r");
	if (!f) {
		printf("loi mo tep");
		exit(0);
	}
	while (!feof(f)) {
		//s[strlen(s) - 1] = 0;
		fscanf(f,"%d",&d);
		fgets(s, 30, f);

		//fscanf(f, "%s", s);
		head = addElement(head, s,d);
	}
	return head;
}

void printQueue(node *head) {
	node *p = head;
	while (p != NULL) {
		printf("%s", p->data);
		printf("%d\n",p->diem);
		p = p->next;
	}
	printf("\n");
}

node *sapxep(node *head) {
	node *p;
	char k[20];
	node *q;
	for (p = head; p != NULL; p = p->next)
		for (q = p->next; q != NULL; q = q->next)
			if (strcmp(p->data, q->data) > 0) {
				strcpy(k, p->data);
				strcpy(p->data, q->data);
				strcpy(q->data, k);
			}

	return head;
}

node *xoa(node *head, char *x) {
	if (head == NULL)
			return NULL;
		if (strcmp(head->data, x) == 0) {
			head = head->next;
			return head;
		}

		node *p = head;
		while (p->next != NULL) {
			if (strcmp(p->next->data, x) == 0) {
				p->next = p->next->next;
				return head;
			}
			p=p->next;
		}
		return head;
}

void in(node *head) {
	node *q = head;
	while (q != NULL) {
		printf("%s\t", q->data);
		printf("%d\n", q->tanso);
		q = q->next;
	}
}

node *chen(node *head, char x[30]) {
	if (head == NULL) {
		head = createElement(x);
		return head;
	}
	node *p = head, *q;
	if (strcmp(p->data, x) > 0) {
		q = createElement(x);
		q->next = p;
		return q;
	}
	for (p = head; p->next != NULL; p = p->next) {
		if (strcmp(p->next->data, x) > 0) {
			q = createElement(x);
			q->next = p->next;
			p->next = q;
			return head;
		}
	}
	while (p->next != NULL) {
		p = p->next;
	}
	q = createElement(x);
	p->next = q;
	return head;
}



