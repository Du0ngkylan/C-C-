#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

//cho day 5, 2, 8, 1,9 .
//nhap vao linked list dung thu tu!

typedef struct Node{
        int data;
        Node *next;        
}Node;

Node *head = NULL;

Node *creatNode(int data){
     Node *temp = (Node *)malloc(sizeof(Node));
     if (temp != NULL){
        temp -> data = data;
        temp -> next = NULL;         
     }
     return temp;
}

Node *addNode(Node *head, int data){
     Node *temp  = creatNode(data);
     if (head == NULL){
        head = temp;
        return head;         
     }
     temp -> next = head;
     head = temp;
     return head;     
}
void prin(Node *head){
     Node *temp = head;
     while (temp != NULL){
           printf("%d\t",temp -> data); 
           temp = temp -> next;     
     } 
     puts("");    
}
Node *listNode(Node *head, int *a){
     for (int i = 0; i < 5; i++){
        head = addNode(head, a[i]);
        
    }
    return head;
}

Node* sapXep(Node *head){
     Node *temp = head;
     int k;  
     while (temp != NULL){
           Node *temp2 = temp -> next;
           while (temp2 != NULL){
                 if (temp -> data > temp2 -> data){
                       k = temp -> data;
                       temp -> data = temp2 -> data;
                       temp2 -> data = k;   
                 }
                 temp2 = temp2 -> next;
           } 
           temp = temp -> next;     
     }
     return head;   
}
int main(){
    
    int a[] = {5, 2, 8, 1, 9};
    
    //for (int i = 0; i < 5; i++){
//        head = addNode(head, a[i]);
//        
//    }
      
      head = listNode(head, a);
      
    printf("List: \n");
    prin(head);
    head = sapXep(head);
    
    printf("List after sort: \n");
    prin(head);
    
    getch();
    return 0;    
}
