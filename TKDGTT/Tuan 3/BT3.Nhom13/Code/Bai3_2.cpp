#include <stdio.h>
#include <conio.h>
//Tim max min cua day so

//Tim max
int max(int a,int b) {
    if (a>=b) return a;
    return b;
    }
//Tim min
int min(int a,int b) {
    if (a<=b) return a;
    return b;
    }
//Tim max, min cua day so
void maxmin(int A[], int L, int R, int &Max, int &Min) {
     int Max1,Min1,Max2,Min2;
     if ((L+1)<R) {
                  maxmin(A,L,((R+L)/2),Max1,Min1);
                  maxmin(A,(((R+L)/2) + 1),R, Max2,Min2);
                  Max=max(Max1,Max2);
                  Min=min(Min1,Min2);
                  }
     else {
          if (A[L]<=A[R]) { 
                          Max=A[R];
                          Min=A[L];
                          }
          else {
               Max=A[L];
               Min=A[R];
               }
          }
     }
int main() {
    int Max,Min;
    int A[]={3,50,5,6,10,26,-6,7,9};
    maxmin(A,0,8,Max,Min);
    printf("Day so co (Max , Min) = (%d,%d)",Max,Min);
    getch();
    }
