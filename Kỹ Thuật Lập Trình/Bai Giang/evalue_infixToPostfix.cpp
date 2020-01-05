#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
char exp[100];
char expInfixToPost[100];
int top = 0; 
int len = 0;

void push(char c){
     top++;
     stack[top] = c;
}

char pop(){
     if (top > 0){
        return stack[top--];
     }     
} 
int hasPrecedence(char op){
    if (op == '*' || op == '/') return 2;
    else if (op == '-' || op == '+') return 1;
    else return 0;
}
void infixToPostfix(char exp[]){
     int lenght;
     lenght = strlen(exp);
     for (int i = 0; i < lenght; i++){
         if (exp[i] == ' ') continue;
         else if (hasPrecedence(exp[i]) == 0 && exp[i] != '(' && exp[i] != ')'){
              expInfixToPost[len++] = exp[i];          
         }    
         else if (exp[i] == '('){
              push(exp[i]);     
         }
         else if (exp[i] == ')'){
              char x;
              	do {
				x = pop();
				if (x != '(') {
					expInfixToPost[len++] = x;
				}
			} while (x != '(');
         }
         else {
              while (top != 0 && hasPrecedence(exp[i]) <= hasPrecedence(stack[top]) && exp[i] != '('){
                    char x;
                    x = pop();
                    if (x != '('){
                        expInfixToPost[len++] = x;     
                    }
              }
              push(exp[i]);     
         }
     }
     while (top != 0){
           char x;
           x = pop();
           expInfixToPost[len++] = x;      
     }
     printf("\ninfix to postfix: %s",expInfixToPost);     
}
int calculator(char c, int op1, int op2){
    int res;
    switch(c){
        case '*': 
             res = op2 * op1; 
             break;
        case '/': 
             res = op2 / op1; 
             break;
        case '+': 
             res = op2 + op1; 
             break;
        case '-': 
             res = op2 - op1; 
             break;     
    }
    return res;
}
int evalueToPostfix(){
     int lenght;
     int op1, op2;
     int result;
     lenght = strlen(expInfixToPost);
     for (int i = 0; i < lenght; i++){
         if (hasPrecedence(expInfixToPost[i]) == 0){
            char c = expInfixToPost[i];
            push(atoi(&c));   
         }
         else {
              op1 = pop();
              op2 = pop();
              result = calculator(expInfixToPost[i],op1,op2);
              push(result);
         }
     }
     return pop();
}

int main(){
    printf("nhap vao bieu thuc trung to: ");
    fflush(stdin);
    gets(exp);
    infixToPostfix(exp);
    
    printf("\nket qua cua bieu thuc hau to: %d",evalueToPostfix());
    
    getch();
    return 0;    
}



