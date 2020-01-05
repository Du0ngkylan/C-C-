#include<stdio.h>
#include<conio.h>
void phantich_thuaso(int n){
        int i=2;
        printf("%d=",n);
//        if(n>0)
    while(i<=n/2){
        if(n%i==0){
                printf("%d*",i);
                n=n/i;
        }
        else i++;
        
    }
    printf("%d",n);
}

int main(){
        int n;
        printf("Nhap n:");
        scanf("%d",&n);
        phantich_thuaso(n);
        getch();
        return 0;
}
