/*
 * sinhvien.c
 *
 *  Created on: Oct 31, 2012
 *      Author: ADMIN
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sinhvien {
	char ten[30];
	int diem;
	struct sinhvien *next;
} sv;

sv *create(char s[], int d) {
	sv* sinhvien = (sv*) malloc(sizeof(sv));
	if (sinhvien != NULL ) {
		strcpy(sinhvien->ten, s);
		sinhvien->diem = d;
		sinhvien->next = NULL;
	}
	return sinhvien;
}

sv *add(sv* head, char s[], int d) {
	sv* sinhvien;
	sinhvien = create(s, d);
	if (sinhvien != NULL ) {
		sinhvien->next = head;
		return sinhvien;
	} else {
		return head;
	}
}

sv* createList(sv* head) {
	char s[30];
	float d;
	int i = 1;
	int j = 0;
	puts("bat dau nhap danh sach\n Nhan phm bat ky de nhap tiep\n Nhan 0 de dung lai.");
	do {
		if (j == 1) {
			scanf("%d", &j);
			if (j == 0)
				break;
		}
		printf("Nhap ten sinh vien thu %d: ", i);
		fflush(stdin);
		gets(s);
		fflush(stdout);
		printf("Nhap diem sinh vien thu %d: ", i);
		scanf("%f", &d);
		head = add(head, s, d);
		//j = 1;
		i++;
	} while (j == 1);
	return head;
}

sv *doctep(sv *head) {
	//char z[30];
	char s[30];
	int mark;
	//printf("nhap ten tep:\t");
	//gets(z);
	FILE *f;
	f = fopen("sv.txt", "r");
	if (!f) {
		printf("loi mo tep");
		exit(0);
	}
	while (!feof(f)) {
		fgets(s, 30, f);
		fscanf(f, "%d", &mark);
		//fscanf(f, "%s", s);
		head = add(head, s, mark);
		//s[strlen(s) - 1] = 0;
	}
	return head;
}

void search(sv* head, char s[]) {
	sv *p, *q;
	int i = 0;
	printf("Dang tim kiem ten %s \n", s);
	for (p = head; p != NULL ; p = p->next) {
		if (strcmp(p->ten, s) == 0) {
			puts("Da tim thay. Dag sua diem.");
			p->diem = p->diem * 1, 1;
			i++;
		}
	}
	if (i == 0) {
		puts("khong tim thay . dang khoi tao");
		for (p = head; p != NULL ; p = p->next)
			if (p->next == NULL ) {
				q = create(s, 0);
				p->next = q;
				return;
			}
	}
}
sv*invert(sv*head) {
	sv*p = NULL, *q;
	q = head;
	puts("dang dao nguoc dang sach sinh vien");
	while (head != NULL ) {
		q = head->next;
		head->next = p;
		p = head;
		head = q;
	}
	return p;
}
void freelist(sv*head) {
	sv*p;
	p = head;
	puts("\ndang xoa danh sach");
	while (p != NULL ) {
		p = p->next;
		free(head);
		head = p;
	}
	if (head == NULL )
		puts("\nda xoa xong danh sach");
}
void print(sv*head) {
	sv*p;
	p = head;
	while (p != NULL ) {
		/*printf("%20s%6.1f",p->ten,p->diem);*/
		printf("%s\n",p -> ten);
		printf("%d", p->diem);
		p = p->next;
		puts("");
	}
}
int main(int argc, char **argv) {
	setbuf(stdout,NULL);
	sv*head=NULL;
	//char s[30];
	//strcpy (s,"nam");
	head = doctep(head);
	//head=createList(head);
	print(head);
	//search(head,s);
	head=invert(head);
	print(head);
	freelist(head);
	return 0;
}
