#include <conio.h>
#include <stdio.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;
void Push(int x){
     if (top == MAX_SIZE - 1){
         printf("Error: stack overflow\n");
         return;  
     } 
     A[++top] = x;    
}
void Pop(){
    if (top == -1){
        printf("Error: Noelement to pop\n");
        return;    
    }
    top--;
}

int Top(){
    return A[top];    
}
void Prin(){
     int i;
     printf("Stack: ");
     for (i = 0; i <= top; i++)
         printf("%d  ",A[i]);
     printf("\n");
          
}
int main(){
    
    Push(2); Prin();
    Push(5);Prin();
    Push(10);Prin();
    Pop();Prin();
    Push(12);Prin();
    
    getch();
    return 0;    
}
