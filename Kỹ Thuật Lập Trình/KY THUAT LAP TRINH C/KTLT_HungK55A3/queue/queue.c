#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nguyento{
	int songuyento;
	struct nguyento*next;
};

struct nguyento*list=NULL;
struct nguyento *pRear = NULL;

struct nguyento* enqueue(int songuyento) {
	struct nguyento *element = (struct nguyento*)malloc(sizeof(struct nguyento));
	element->songuyento = songuyento;
	element->next = NULL;
	if (pRear != NULL) {
		pRear->next = element;
	} else {
		list = element;
	}
	pRear = element;
	return list;
}

struct nguyento *addElement(struct nguyento*list,int songuyento){
	struct nguyento*element = enqueue(songuyento);
	if(element==NULL){
		return list;
	}
	else{
		element->next=list;
		return element;
	}
}

int songuyento(int n){
	int i;
	if(n<=1){
		return 0;
	}
	else{
		for(i=2;i<n;i++){
			if(n%i==0){
				return 0;
			}
		}
		return 1;
	}
}

struct nguyento*taodanhsachsonguyento(int n,struct nguyento*list){
	int i;
	for(i=1;i<=n;i++){
		if(songuyento(i)==1){
			list=addElement(list,i);
		}

	}
	return list;
}

void indanhsach(struct nguyento*list){
	struct nguyento*p;
	for(p=list;p!=pRear;p=p->next){
		printf("%5d",p->songuyento);
	}
}

int main(){
	int n;
	struct nguyento*a;
	printf("nhap vao so n bat ki : ");scanf("%d",&n);
	printf("so nguyen to nho hon hoac bang %d la : ",n);
	a=taodanhsachsonguyento(n,list);
	indanhsach(a);
	return 0;
}
