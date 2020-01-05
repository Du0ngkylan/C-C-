#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node{
       int datum;
       struct Node *left;
       struct Node *right;
};

typedef struct Node *Tree;
Tree root = NULL;

Tree createNode(int datum){
     Tree node = (Tree)malloc(sizeof(struct Node));
     node -> datum = datum;
     node -> left = NULL;
     node -> right = NULL; 
     return node;    
}

void addNode(Tree *root, int datum){
     if ((*root) == NULL){
        Tree node = createNode(datum);
        *root = node;
        return;            
     }     
     if (datum < (*root) -> datum){
        addNode(&(*root) -> left, datum);          
     }else {
           addNode(&(*root) -> right, datum);      
     }
}

void visit(Tree tree){
     printf("%3d", tree -> datum);     
}
void addList(int *a){
     int i; 
     for (i = 0; i < 9; i++){
         addNode(&root, a[i]);    
     }     
}

void inOrder(Tree tree){
     if (tree != NULL){
        inOrder(tree -> left);
        visit(tree);
        inOrder(tree -> right);
                 
     }     
}
void preOrder(Tree tree){
     if (tree != NULL){
        visit(tree);
        preOrder(tree -> left); 
        preOrder(tree -> right);        
     }     
}
void postOrder(Tree tree){
     if (tree != NULL){
        postOrder(tree -> left); 
        postOrder(tree -> right);
        visit(tree);        
     }     
}
int main(){
    int a[] = {3, 1, 8, 0, 2, 6, 9, 5, 7};
    
    addList(a);
    printf("List in-Order: \n");
    inOrder(root);
    printf("\n\nList pre-Order: \n");
    preOrder(root);
    printf("\n\nList post-Order: \n");
    postOrder(root);
    
    getch();
    return 0;    
}


