#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
        float element;        
        Node* next;
}Node;

Node* queue = NULL;
Node* pRear = NULL;

void enqueue(float element){
     Node *node = (Node*)malloc(sizeof(Node));
     node -> element = element;
     node -> next = NULL;
     if (pRear != NULL){
        pRear -> next = node;          
     }else{
           queue = node;      
     }
     pRear = node;
}

float dequeue(){
      if (queue != NULL){
         Node *pElement = queue;
         float element = pElement -> element;
         queue = pElement -> next;
         if (pElement == pRear){
               pRear = NULL;
         }          
         free(pElement);
         return element;
      }else{
            return 0;      
      }
}
void prin(){
     Node *temp = queue;
     printf("\nqueue: \n");
     while (temp != NULL){
           printf("%0.f  ",temp -> element);
           temp = temp -> next;
     }
}
int main(){
    
    enqueue(4);
    enqueue(5);
    enqueue(6);
    
    prin();
    
    dequeue();
    
    prin();
    
    getch();
    return 0;    
}
