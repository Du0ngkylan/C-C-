#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int datum;
struct Node *next;
}Node;

struct word{
	char w[20];
	int count ;
	struct word *next;
};

Node* createElement(int datum)
{
	Node *element = (Node*)malloc(sizeof(Node));
	if(element!= NULL)
	{
		element->datum =  datum;
		element->next = NULL;
	}

	return element;
}


Node* addElement(Node *head, int datum)
{
	Node* element = createElement(datum);

	if(element!=NULL)
	{
		element->next = head;
		head = element;
		return element;
	}
	else
		return head;

}

void createList(Node **head, int n)
{
	int i;
	srand(time(NULL));
	for(i = 0 ; i<n; i++)
	{
		int r = rand()%100;
		*head = addElement(*head,r);
	}

}

void printList(Node *head)
{
	Node *p ;

	for(p=head; p->next !=NULL; p = p->next)
		printf("%d -> ",p->datum);

	printf("%d\n",p->datum);
}

void swap(Node *p, Node *q)
{
	int tg = p->datum;
	p->datum = q->datum;
	q->datum = tg;
}

void Sort(Node *head)
{
	Node *p,*q;

	for( p = head ; p->next!=NULL;p=p->next)
		for(q = p->next ; q!=NULL;q=q->next)
			if(p->datum > q->datum)
				swap(p,q);
}

Node* insert(Node *head, int datum)
{
	Node *p = head;
	if(p->datum >= datum)
	{
		Node* element = createElement(datum);
		element->next = head;

		return element;
	}
	else
	{
		Node *q =  p->next;
		while( p->next != NULL && q->datum < datum)
		{
			p=p->next;
			q=p->next;
		}

		if(q==NULL)
		{
			Node* element = createElement(datum);
			p->next = element;
			return head;
		}
		else
		{
			Node* element = createElement(datum);
			p->next = element;
			element->next = q;
			return head;
		}
	}
}
Node* removeNode(Node *head,int datum)
{
	Node *p = head;
	if(p->datum == datum)
	{
		p = p->next;
		return p;
	}
	else
	{
		Node *q =  p->next;
		while( p->next != NULL && q->datum != datum)
		{
			p=p->next;
			q=p->next;
		}

		if(q==NULL)
		{
			p->next = NULL;
			return head;
		}
		else
		{
			p->next = q->next;
			return head;
		}
	}
}


struct word* createWord(char *s)
{
	struct word * w = (struct word*)malloc(sizeof(struct word));

	if(w!=NULL)
	{
		w->next = NULL;
		strcpy(w->w,s);
		w->count = 1;
	}

	return w;
}

struct word* addWord(struct word* head, char *s)
{
	struct word* w = createWord(s);
	if(w!=NULL)
	{
		w->next = head;
		return w;
	}
	else
		return head;
}
struct word* checkIn(struct word* head,char *s)
{
	struct word* p = head;

	for( p = head; p!=NULL;p=p->next)
		if(strcmp(p->w,s)==0)
			return p;

	return NULL;
}

void proper(char *s)
{
	int i = 0,j=0;
	char replace[20];

	while(i< strlen(s))
	{
		if(s[i]!='.' && s[i]!=',' && s[i]!='!' && s[i]!='?' && s[i]!=':' && s[i]!='"')
		{
			replace[j] = s[i];
			j++;
		}
		i++;
	}

	replace[j] = '\0';

	for(i=0;i<=j;i++)
		s[i]=replace[i];
}


struct word* readFile(struct word*head,char *filename)
{
	FILE *f;
	char s[40];
	f=fopen(filename,"r");

	if(f!=NULL)
	while(!feof(f))
	{
		fscanf(f,"%s",&s);
		proper(&s);
		struct word* p =checkIn(head,&s);
		if(p==NULL)
			head = addWord(head,&s);
		else
			p->count = p->count+1;

	}

	return head;

}
void printListWord(struct word* head)
{
	struct word* p;
	for( p = head ;  p!=NULL ;  p=p->next)
		printf("%s: %d\n",p->w,p->count);
}



int main()
{
	Node *linkList = NULL;
	struct word* listWord = NULL;
	createList(&linkList,10);
	printf("\n--------------CREATE LIST----------\n");
	printList(linkList);

	printf("\n--------------SORT LIST----------\n");
	Sort(linkList);
	printList(linkList);

	printf("\n--------------INSERT to LIST----------\n");
	linkList = insert(linkList,55);
	printList(linkList);
	printf("\n--------------REMOVE  from LIST----------\n");
	linkList = removeNode(linkList,55);
	printList(linkList);

	listWord = readFile(listWord,"Input.txt");
	printListWord(listWord);


	return 0;
}
