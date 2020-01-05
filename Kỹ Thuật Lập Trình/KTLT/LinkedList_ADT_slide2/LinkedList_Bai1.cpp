#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
        int data;
        Node* next;        
};

Node* creatNode(int data){
      Node* temp = (Node*)malloc(sizeof(Node));
      temp -> data = data;
      temp -> next = NULL;
      return temp;
}
Node* addNode(Node* head, int data){
      Node* temp = creatNode(data);
      if (head != NULL) temp -> next = head;
      head = temp;
      return head; 
}
int soNguyenTo(int n){
    if (n == 2) return 1;
    else if (n == 0 || n == 1) return 0;
    for (int i = 2; i <= n / 2; i++){
          if (n % i == 0){
             return 0;
          }  
    } 
    return 1;   
}
void creatList(Node* &head,int n){
     for (int i = 0; i < n; i++){
         if (soNguyenTo(i) == 1){
              head =  addNode(head,i);
         } 
     }
}
Node* Reverse(Node* &head){
     Node *next, *prev, *current;
     current = head;
     prev = NULL;
     while (current != NULL){
          next =  current -> next;
          current -> next = prev;
          prev = current;
          current = next;
     } 
     head = prev;
     return head;    
}
void Prin(Node* &head){
     Node* temp = head;
     while (temp != NULL){
           printf("%d  ",temp -> data);
           temp = temp -> next;      
     }
}
void RemoveAll(Node* &head){
     Node* temp;
     while (head != NULL){
           temp = head;
           head = head -> next;
           free(temp);
     }
     head = NULL;     
}
int main(){
    int n;
    Node* head = NULL;
    printf("nhap n: ");scanf("%d",&n);
    creatList(head,n);
    printf("Linked List: \n");
    Prin(head);
    Reverse(head);
    printf("\nlist nguoc: \n");
    Prin(head);
    RemoveAll(head);
    printf("\nList sau khi remove: \n");
    
    getch();
    return 0;
}
