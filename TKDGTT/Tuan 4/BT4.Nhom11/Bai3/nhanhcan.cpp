#include<stdio.h>
#include<conio.h>
int dem=0;
void ChuyenCot1(int N,char C,char A,char B) ;
void ChuyenCot2(int N,char A,char C,char B) 
{ 
    
         if (N==1) 
         { 
             printf("Chuyen tu cot %c sang cot %c\n",A,B); 
             printf("Chuyen tu cot %c sang cot %c\n",B,C); 
             dem+=2; 
          } 
          else 
          { 
                    ChuyenCot2(N-1,A,C,B); 
                    ChuyenCot1(1,A,B,C); 
                    ChuyenCot1(N-1,C,A,B); 
                    ChuyenCot1(1,B,C,A); 
                    ChuyenCot2(N-1,A,C,B); 
           } 
} 

void ChuyenCot1(int N,char C,char A,char B) 
{ 
         if (N==1) 
         { 
                 printf("Chuyen tu cot %c sang cot %c\n",C,A); 
                dem++; 
          } 
          else 
          { 
                     ChuyenCot2(N-1,C,B,A); 
                     ChuyenCot1(1,C,A,B); 
                     ChuyenCot2(N-1,B,A,C); 
          } 
} 
int main(){
	int n;
	char a = 'a',b = 'b',c = 'c';
	printf("\nNhap so dia: ");
	scanf("%d",&n);
	ChuyenCot2(n,a,b,c);
    getch();
    return 0;
}
