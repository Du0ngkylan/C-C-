#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
        int data;
        Node *next;
}Node;

Node *head = NULL;
int count = 0;
Node *creatNode(int data){
     Node *temp = (Node *)malloc(sizeof(Node));
     if (temp != NULL){
     temp -> data = data;
     temp -> next = NULL;
     }
     return temp;
}
Node *addNode(Node *head,int data){
     Node *temp = creatNode(data);
     if (head == NULL){
        head = temp;
        return head;         
     }
    // Node *temp2 = head;
     if (head -> data > temp -> data){
        temp -> next = head;
        head = temp;
        return head;         
     }
     Node* temp2 = head;
     Node* temp3 = temp2 -> next;
     while(temp2 != NULL){
            
          if ((temp2 -> next == NULL )&& (temp2 -> data < temp ->data) ){
                temp2 -> next = temp;
                return head;
          }    
          if ((temp2 -> data < temp -> data) && ((temp3->data) > temp -> data)){
             temp -> next = temp2 -> next;
             temp2 -> next = temp; 
             return head;         
          }       
          temp2 = temp2 -> next;
     }
     
     return head;
}


Node *doctep(){
     FILE *f;
     int n;
     f = fopen("dayso.txt","r");
     if (!f){
        printf("error!!!...");
        getch();
        exit(0);        
     }
     
     while (!feof(f)){
        fscanf(f,"%d",&n); 
        head = addNode(head,n);  
     }
     return head;
     
}

Node* prin(Node *head){
      Node *temp = head;
      while (temp != NULL){
            printf("%d\t", temp -> data);
            temp = temp -> next;      
      }      
}
int main(){
   
    head = doctep();
    
    
    printf("\nlist: \n");
    prin(head);
    
    //head = sort(head);
   // printf("\nlist: \n");
    //prin(head);
    
   // printf("\n%d",count);
    
    getch();
    return 0;
}
