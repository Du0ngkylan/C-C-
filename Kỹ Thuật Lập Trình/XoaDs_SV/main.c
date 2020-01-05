/*
 * main.c
 *
 *  Created on: Oct 29, 2012
 *      Author: Tienngo
 */

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sv {
	char name[30];
	float dtoan;
	float dtin;
	struct sv *next;
} SV;
int n;

SV *create(char s[], float dtoan, float dtin) {
	SV *st = (SV*) malloc(sizeof(SV));
	if (st != NULL) {
		strcpy(st->name, s);
		st->dtin = dtin;
		st->dtoan = dtoan;
		st->next = NULL;
	}
	return st;
}

SV *add(SV *head, char s[], float dtoan, float dtin) {
	SV *st = create(s, dtoan, dtin);
	if (st != NULL) {
		st->next = head;
		return st;
	} else
		return head;
}

/*SV *list(SV *head,int n){
 int i;
 char s[30];
 float dtoan;
 float dtin;
 for(i=1;i<=n;i++){
 printf("nhap vao ten cua sv thu %d\n",i);
 fflush(stdin);
 gets(s);
 printf("nhap diem toan\n");
 scanf("%f",&dtoan);
 printf("nhap diem tin\n");
 scanf("%f",&dtin);
 head=add(head,s,dtoan,dtin);
 }
 return head;
 }
 */
SV *list(SV *head) {
	int i;
	char s[50];
	float dtoan;
	float dtin;
	FILE *f;
	f = fopen("ds.txt", "r");
	if (!f) {
		puts("loi mo tep.");
		exit(0);
	}
	fscanf(f, "%d", &n);
	fgets(s, 50, f);

	for (i = 0; i < n; i++) {
		fgets(s, 50, f);
		if (s[strlen(s) - 1] == '\n')
			s[strlen(s) - 1] = 0;
		fscanf(f, "%f", &dtoan);
		fscanf(f, "%f", &dtin);
		head = add(head, s, dtoan, dtin);
		fgets(s, 50, f);
	}
	fclose(f);
	return head;
}

/*void print(SV *head){
 SV *p=head;
 int i;
 for(i=1;i<=n;i++){
 printf("%30s%6.1f%6.1f\n",p->name,p->dtoan,p->dtin);
 p=p->next;
 }
 //	puts("");

 }*/

void print(SV *head) {
	SV *p = head;
	while (p != NULL) {
		printf("%20s%6.1f%6.1f\n", p->name, p->dtoan, p->dtin);
		p = p->next;
	}
//	puts("");
}

void freeList(SV *head) {
	SV *p = head;
	int i;
	for (i = 1; i <= n; i++) {
		p = p->next;
		free(head);
		head = p;
	}
	if (head == NULL)
		puts("danh sach da duoc xoa.");
	else
		puts("ds chua duoc giai phong.");
}

int main() {
	setbuf(stdout, NULL);
//	int n;
//	puts("nhap vao so luong sinh vien");
//	scanf("%d",&n);
	SV *head = NULL;
	head = list(head);
	print(head);
	freeList(head);
	return 0;
}
