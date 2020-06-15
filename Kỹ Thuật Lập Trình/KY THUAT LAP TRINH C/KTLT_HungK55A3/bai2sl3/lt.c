#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct sinhvien{
	char hoten[50];
	struct sinhvien*next;
};
struct sinhvien*list=NULL;


struct sinhvien*creatElement(char hoten[]){
	struct sinhvien*element;
	element=(struct sinhvien*)malloc(sizeof(struct sinhvien));
	if(element!=NULL){
		strcpy(element->hoten,hoten);
		element->next=NULL;
	}
	return element;
}

struct sinhvien*addElement(struct sinhvien*list,char hoten[]){
	struct sinhvien*element=creatElement(hoten);
	if(element==NULL){
		return list;
	}
	else{
		element->next=list;
		return element;
	}
}

struct sinhvien*doctep(int *n){
	FILE*f;
	f=fopen("sv","r");
	if(!f){
		puts("ERRROR");
		exit(0);
	}
	fscanf(f,"%d",n);
	fscanf(f,"\n");
	int i;
	char hoten[50];
	for(i=0;i<*n;i++){
		fflush(stdin);
		fgets(hoten,50,f);
		int l;
		l=strlen(hoten);
		hoten[l-1]='\0';
		list=addElement(list,hoten);
	}
	fclose(f);
	return list;
}

void in(struct sinhvien*list){
	struct sinhvien*p;
	for(p=list;p!=NULL;p=p->next){
		printf("%s==> ",p->hoten);
	}
	printf("%s",p->hoten);
	puts("");
}

struct sinhvien*sort(struct sinhvien*list){
	struct sinhvien*p,*q;
	for(p=list;p->next!=NULL;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(strcmp(p->hoten,q->hoten)>0){
				char temp[50];
				strcpy(temp,p->hoten);
				strcpy(p->hoten,q->hoten);
				strcpy(q->hoten,temp);
			}
		}
	}
	return list;
}

int search(struct sinhvien*p){
	int dem=0;
	char ten[50];
	printf("nhap vao ten can tim: ");
	fflush(stdin);
	gets(ten);
	for(p=list;p!=NULL;p=p->next){
		dem++;
		if(strcmp(ten,p->hoten)==0)return dem;
	}
	return -1;

}

struct sinhvien*insert(struct sinhvien*list){
	struct sinhvien*p;
	char ten[50];
	printf("nhap vao ten can chen: ");
	fflush(stdin);
	gets(ten);
	struct sinhvien*element=creatElement(ten);
	p=list;
	if(strcmp(element->hoten,p->hoten)<0){
		element->next=list;
		return element;
	}
	for(p=list;p!=NULL;p=p->next){
		if(strcmp(element->hoten,p->next->hoten)<0){
			element->next = p->next;
			p->next=element;
			return list;
		}
	}
	return list;
}
void ListDelete(struct sinhvien **list)
{
	struct sinhvien *p, *q;
	char ten[50];
	printf("Nhap ten:\t");
	gets(ten);
	q = NULL;
	for(p=*list;p!=NULL;p=p->next){
		q = p;
		if(strcmp((p->hoten),ten) == 0){
			if(q == NULL)
				*list = p->next;
			else
				q->next = p->next;
				free(p);
		}
	}
}
void freedom(struct sinhvien*list){
	struct sinhvien **p = (struct sinhvien **)malloc(sizeof(struct sinhvien*));
	struct sinhvien *q = (struct sinhvien*)malloc(sizeof(struct sinhvien));
	*p = list;
	while(*p!=NULL){

		q = (*p)->next;
		free(*p);
		*p = q;
	}
}


int main(){
	int n;
	list=doctep(&n);
	in(list);
	printf("list sau khi da sap xep la: \n");
	list=sort(list);
	in(list);
	int kq=search(list);
	if(kq>0){
		printf("co ten do trong danh sach va no nam o vi tri %d\n",kq);
	}
	else{
		printf("ko co trong ds \n");
	}
	list=insert(list);
	in(list);
	ListDelete(&list);

	in(list);
	freedom(list);
	in(list);


	return 0;
}





