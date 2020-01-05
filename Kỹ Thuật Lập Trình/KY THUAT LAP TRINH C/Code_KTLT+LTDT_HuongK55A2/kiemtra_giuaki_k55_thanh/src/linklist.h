/*
 * linklist.h
 *
 *  Created on: october 28, 2012
 *      Author: ThanhMeo
 */
#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef struct Student {
	char name[20];
	float dtb;
	struct Student *next;
} Student;

struct Student* createElement(char[], float);//ham tao 1 phan tu
struct Student* addElement(struct Student*, char[], float);//ham them 1 phan tu vao dau danh sach
struct Student* addEnd(struct Student*, char[], float);//ham them phan tu vao cuoi danh sach
struct Student* readFile(char *);//Truong hop doc tep thi su dung
struct Student* createList();//ham tao danh sach sinh vien
struct Student* delList(struct Student *);//ham xoa danh sach
void printList(struct Student *);//ham in danh sach
int compare(void*, void*);//ham so sanh khi can thiet
void sortList(struct Student *);//ham sap xep danh sach
struct Student *searchName(struct Student*, char[]);//ham tim kiem ten trong danh sach
#endif /* LINKLIST_H_ */
