#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;    
    Node *left;
    Node *right;
}Node;
Node *root = NULL;

Node *createNode(int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;   
}

Node *addTree(Node *root, int data){
    Node *temp = createNode(data);
    if (root == NULL) {
        root = temp;
        return root;    
    } 
    if (root -> data > data){
        root -> left = addTree(root -> left, data);    
    }
    else 
        root -> right = addTree(root -> right, data);
        
    return root;
}
Node *addList(Node *root,int a[]){
    int i;
    for (i = 0; i <= 8; i++){
        root = addTree(root, a[i]);    
    }
    return root;    
}
void visit(Node *root){
    printf("%d\t", root -> data);    
}
void preOrder(Node *root){
    if (root != NULL) {
    
    visit(root);
    preOrder(root -> left);
    preOrder(root -> right); 
    
    }    
}
Node* search(Node *root, int value){
    if (root == NULL) return NULL;
    else if (root -> data == value) return root;
    else if (root -> data > value) return  search(root -> left, value);
    else  return  search(root -> right, value);  
}
int sizeOfNode(Node *root){
    if (root == NULL) return 0;
    else        
        return sizeOfNode(root -> left) + sizeOfNode(root -> right) + 1;
}

//void check(Node *root, int a, int b){
//    Node *p, *q;
//    p = search(root,a);
//    if(p == NULL){
//        printf("%d khong xh trong cay", a);
//    }
//    else{
//        q = search(p,b);
//        if(q==NULL){
//        printf("\n%d khong la to tien %d", a,b);
//    }
//    else{
//        printf("\n%d la to tien cua %d",a,b);
//        }
//    }
//}


int main(){
    int a[] = {3, 1, 8, 0, 2, 6, 9, 5, 7};
    root = addList(root, a);
    printf("\nTree: \n\n");
    preOrder(root);
    
    int n; 
    printf("\n\nnhap vao node n co tren CAY: ");scanf("%d",&n);
    while (search(root,n) == NULL){
       printf("\nnhap vao node n co tren CAY: \n");scanf("%d",&n);       
    }
    Node *temp = search(root,n);
    int m = sizeOfNode(temp);
    printf("\nsize of node: %d",m);
    //int m, n;
//    printf("\nnhap m: "); scanf("%d", &m);
//    
//    while (!search(root,m)){
//        printf("\nnhap lai m co trong tree: "); scanf("%d", &m);
//    }
//    printf("\nnhap n: "); scanf("%d", &n);
//    while (!search(root,n)){
//        printf("\nnhap lai n co trong tree: "); scanf("%d", &n);
//    }
//    check(root,m,n);
    
    
    
    getch();
    return 0;    
}
