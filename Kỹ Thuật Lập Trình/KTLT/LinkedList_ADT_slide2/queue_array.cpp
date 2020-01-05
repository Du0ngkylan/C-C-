#include <conio.h>
#include <stdio.h>


float queueBuffer[100];
int front = 0, rear = 0, count = 0;

void enqueue(float element){
     if (count < 100){
        queueBuffer[(front + count) % 100] = element;
        count++;          
     }     
}
float dequeue(){
      if (count > 0){
         queueBuffer[front] = 0;
         float element = queueBuffer[front];
         count--;
         front++;
         if (front == 100){
            front = 0;          
         }
         
         return element;          
      } else {
          return 0;       
      }     
}
void prin(){
     printf("queue:  ");
      for (int i = 0; i < 10; i++){
          if (queueBuffer[i] != 0 ){
          printf("%.0f  ",queueBuffer[i]);
          }
          
      } 
      printf("\n");   
}
int main(){
    //float queueBuffer[100];
    //int front = 0, rear = 0, count = 0;
    float a;
    enqueue(5);prin();
    enqueue(4);prin();
    enqueue(9);prin();
    //printf("\na[front]= %0.f\n",queueBuffer[front]);
    enqueue(6);prin();
    a = dequeue(); prin();
    //printf("\na[front]= %0.f\n",queueBuffer[front]);
   
    enqueue(15);prin();
    enqueue(9);prin();
    enqueue(21);prin();
    enqueue(14);prin();
    enqueue(5);prin();
    a = dequeue(); prin();
    a = dequeue(); prin();
    a = dequeue(); prin();
    a = dequeue(); prin();
    
    getch();
    return 0;    
}
