#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct  hang{
         char ten[10];
         int tluong,gtri;
         float  dgia;
}hang;

typedef struct nhan{
        char ten[10];
        int sluong;
};

hang sp[20];
int tui;
char f;
nhan xd[20];
int n,i,j;

void  init(){
      int g ;
      char t[10];
      hang tg;
      printf("Trong luong cua tui la ");
      scanf("%d",&tui);
      printf("So luong loai hang hoa <=20 ");
      scanf("%d",&n);
      for (i = 1 ; i <= n ; i++)
      {
          printf("san pham thu %d \n", i);
          fflush(stdin);
          printf("ten san pham ");
          gets(t);
          strcpy(sp[i].ten,t);
          printf("co trong luong ");
          scanf("%d",&g);
          sp[i].tluong = g;
          printf("co gia tri la ");
          scanf("%d",&g);
          sp[i].gtri = g;
          sp[i].dgia = (float)sp[i].gtri/sp[i].tluong;
      }
      printf("stt |ten \t\t | Tluong | Gtri");
      printf("\n");
      printf("----|--------------------|--------|-----");
      printf("\n");
      for (i = 1 ; i <= n ; i++)
          printf("%d\t %-11s\t%4d\t %4d\n",i,sp[i].ten,sp[i].tluong,sp[i].gtri);
      for (i = 1 ; i <= n-1 ; i++)
      for (j = i + 1 ; j <= n ; j++ )
          if (sp[i].dgia < sp[j].dgia)
          {
                         tg = sp[i];
                         sp[i] = sp[j];
                         sp[j] = tg;
          }
      printf("stt |ten\t\t | Tluong | Gtri | Dgia");
      printf("\n");
      for (i = 1 ; i <= n ; i++)
          printf("%d\t %-11s\t %4d\t %4d\t %8.4f\n",i,sp[i].ten,sp[i].tluong,sp[i].gtri, sp[i].dgia);
}
void  xacdinh(){
      int sl, tlduoc,tltui ;
      float gtduoc;
      i = 1; 
      j = 1;
      tltui = tui;
      gtduoc = 0; 
      tlduoc = 0;
      while (i <= n)
      {
            printf("So: %d san pham %s  Tluong: %d \n",i,sp[i].ten,sp[i].tluong);
            if (sp[i].tluong <= tltui )
            {
                    sl = tltui/sp[i].tluong;
                    tlduoc = tlduoc + sl*sp[i].tluong;
                    gtduoc = gtduoc + sl* sp[i].gtri;
                    tltui = tltui - sl*sp[i].tluong;
                    strcpy(xd[j].ten,sp[i].ten);
                    xd[j].sluong = sl;
                    j = j+1;
                    printf(" so luong lay la: %d \n",sl);
                    printf(" trong luong hien co : %d \n",tlduoc);
                    printf(" trong luong con lai : %d \n", tltui);
            }
            else
            {
                printf(" so luong lay la: 0 \n");
            }
            i = i+1;
      }
      printf(" trong luong tui la %d \n", tui);
      printf(" trong luong lay duoc la %d\n", tlduoc);
      printf(" gia tri thu duoc la %f\n",gtduoc);
      i = 1;
      printf("san pham co duoc la \n");
      while ( i < j)
      {
            printf(" san pham : %s co so luong: %d\n",xd[i].ten,xd[i].sluong);
            i = i+1;
      }
}

int main(){
     init();
     xacdinh();
     getch();
     return 0;
}
