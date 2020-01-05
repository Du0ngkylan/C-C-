#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int datum;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *Tree;

Tree createNode(int datum) {
    Tree node = (Tree)malloc(sizeof(struct Node));
    node->datum = datum;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void addNode(Tree *root, int datum) {
    if ((*root) == NULL) {
        Tree node = createNode(datum);
        *root = node;
        return;
    }
    if (datum < (*root)->datum) {
        addNode(&(*root)->left, datum);
    } else {
        addNode(&(*root)->right, datum);
    }
}

void visit(Tree tree) {
    printf("%3d", tree->datum);
}

void preOrder(Tree tree) {
    if (tree != NULL) {
        visit(tree);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

Tree visitForSearch(Tree tree, int value) {
    if (tree->datum == value)
        return tree;
    return NULL;
}

Tree searchByValue(Tree tree, int value)
{
    if (tree != NULL) {
        Tree ro = visitForSearch(tree, value);
        if (ro!=NULL)
            return ro;
            
        Tree l = searchByValue(tree->left,value);
        if (l!=NULL)
            return l;
        
        Tree ri = searchByValue(tree->right,value);
        if (ri!=NULL)
            return ri;
    }
    
    return NULL;
}

int main()
{
    int a[] = {3, 1, 8, 0, 2, 6, 9, 5};
    Tree root = NULL;
    int i;
    for (i = 0; i < 8; i++) {
        addNode(&root, a[i]);
    }
    
    preOrder(root);
    
    
    int vp, vq;
    printf("\nNhap p, q");
    scanf("%d%d",&vp,&vq);
    
    
    //Tree p chua vp
    Tree p = searchByValue(root,vp);
    preOrder(p);
    printf("\n");
    
    //Duyet p de tim xem co q khong?
    Tree q = searchByValue(p,vq);
    if (q==NULL)
        printf("P khong phai la to tien cua q!");
    else
        printf("P la to tien cua q!");
    
    getch();
    return 0;
}
