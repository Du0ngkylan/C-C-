/*
 * tan so xuat hien tu tieng anh.c
 *
 *  Created on: Oct 28, 2012
 *      Author: NgoHuong
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
   char words[30];
   int freq;
   struct Node *next;
}Node;

Node *addNode(Node *list, char s[30], int freq)// khooit tao list = null o main
{
   Node *p;
   p = (Node*)malloc(1*sizeof(Node));
   strcpy(p->words, s);
   p->freq = freq;
   p->next = list;
   list=p;
   return list;
}

Node *dl(Node *list)
{
   FILE *f;
   f = fopen("englishWords.txt", "r");
   if (f == NULL)
   {
      puts("Loi mo tep");
      exit(0);
   }
   Node *p;
   char s[30];
   //fscanf(f, "%s", s);
   //list =addNode(list,s,1);// can khong<=====
   while (!feof(f))
   {
      fscanf(f, "%s", s);
      int them =0;
      for (p=list; p!=NULL; p=p->next)
      {
         if (strcmp(p->words, s) == 0)
         {
            p->freq ++;
           them++;//neu th nay xay ra thi se ko them nua
           break ;
         }
      }
  if(them==0)//neu trong kia ko gap tu nao giong thi moi them vao
    list = addNode(list,s,1);
   }
   fclose(f);
   return list;
}

void in_ds(Node *list)
{
   if (list == NULL)
   {
      puts("Danh sach rong");
      exit(0);
   }
   Node *p;
   for (p=list; p!=NULL; p=p->next)
   {
      printf("%s\t%d\n", p->words, p->freq);
   }
}

void sortList(Node *list)
{
   Node *p, *q;
   if (list == NULL)
   {
      printf("Danh sach rong");
      exit(0);
   }
   for (p=list; p->next!=NULL; p=p->next)
   {
      for (q=p->next; q != NULL; q=q->next)
      {
         if(strcmp(p->words, q->words) > 0)
         {
            char t[30];
            strcpy(t,p->words);
            strcpy(p->words, q->words);
            strcpy(q->words, t);
            int temp;
            temp = p->freq;
            p->freq = q->freq;
            q->freq = temp;
         }
      }
   }
}

int main()
{
   setbuf(stdout, NULL);
   Node *list, *p;
   list = NULL;
   p = dl(list);
   printf("\ndanh sach cac chu va tan suat cua no la:\n");
   in_ds(p);
   printf("\ndanh sach da sap xep la:\n");
   sortList(p);
   //Node *k;
   /*if (p=NULL)
   {
	   printf("DS rong");
	   exit(0);
   }*/
   /*for (k=p; k!=NULL; k=k->next)
   {
	   printf("%s\n", k->words);
   }*/
   in_ds(p);
   return 0;
}

