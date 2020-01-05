#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	char name[50];
	struct Node *next;
};

struct Node *q = NULL;

struct Node* createElement(char *datum)
{
	struct Node* element = (struct Node*) malloc (sizeof(struct Node));
	if(element != NULL){
		strcpy(element->name, datum);
		element->next = NULL;	
	}
	return element;
}

struct Node* addElement(struct Node *head, char *datum)
{
	struct Node *element = 	createElement(datum);
	if(element == NULL)
		return head;
	else{
		element->next = head;
		return element;	
	}	
}

struct Node* creatList(struct Node *head)
{
	FILE *f;
	f = fopen("danhsach.txt", "r");
	char name[100];
	while(!feof(f))
	{
		fgets(name,100,f);
		if (name[strlen(name)-1]==10)
			name[strlen(name)-1] = '\0';
		head = addElement(head, name);		
	}
	fclose(f);
	return head;
}

void printList(struct Node *head)
{
	struct Node *i = head;
	while(i != NULL)
	{
		printf("\n%s", i->name);	
		i = i->next;
	}	
}

int count( struct Node * q )
{
	int c = 0 ;
	while ( q != NULL )
	{
		q = q -> next ;
		c++ ;
	}
	return c ;
}

void selection_sort(struct Node *head)
{
	char temp[100];
	int n = count(head);
	struct Node *p, *q;
	p = head;
	for (int i = 0 ; i < n - 1 ; i++)
	{
		q = p -> next;
		for (int j = i + 1 ; j < n ; j++)
		{
			if (strcmp(p->name, q->name) > 0)
			{
				strcpy(temp, p->name);
				strcpy(p->name, q->name);
				strcpy(q->name, temp);
			}
			q = q->next;
		}
		p = p->next;
	}
}

void insertElement(struct Node *head, char *name)
{
	struct Node *p, *pre;
	p = head;
	struct Node *element = 	createElement(name);
	
	while ( p != NULL && strcmp(name, p->name) > 0) {
	            pre = p;
	            p = p->next;
	        }
	 if ( pre == NULL ) {
	            element->next = head;
	            head = element;
	        }
	        else{
	            pre->next = element;
	            element->next = p;
	        }
}

void searchElement(struct Node *head, char *name)
{
	int c = 0;
	int find = 0;
	while ( head != NULL) {
		printf("\n%d - %d", strlen(name), strlen(head->name));
//		for(int i=0; i< strlen(head->name); i++)
//			printf("---%c", head->name[i]);
		if(strcmp(name, head->name) == 0)
		{   
	        find = 1;
			break;
		}
		else
		{
			head = head->next;
			c++;
		}
	}
	if(find == 1)
		 printf("Position: %d", c);
	else
		printf("Not found");
}


struct Node* deleteElement(struct Node *head, char *name)
{
	int c = 0;
	//Kiem tra head
	if (head != NULL)
	   if (strcmp(head->name,name)==0)
	       return head->next;
	       
	struct Node *p;
	p = head;

	while ( p->next != NULL) {
		if(strcmp(name, p->next->name) == 0) {
            p->next = p->next->next;
            //break; Neu chi xoa phan tu dau tien tim duoc thi them lenh nay
        }

		p = p->next;
	}
	return head;
}

int main()
{
	struct Node *i;

	
	// tao list
	struct Node *p = NULL;
	p = creatList(q);
	
	// in list
	printf("\nList: ");
	printList(p);
	
	// in list sau khi sap xep
	printf("\nList sorted: ");
	selection_sort(p);
	printList(p);
	
	//chen ten theo dung vi tri
	char newName[100];
	printf("\nEnter the name to insert in linked list: ");
	gets(newName);
	insertElement(p, newName);
	printf("\nList inserted: ");
	printList(p);
	
	//tim kiem ten
	char *newName2;
	newName2 = (char *)malloc(sizeof(char)*50);
	printf("\nEnter the name to search: ");
	gets(newName2);
	searchElement(p, newName2);
	
	// Xoa ten
	char newName3[100];
	printf("\nEnter the name to delete: ");
	gets(newName3);
	p = deleteElement(p, newName3);
	printf("\nList deleted: ");
	printList(p);
	
	getch();
	return 0;
}
