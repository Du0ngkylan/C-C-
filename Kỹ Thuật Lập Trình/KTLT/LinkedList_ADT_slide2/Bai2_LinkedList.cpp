#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
        char data[20];
        Node* next;        
}Node;
Node* head = NULL;
Node* creatNode(char data[20]){
      Node* temp = (Node*)malloc(sizeof(Node));
      strcpy(temp -> data, data);
      temp -> next = NULL;
      return temp;
}
Node* addNode(Node* head, char data[20]){
      Node* temp = creatNode(data);
      if (head != NULL) temp -> next = head;
      head = temp;
      return head; 
}

Node* docTep(){
     FILE* f;
     f = fopen("sv.txt","r");
     if (f == NULL){
        printf("Error!..");
        getch();
        exit(0);      
     } 
     char ten[20];
     while (!feof(f)){
           fgets(ten,20,f);
           ten[strlen(ten) - 1] = 0;
           head = addNode(head,ten);      
     }
      fclose(f);
     return head;
    
}

void Prin(Node* head){
     Node* temp = head;
     if (head == NULL) return;
     //printf("List: \n");
     while (temp != NULL){
           printf("%s\n",temp -> data);
           temp = temp -> next;      
     }
}
Node* sort(Node* head){
    Node *p = head;
	char k[20];
	
    while (p != NULL){
      Node*q = p -> next;
         while (q != NULL){
            if(strcmp(p->data,q->data)>0){
                   strcpy(k,p->data);
				   strcpy(p->data,q->data);
				   strcpy(q->data,k);                       
            }
            q = q ->next;
         } 
         p = p -> next;   
    }
    //Prin(head);
    return head;
}
void Dlist(Node *head){
     Node* temp = head;
     while (temp != NULL){           
           head = temp -> next;
           free(temp);
     }
     head = NULL;
    // return head;
}
Node* insert(Node *head,char data[20]){
     Node *temp = head;
     Node* temp2 = creatNode(data);
     if (head == NULL ) {
		head = temp2;
		return head;
	}
	Node*q;		
	while (temp -> next!= NULL ) {
          char k[20];
           if (strcmp(temp -> data, temp2 -> data) > 0){                       
                        temp2 -> next = temp -> next;
                        temp -> next = temp2;
                        strcpy(k,temp->data);
	                    strcpy(temp->data,temp2->data);
	                    strcpy(temp2->data,k);
                        return head;     
           } 
		temp = temp->next;
	}
	q = temp2;
	temp->next = q;
	return head;
}

void search(Node *head, char data[20]){
     int count = 0;
     Node *temp = head;
     if (temp == NULL) return;
     while (temp != NULL){
           count++;
           if (strcmp(temp -> data, data) == 0){
                           //count++;
                           printf("\nco ten \"%s\" tai vi tri %d...", data, count);                
           }/*else {
                 printf("\nkhong co te can tim!!!");      
           }*/
           temp = temp -> next;
     }
     //return 1;
         
}
Node* Dname(Node *head, char data[20]){
     Node *temp = head;
     if (temp == NULL) return NULL;
     int count = 0;
     while (temp != NULL) {
           char k[20];
           count++;
           if (strcmp(head -> data,data) == 0){
                           head = temp -> next;
                           free(temp);
                           return head;
           }
           if (strcmp(temp -> data,data) == 0){                       
                        Node* temp2 = head;
                        for (int i = 0; i < count - 2; i++){ 
                            temp2 = temp2 -> next;
                        }                     
                        temp2 -> next = temp -> next;
                       // temp -> next = temp2;
                        free(temp);     
           } 
           
           temp = temp -> next;     
     }
     return head;   
}
int main(){
   
    char name[20];
    head = docTep();
    printf("Linked List: \n");
    Prin(head);
   
   printf("\nten sau khi sap xep: \n\n");
    head = sort(head);
    Prin(head);
    
    printf("\nnhap ten can chen: ");
    
    gets(name);
    
    head = insert(head,name);
   Prin(head);
  
   // printf("\nten tim kiem: \n");
    //search(head,"thu");
                  
    
    //printf("\nxoa: \n");
    //head = Dname(head,"ba");
   // Prin(head);
   // Dlist(head);
   // Prin(head);
    
    
    
    getch();
    return 0;
}
