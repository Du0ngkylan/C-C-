#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
        int data;
        node *next;        
}node;

node *head = NULL;

node *creatNode(int data){
     node *temp = (node* )malloc(sizeof(node));
     if (temp != NULL){
     temp -> data = data;
     temp -> next = NULL;
     }
     return temp;     
}
node *push(node *head, int data){
     node *temp = creatNode(data); 
     if (head == NULL){
        head = temp;
        return head;         
     }    
     temp -> next = head;
     head = temp;
     return head;
}

node* list(node *head,int n, int data){
      for (int i = 0; i < n; i++){
          head = push(head,data);
          data += 3;
     }
     return head;
}

void prin(node *head){
     node *p = head;
     /*for ( p = head; p != NULL; p++){
         printf("%d\t",p -> data);    
     }*/
     while (p!=NULL){
            printf("%d\t",p -> data);
           p = p -> next;
     }
}
node* pop(node *head){
     node *temp  = head;
     if (temp == NULL){
        return NULL;         
     } 
     head = temp -> next;
     free(temp);
     return head;
}
node* tim(node* head){
     node *temp = head;
     while (temp != NULL){
           if (temp -> data % 5 == 0 ){
             // temp = pop(head);         
              head = temp -> next;
           }
           temp = temp -> next;
     }
     return head;
}
void remove(node *head){
     node *temp = head;
     while (temp != NULL){
           head = temp -> next;
           free(temp);
           temp = temp -> next;      
     }     
}

int main(){
    int number, n;
    printf("nhap mot so: ");scanf("%d",&number);

    printf("\n nhap so phan tu cua day >= 8: "); scanf("%d",&n);
    while (n < 8){
      if (n < 8){
           printf("\nmoi nhap lai mot so nguyen >= 8: ");
           scanf("%d",&n); 
      } 
   }         
    //}while(n >= 8);
    
    head = list(head,n,number);
    printf("\nlist: \n");
    prin(head);
    head = tim(head);
    printf("\nlist sau khi tim: \n");
    prin(head);
    
    
    printf("\nlist sau khi remove: \n");
    remove(head);
    prin(head);
    
    
    getch();
    return 0;    
}
