#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nguyento{
	
	int songuyento;
	struct nguyento*next;
};
struct nguyento*list=NULL;
struct nguyento *pRear = NULL;


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

struct nguyento*enqueue(int songuyento){
	struct nguyento*element;
	element = (struct nguyento*)malloc(sizeof(struct nguyento));
	element->songuyento = songuyento;
	element->next=NULL;
	if(pRear!=NULL){
		pRear->next=element;
	}
	else{
		list =element;
	}
	pRear=element;
	return list;
}

struct nguyento*creatList(int n){
	int i;
	for(i=2;i<=n;i++){
		if(songuyento(i)==1){
			list=enqueue(i);
		}
	}
	return list;
}

void in(struct nguyento*list){
	struct nguyento*p;
	for(p=list;p!=NULL;p=p->next){
		printf("%5d",p->songuyento);
	}
}


int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	int n;
	struct nguyento*a;
	printf("nhap vao so n bat ki : ");scanf("%d",&n);
	printf("so nguyen to nho hon hoac bang %d la : ",n);
	a=creatList(n);
	in(a);
	return 0;
}
