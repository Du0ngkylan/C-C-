#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node{
	int datum;
	struct Node *next;
};

struct Node* createElement(int datum){
	struct Node* element = (struct Node*) malloc (sizeof(struct Node));
	if(element != NULL){
		element->datum = datum;
		element->next = NULL;	
	}
	return element;
}

struct Node* addElement(struct Node *head, int datum){
	struct Node *element = 	createElement(datum);
	if(element == NULL)
		return head;
	else{
		//1. Them vao dau danh sach
		element->next = head;
		return element;	
		
		//2. Them vao cuoi danh sach
	//	if(head == NULL)
//		   return element;
//		struct Node* t = head;
//		while(t->next!=NULL)
//			t = t->next;
//		t->next = element;
//		return head;
	}	
}

int prime(int k)
{
	if(k <=1 )
		return 0;
	else
	{
		int dem = 0;
		for(int i=2; i<=k/2; i++)
			if(k%i==0)
				dem++;
		if(dem==0)
			return 1;
		else
			return 0;	
	}
}

struct Node* creatList(struct Node *head, int n){
	for(int i = 0; i<n; i++){
		if(prime(i))
			head = addElement(head, i);	
	}	
	return head;
}

struct Node * reverseList(struct Node * head)
{
    struct Node * temp;
    struct Node * i = head;
    struct Node * previous = NULL;
    while(i != NULL) {
        temp = i->next;
        i->next = previous;
        previous = i;
        i = temp;
    }
    return previous;
}

void printList(struct Node *head)
{
	struct Node *i = head;
	while(i != NULL)
	{
		printf("%d ", i->datum);	
		i = i->next;
	}	
}

void searchList(struct Node *head, int k)
{
	struct Node *i = head;
	int find = 0;
	while(i != NULL)
	{
		if(k == i->datum)
		{
			find = 1;
		}
		i = i->next;
	}	
	if(find == 1)
		printf(" found ");	
	else
		printf(" Not found ");	
}

void freeList(Node* head)
{
    while (head != NULL)
    { 
        Node* temp = head; 
        free(temp);
        head = head -> next;
    }
}

void searchElement(struct Node *head, int name)
{
	int c = 0;
	int find = 0;
	while ( head != NULL) {
		if(name == head->datum)
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


int main()
{
	struct Node *i;
	struct Node *p = NULL;
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	
	// tao list
	p = creatList(p, n);
	
	// in list
	printf("\nList: ");
	printList(p);
	
	struct Node *res = reverseList(p);
	printf("\nReserve List: ");
	printList(res);
	
	printf("\nFree list: ");
	freeList(res);
	printList(res);
	
	int k = 7;
	searchList(res, k);
	
	getch();
	return 0;
}
