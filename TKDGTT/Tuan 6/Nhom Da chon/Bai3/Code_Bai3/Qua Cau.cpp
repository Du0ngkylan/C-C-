#include <conio.h>
#include <stdio.h>
//=========================
int main() {
   int n,BT = 0,bt[100];
   printf ("\n Nhap so nguoi qua cau : " );
   scanf("%d",&n);
   printf ("\n Nhap thoi gian tung nguoi:\n" ) ;
   for (int i = 0;i < n;i++)
   {
       printf ("\n Nguoi so %d phut : ",i+1);  
       scanf ("%d",&bt[i]);
   }
   int min = bt[0];
   for (int i = 0;i < n;i++)
      if (bt[i] > bt[i + 1])
         min = bt[i + 1];
   for (int i = 0;i < n;i++)
      if (bt[i] != min)   
         BT += bt[i];
      else   
         BT += min * (n - 2);      
   printf ("\n ---------------------------------------------\n");
   printf("\n Can it nhat %d phut de ca %d nguoi qua cau : ",BT,n ) ;
   getch();
}
