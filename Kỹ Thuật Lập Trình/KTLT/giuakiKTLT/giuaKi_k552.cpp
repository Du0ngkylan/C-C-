#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
        int data;
        Node *next;        
}Node;

Node *front = NULL;
Node *rear = NULL;

Node *creatNode(int data){
     Node *temp = (Node*)malloc(sizeof(Node));
     if (temp != NULL){
        temp -> data = data;
         temp -> next = NULL;        
     }    
     return temp; 
}
Node *enqueue(Node *front, int data){
     Node *temp = creatNode(data);
     if (front == NULL){
        front = rear = temp;
        return front;          
     }
     rear -> next = temp;
     rear = temp;
     return front;     
}
Node *dequeue(Node *front){
      Node *temp = front;
      if (front == NULL){return NULL;} 
      front = temp -> next;
      free(temp);
      return front;   
}
void Prin(Node *front){
     Node *temp = front;
    // for (temp = front; temp != NULL; temp++){
//         printf("%d\t",temp -> data);    
//     } 
       while (temp != NULL){
              printf("%d\t",temp -> data);
             temp = temp -> next;      
       }    
     puts("");
}

Node *addList(Node *front,int soPt, int data){
      for (int i = 0; i < soPt; i++){
              //data = data * 2;
              front = enqueue(front, data);
              data = data * 2;
      } 
      return front;   
}

Node *kTra(Node *front){
     Node *temp = front;
     while (temp != NULL){
           if ((temp -> data) % 6 == 0){
                    front = temp -> next;
                    //return front;
           }
           temp = temp -> next;      
     }
     return front;     
}

void remove(Node *front){
     Node *temp = front;
     while (temp != NULL){
           front = temp -> next;
           free(temp);
           temp = temp -> next;      
     }     
}

int main(){
    int n;
    int soPt;
    printf("NHap n: ");scanf("%d",&n);
    printf("NHap so phan tu >= 8: ");scanf("%d",&soPt);
    
    while (soPt < 8){
          printf("NHap so phan tu >= 8: ");scanf("%d",&soPt);      
    }
    
    front = addList(front,soPt,n);
    printf("\nList before:\n");
    Prin(front);
    
    printf("list after:\n ");
    front = kTra(front);
    Prin(front);
    
    
    printf("list after remove:\n ");
    remove(front);
    
    
    
    getch();
    return 0;
} 
