#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
        char data[20];
        int tanSo;
        Node* next;        
}Node;
Node* head = NULL;
//int count = 0;
Node* creatNode(char data[20]){
      Node* temp = (Node*)malloc(sizeof(Node));
      strcpy(temp -> data, data);
      temp -> tanSo = 1;
      temp -> next = NULL;
      return temp;
}
Node* addNode(Node* head, char data[20]){
      Node* temp = creatNode(data);
      if (temp != NULL) {
         if (head != NULL) {
                  Node *p = head;
              while (p != NULL){
                   if (strcmp(p -> data, data) == 0){
                      p -> tanSo++;
                      return head;
                   } 
                   p = p -> next;   
               }
               temp -> next = head;
         }
         return temp;
      }else {      
            return NULL;
      } 
}

Node* docTep(){
     FILE* f;
     f = fopen("sv1.txt","r");
     if (f == NULL){
        printf("Error!..");
        getch();
        exit(0);      
     } 
     char ten[10];
     //int count = 0;
     while (!feof(f)){
           fscanf(f,"%s",ten);
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
           printf("\t---------------\n");
           printf("\t|             |\n");
           printf("\t|\"%5s\" | %d  |\n",temp -> data,temp -> tanSo);
           printf("\t|             |\n");
           printf("\t---------------\n");
           printf("\n\n");
          //printf("-     -");
          // printf("-------");
           temp = temp -> next;      
     }
     printf("\t");
}
Node* sort(Node* head){
    Node *p = head;
	char k[20];
	int h;
    while (p != NULL){
      Node*q = p -> next;
         while (q != NULL){
            if(strcmp(p->data,q->data)>0){
                   strcpy(k,p->data); 
				   strcpy(p->data,q->data);
				   strcpy(q->data,k);
                   h = p -> tanSo;
                   p -> tanSo = q -> tanSo;
                   q -> tanSo = h;                       
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

int main(){
   
    char name[20];
    head = docTep();
    printf("Linked List: \n");
    Prin(head);
   
    printf("\nten sau khi sap xep: \n\n");
    head = sort(head);
    Prin(head);
    
    //Dlist(head);
    //Prin(head);
   
  
    getch();
    return 0;
}
