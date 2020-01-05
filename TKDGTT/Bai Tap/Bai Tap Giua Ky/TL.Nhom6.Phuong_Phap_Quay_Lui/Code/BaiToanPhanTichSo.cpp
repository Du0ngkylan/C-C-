//bai toan phan tich so = phuong phap quay lui

#include<stdio.h>
#include<conio.h>
int x[30],t[30];
int n;
//khoi tao
void init() {
     printf("Nhap n= ");
     scanf("%d",&n);
     x[0]=1;
     t[0]=0;
     }
//in ket qua
void PrintResult(int k) {
     int i;
     printf("%d = ",n);
     for(i=1;i<k;i++)  printf("%d + ",x[i]);
     printf("%d\n",x[k]);
     }

void Thu(int i) {
     int j;
     for(j=x[i-1];j<=(n-t[i-1])/2;j++) {
                                       x[i]=j;
                                       t[i]=t[i-1]+j;
                                       Thu(i+1);
                                       }
     x[i]=n-t[i-1];
     PrintResult(i);
     }
int main() {
    init();
    Thu(1);
    getch();
    return 0;
    }
