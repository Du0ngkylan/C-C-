/*
 * main.c
 *
 *  Created on: october 28, 2012
 *      Author: ThanhMeo
 */
/*
 * Do dang ban thi nen chi lam toi day.
 * Moi nguoi cham cuu nha va tu hoan thien theo so thich .
 */
#include "stdio.h"
#include "linklist.h"
int main(int argc, char **argv) {
	setvbuf(stdout, NULL, _IONBF, 0);
	struct Student *listStudent = NULL; //KHOI TAO DANH SACH RONG
	//listStudent = createList(); // PHAN 1
	listStudent = readFile("data.txt");
	printList(listStudent); // in danh sach
	sortList(listStudent); // sap xep danh sach khi can thiet
	printList(listStudent); //in sau sap xep
	char name[] = "chi"; //Ten ma muon kiem tra trong Phan 2
	struct Student *p;
	p = searchName(listStudent, name); //tim ten tra lai vi tri cua ten neu tim thay va null nguoc lai
	if (p != NULL) { //khac thi thay
		printf("Co\n");
		p->dtb += (p->dtb * 0.1); //cap nhat diem
	} else {
		printf("Khong co!\n");
		listStudent = addEnd(listStudent, name, 0.00); //them vao cuoi
	}
	printList(listStudent); //in lai danh sach sau cap nhat
	listStudent = delList(listStudent); //giai phong danh sach
	printf("\nSau khi giai phong danh sach la:\n");
	printList(listStudent);
	return 0;
}
