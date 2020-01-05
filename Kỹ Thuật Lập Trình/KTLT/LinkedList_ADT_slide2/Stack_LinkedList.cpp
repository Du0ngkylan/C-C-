#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
       int data;
       struct Node* link;       
};

Node* top = NULL;

void Push(int x){
     Node* temp = (Node*)malloc(sizeof(Node));
     temp -> data = x;
     temp -> link = top;
    // if (top != NULL) temp -> link = top; 
     top = temp;
            
}
void Pop(){
     Node *temp;
     if (top == NULL) return;
     temp = top;
     top = top -> link;
     free(temp);    
       
}
void Prin(){
     Node* temp = top;
     printf("Stack: ");
     while (temp != NULL){
           printf("%d  ", temp -> data); 
           temp = temp -> link;     
     }  
     printf("\n");   
}
int main(){
   // Node* top = NULL;
    Push(3);Prin();
    Push(4);Prin();
    Push(5);Prin();
    Pop();Prin();
    
    Push(12);Prin();
   // Push(12);Prin();
    
    
    getch();
    return 0;
}
