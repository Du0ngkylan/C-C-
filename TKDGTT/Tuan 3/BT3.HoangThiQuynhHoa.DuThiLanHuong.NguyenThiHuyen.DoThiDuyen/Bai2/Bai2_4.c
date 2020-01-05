//bai 2_4: viet thuat giai de quy cho bai toan thap ha noi
#include"stdio.h"
#include"conio.h"
//chuyen thap tu A sang B lay C lam trung gian
void chuyenthap(int n, char *A, char *B, char *C)
{
     if(n==1)
          printf("%s->%s\n",A,B);
     else
     {
          chuyenthap(n-1,A,C,B);
          printf("%s->%s\n",A,B);
          chuyenthap(n-1,C,B,A);
     }
}
int main()
{
    int n;
    do
    {
          printf("nhap so tang thap can chuyen n=");
          scanf("%d",&n);
    }while(n<=0);   
    printf("Quy trinh chuyen tu A toi B:\n");
    chuyenthap(n,"A","B","C");
    getch();
    return 0;
}
