#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node{
        int data;
        Node *next;        
}Node;
Node *head = NULL;

Node *creatNode(int data){
     Node *temp = (Node* )malloc(sizeof(Node));
     temp -> data = data;
     temp -> next = NULL;
     return temp;     
}

Node *addNode(Node *head, int data){
     Node *temp = creatNode(data);
     if (head == NULL){
        head = temp;
        return head;         
     }    
     temp -> next = head;
     head = temp;
     return head;
}

int fibonaci(int n){
    if (n <= 1) return n;
    return   fibonaci(n - 1) + fibonaci(n - 2);
}


Node *ktra(Node *head, int n){
     int i;
     for (i = 0; i < n; i++){
         if (fibonaci(i) < n){
            head = addNode(head, fibonaci(i));                
         }    
     } 
     return head;    
}
void prin(Node *head){
     Node *temp = head;
     while (temp != NULL){
           printf("%d\t",temp -> data);
           temp = temp -> next;      
     }     
}
int main(){
    int n;
   
    printf("nhap n: "); scanf("%d",&n);
    printf("so fibonaci nho hon %d : ", n);
    head = ktra(head,n);
    prin(head);
    
    getch();
    return 0;    
}
