#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>

struct Node
{
	char name[50];
	int quatility;
	struct Node *next;
};

struct Node *head = NULL;

struct Node* createElement(char *datum)
{
	struct Node* element = (struct Node*) malloc (sizeof(struct Node));
	if(element != NULL){
		strcpy(element->name, datum);
		element->quatility++;
		element->next = NULL;	
	}
	return element;
}

struct Node  *searchElement(struct Node *head, char *name)
{
	int c = 0;
	int find = 0;
	while ( head != NULL) {
		if(strcmp(name, head->name) == 0)
		{   
	        return head;
		}
		else
		{
			head = head->next;
		}
	}
	return NULL;
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

void printList(struct Node *head)
{
	struct Node *i = head;
	
	while(i != NULL)
	{
		printf("\n%s - %d", i->name, i->quatility);	
		i = i->next;
	}	
}

struct Node* creatList()
{
	FILE *f;
	f = fopen("word.txt", "r");
	char name[100];
	while(!feof(f))
	{
		fscanf(f, "%s", name);
		
		if(searchElement(head,name) == NULL)
		{
			head = addElement(head, name);	
		}
		else
		{
			searchElement(head,name)->quatility ++;
		}
	}
	fclose(f);
	return head;
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
				int dc = p->quatility;
				p->quatility = q->quatility;
				q->quatility = dc;
			}
			q = q->next;
		}
		p = p->next;
	}
}

int main()
{
	head = creatList();
	printf("\nList: ");
	printList(head);
	
	printf("\nList sorted: ");
	selection_sort(head);
	printList(head);
	
	getch();
	return 0;
}
