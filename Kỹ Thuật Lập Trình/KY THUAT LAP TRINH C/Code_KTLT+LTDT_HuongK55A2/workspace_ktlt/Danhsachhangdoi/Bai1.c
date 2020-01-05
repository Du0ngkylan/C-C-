/*
 * Bai1.c
 *
 *  Created on: Oct 6, 2012
 *      Author: Windows7
 */
#include<stdio.h>
#include<stdlib.h>
struct node{
	int  x;
	struct  node * next;
};
int ngto(int k){
	int i;
	if(k<2) return 0;
	for(i=2;i<k;i++){
		if(k%i==0) return 0;
	}
	return 1;
}
struct node*taonut(int a){
	struct node*nut=(struct node*)malloc(sizeof(struct node));
	if(nut!=NULL){
		nut->x=a;
		nut->next=NULL;
	}
	return nut;
}
struct node*themvao(struct node*head,int  y){
	struct node*nut=taonut(y);
	if(nut==NULL){
		return head;
	}else{
		nut->next=head;
		head=nut;
		return head;
	}

}
struct node*taods(struct node*head,int n){
	int i;
	for(i=n;i>0;i--){
		if(ngto(i)==1){
			head=themvao(head,i);
		}
	}
	return head;
}
struct node* dao(struct node* head) {
	struct node *p = NULL;
	//head = taods(head, n);
	while (head != NULL) {
		struct node *q;
		q = head;
		head  = head->next;
		q->next = NULL;//lay rieng q
		if( p != NULL) {
			q->next = p;
		}
		p = q;
	}
	return p;

}
void in(struct node*head){
	struct node *p;
	if(head==NULL){
		printf("Danh sach rong");
	}else{
		for(p=head;p!=NULL;p=p->next)
			printf("%2d",p->x);
	}

}

struct node*xoa(struct node*list){
	struct node *p;
	if(list!=NULL){
		p=list;
		list=p->next;
		free(p);
	}
	return list;
}
int main(){
	setbuf(stdout,NULL);
	int n;
	struct node*head=NULL;
//	struct node*k;
//	struct node*a;
	printf("nhap n="); scanf("%d",&n);
	head= taods(head,n);
	printf("Danh sach cac so nguyen to nho hon %d la:\n",n);
	in(head);
	head = dao(head);
	printf("\nDanh sach sau khi dao nguoc la: \n");
	in(head);

	return 0;
}



