#include<stdio.h>
#include<conio.h>

void PhanTich(int n){
	int d = 2;
            while ((n %d!=0)&&(n>0))
              d = d+1;
              if(n/d==1) printf("%d",d);
              else printf("%d.",d);
	          PhanTich(n/d);
}

int main(){
    int n;
    printf("Nhap so can phan tich:");
    scanf("%d",&n);
    printf("So sau khi phan tich:");
    PhanTich(n);
    getch();
}
