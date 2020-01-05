/*
 * StackListName.c
 *
 *  Created on: Jan 9, 2013
 *      Author: BlueWhale
 */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//Khai bao mot nut
struct wordStruct{
	char word[20];//Tu co trong van ban
	int numWord;//So tu lap lai trong van ban
	struct wordStruct * next;//Con tro tro vao not tiep theo
};

struct wordStruct * stackWord = NULL;//Nut dau tien cua stack

//Khoi tao mot nut co chua tu wordElement va co so tu bang 1
struct wordStruct * createElement(char wordElement[20]){
	struct wordStruct * element = (struct wordStruct *) malloc (sizeof(struct wordStruct));
	if (element != NULL){
		strcpy(element->word,wordElement);
		element->numWord = 1;
		element->next = NULL;
		return element;
	}
	return NULL;
}

//Them mot tu wordElement vao stack
void push (char wordElement[20]){
	struct wordStruct * element = createElement(wordElement);
	if (element != NULL){
		element->next = stackWord;
		stackWord = element;
	}
	else printf("\nKhong chen duoc phan tu moi vao ngan xep");
}

//Lay tu tu stack
/*char *pop(){
	struct wordStruct * p = stackWord;
	char word[20];
	char * word1;
	strcpy(word,stackWord->word);
	stackWord = stackWord->next;
	free(p);
	p = NULL;
	word1=word;
	return word1;
}*/

//Doc van ban, dem tu va khoi tao stack
void createStack(){
	FILE * f;
	f = fopen("EnglishText.txt","r");
	if (!f) printf("Loi doc file");
	else{
		char word[20];
		struct wordStruct * p = NULL;
		int test;
		while (!feof(f)){
			test = 0;
			fscanf(f,"%s",word);
			for (p=stackWord; p != NULL; p=p->next){
				if (strcmp((p->word),word)==0){
					test=1;
					(p->numWord)++;
				}
			}
			if ((test==0)&&!feof(f)) push(word);
		}
	}
	fclose(f);
}

//Sap xep cac tu trong stack
void sortStack(){
	struct wordStruct * p;
	struct wordStruct * q;
	int temp;
	char wTemp[20];

	for (p=stackWord; (p->next)!=NULL; p=p->next){
		for (q=p->next; q!=NULL; q=q->next){
			if (strcmp(p->word,q->word)==1){
				strcpy(wTemp,p->word);
				strcpy(p->word,q->word);
				strcpy(q->word,wTemp);
				temp = p->numWord;
				p->numWord = q -> numWord;
				q->numWord = temp;
			}
		}
	}
}

//In stack ra
void stackTravelsal(){
	struct wordStruct * p = NULL;
	printf("\n======================\n");
	for (p = stackWord; p!=NULL; p=p->next){
			printf("%s ", p->word);
			printf("%d", p->numWord);
			printf("\n");
	}
}

int main(){
	setvbuf(stdout,NULL,_IONBF,0);

	createStack();
	stackTravelsal();
	sortStack();
	stackTravelsal();
	return 0;
}
