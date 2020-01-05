#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode {
        int data;
        BstNode *left;
        BstNode *right;        
}BstNode;

BstNode *root = NULL;

BstNode* getNewNode(int data){
         BstNode* newNode = (BstNode *)malloc(sizeof(BstNode)); 
         newNode -> data = data;
         newNode -> left = newNode -> right = NULL;
         return newNode;        
}
BstNode* insert(BstNode *root, int data){
         if (root == NULL){
            root = getNewNode(data);
            //return root;         
         }
         else if (data < root -> data){
              root -> left = insert(root -> left, data);     
         }         
         else {
              root -> right = insert(root -> right, data);     
         }
         return root;
}
bool search(BstNode* root, int data){
     if (root == NULL) return false;
     else if (root -> data == data) return true;
     else if (data <= root -> data) return search(root -> left,data);
     else return search(root -> right, data);
}
void visit(BstNode* root) {
     printf("%d \t", root->data);
}
void preOrder(BstNode* root) {
     if (root != NULL) {
        visit(root);
        preOrder(root->left);
        preOrder(root->right);
     }
}
bool isSubTreeLesser(BstNode *root,int value){
     if (root == NULL) return true;
     if (root -> data <= value 
     && isSubTreeLesser(root -> left, value) 
     && isSubTreeLesser(root -> right, value))
     
        return true;
     else
         return false;
                
}
bool isSubTreeGreater(BstNode *root, int value){
     if (root == NULL) return true;
     if (root -> data > value
        && isSubTreeGreater(root -> left, value)
        && isSubTreeGreater(root -> right, value))
        
        return true;
     else
         return false;     
}

bool isBinarySearchTree(BstNode* root){
     if (root == NULL) return true;
     if (isSubTreeLesser(root -> left, root -> data)
        && isSubTreeGreater(root -> right, root -> data)
        && isBinarySearchTree(root -> left)
        && isBinarySearchTree(root -> right)) 
        return true;
     else
         return false;         
}

int main(){
        //BstNode *root = NULL;
        
        root = insert(root,15);
        root = insert(root,10);
        root = insert(root,20);
        root = insert(root,25);
        root = insert(root,8);
        root = insert(root,12);
        
        preOrder(root);
        
        int number;
        printf("\nnhap vao mot so: ");scanf("%d",&number);
        if (search(root,number)==true) printf("Found\n");
        else printf("Not Found\n");
        

        if (isBinarySearchTree(root) == true){
           printf("is binary search tree!");                                    
        }
        else 
             printf("is not!");
        getch();
        return 0;
}
