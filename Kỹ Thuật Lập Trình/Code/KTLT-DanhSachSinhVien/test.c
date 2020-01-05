/*
 * test.c
 *
 *  Created on: Oct 31, 2012
 *      Author: ADMIN
 */
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
		p = p->next;
	}
	return head;
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

void printQueue(node *head) {
	node *p = head;
	while (p != NULL) {
		printf("%s", p->data);
		printf("%d\n", p->diem);
		p = p->next;
	}
	printf("\n");
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
		fscanf(f, "%d", &d);
		fgets(s, 30, f);

		//fscanf(f, "%s", s);
		head = addElement(head, s, d);
	}
	return head;
}

sv *create(char s[], int d) {
	sv* sinhvien = (sv*) malloc(sizeof(sv));
	if (sinhvien != NULL) {
		strcpy(sinhvien->ten, s);
		sinhvien->diem = d;
		sinhvien->next = NULL;
	}
	return sinhvien;
}

sv *add(sv* head, char s[], int d) {
	sv* sinhvien;
	sinhvien = create(s, d);
	if (sinhvien != NULL) {
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
	puts(
			"bat dau nhap danh sach\n Nhan phm bat ky de nhap tiep\n Nhan 0 de dung lai.");
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

void search(sv* head, char s[]) {
	sv *p, *q;
	int i = 0;
	printf("Dang tim kiem ten %s \n", s);
	for (p = head; p != NULL; p = p->next) {
		if (strcmp(p->ten, s) == 0) {
			puts("Da tim thay. Dag sua diem.");
			p->diem = p->diem * 1, 1;
			i++;
		}
	}
	if (i == 0) {
		puts("khong tim thay . dang khoi tao");
		for (p = head; p != NULL; p = p->next)
			if (p->next == NULL) {
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
	while (head != NULL) {
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
	while (p != NULL) {
		p = p->next;
		free(head);
		head = p;
	}
	if (head == NULL)
		puts("\nda xoa xong danh sach");
}

