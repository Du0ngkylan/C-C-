//chuyen bieu thuc trung to thanh hau to, cach khac

#include<stdio.h>
#include<stdlib.h>
struct node{
	char s;
	struct node *next;
};
struct node *stack = NULL;
void push(char s){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	if(p!=NULL){
		p->s=s;
		p->next=stack;
		stack=p;
		}
}
int pop(){
	if(stack!=NULL){
		struct node *p=stack;
		char s=p->s;
		stack=p->next;
		free(p);
		return s;
	}else{
		return 0;
	}
}
int isEmpty(){
	if(stack==NULL){
		return 1;
	}
	else
		return 0;
}
int isOperator(char c){
	switch(c){
		case'(':
			return 1;
		case')':
			return 1;
		case '+':
			return 2;
		case'-':
			return 2;
		case'*':
			return 3;
		case'/':
			return 3;
		default:
			return 0;
	}
}
void xuly(char s[]){
		int i;
		int n = strlen(s);
		for(i=0;i<n;i++){
			if(s[i]!=' '){
				if(isOperator(s[i])==0){
					printf("%c",s[i]);
				}else{
					if(s[i]=='('){
						push(s[i]);
					}
					else if(s[i]==')'){
						char c;
						do{
							c=pop();
							if(c!='('){
								printf("%c",c);
							}
						}while(c!='(');
					}else{
						if(isEmpty()){
							push(s[i]);
						}
						else{
							char c;
							do{
								c=pop();
								if(isOperator(c)>=isOperator(s[i])){
									printf("%c",c);}
								else{
									push(c);
									push(s[i]);
									break;
								}
							}while(1);
						}
					}
				}

			}
		}
		while(!isEmpty()){
				printf("%c",pop());
			}
	}
int main(){
	char c[40];
	setbuf(stdout,NULL);
	printf("Moi ban nhap bieu thuc can chuyen sang hau to: ");
	gets(c);
	xuly(c);
	return 0;
}
