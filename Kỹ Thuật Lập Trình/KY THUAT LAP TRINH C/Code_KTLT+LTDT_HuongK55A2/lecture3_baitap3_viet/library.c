/*
 * library.c
 *
 *  Created on: Mar 6, 2012
 *      Author: MrThai
 */

#include <stdio.h>
#include <conio.h>
#include "dataStructure.h"
#include <string.h>
#include <stdlib.h>

node *addNode (node *list ,char *word ,int frequency)	{
	node *p;
	p= (node *) malloc(sizeof (node));
	if (p!=NULL)	{
		strcpy(p->word,word);
		p->frequency=frequency;
		p->next=NULL;
	}
	if (list==NULL)	{
		list=p;
	}
	else {
		p->next=list;
		list=p;
	}
	return list;

}

//thuat toan la doc file roi tao danh sach moc noi voi tan so ban dau
//bang 1.Roi bat dau duyet danh sach dung hai con tro neu
//pi->word==pj->word thi xoa pj di roi tang tan so cua pi them 1.....

node *createList (char *fileName)	{
	node *list=NULL;
	FILE *f;
	char *s=(char *) malloc(30*sizeof (char));
	int frequency=1;
	f=fopen(fileName,"rt");
	if (f==NULL)	{
		printf("%s is not exist....",fileName);
		exit(0);
	}
	node *pi;
	int dem;
	while (feof(f)==0)	{
		fscanf(f,"%s",s);
		pi=list;
		dem=0;
		while (pi!=NULL)	{
			if (strcmp(pi->word,s)==0)	{
				pi->frequency++;
				dem++;
				break;
			}
			pi=pi->next;
		}
		if (dem==0)	{
			list=addNode(list,s,frequency);
		}
	}
	fclose(f);
	/*node *pl=list,*pi,*pj;
	int i=1;
	while (pl!=NULL)	{
		pj=pl;
		while ((pj->next!=NULL))	{
			pi=pj->next;
			if (strcmp(pl->word,pi->word)==0)	{
				i++;
				pj->next=pi->next;
				free(pi);
			}

			else pj=pj->next;
		}
		if (i>1)	{
			pl->frequency=i;
			i=1;
		}
		pl=pl->next;

	} */
	return list;

}

node *reverse (node *list)	{
	node *pl=list,*pi=list->next,*pj;
	if (pi==NULL)	{
		printf("there is a node of linked list...");
		return list;
	}
	pj=pi->next;
	pl->next=NULL;
	while (pi!=NULL)	{
		pi->next=pl;
		pl=pi;
		pi=pj;
		if (pj!=NULL)	{
			pj=pj->next;
		}
	}
	return pl;

}

void selectionSort (node *list)	{
	node *pi,*pj;
	int temp;
	char *s=(char *) malloc (30*sizeof (char));
	for (pi=list;pi->next!=NULL;pi=pi->next)	{
		for (pj=pi->next;pj!=NULL;pj=pj->next)	{
			if (strcmp(pi->word,pj->word) >0)	{
				strcpy(s,pi->word);
				strcpy(pi->word,pj->word);
				strcpy(pj->word,s);
				temp=pi->frequency;
				pi->frequency=pj->frequency;
				pj->frequency=temp;
			}
		}
	}
}


void printList (node *list)	{
	node *pi=list;
	printf("word\tfrequency\n");
	while (pi != NULL)	{
		printf("%s\t%d\n",pi->word,pi->frequency);
		pi=pi->next;
	}
}







