#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct  hang
{
	char ten[10];
	int tluong,gtri;
	float  dgia;
}hang;

typedef struct nhan
{
	char ten[10];
	int sluong;
};

hang sp[20];
int tui;
char f;
nhan xd[20];
int n,i,j;

void quicksort(hang A[],int l,int r)
{
	if(l>=r) return;
	int i=l;
	int j=r;
	hang x=A[(l+r)/2];
	while(i<=j)
	{
		while(A[i].dgia > x.dgia) i++;
		while(A[j].dgia < x.dgia) j--;
		if(i<=j)
		{
			hang temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			i++;j--;
		}
	}
	quicksort(A,l,j);
	quicksort(A,i,r);
}

void  init()
{
	FILE *f;
	int g;
	char t[10];
	hang tg;
	f = fopen("thamlam.txt","r");
	if(!f)
	{
		fprintf(f,"loi mo tep ");
		exit (1);
    }
	fscanf(f,"%d",&tui);
	fscanf(f,"%d",&n);
	for (i = 0 ; i <= n ; i++)
	{
		fflush(stdin);
		fgets(t,10,f);
		strcpy(sp[i].ten,t);
		fscanf(f,"\n%d %d\n",&sp[i].tluong,&sp[i].gtri);
		sp[i].dgia = (float)sp[i].gtri/sp[i].tluong;
	}
	fclose(f);
    quicksort(sp,1,n);
}

void xacdinh()
{
	int sl, tlduoc,tltui ;
	float gtduoc;
	i = 1;
	j = 1;
	tltui = tui;
	gtduoc = 0;
	tlduoc = 0;
	while (i <= n)
	{
		if (sp[i].tluong <= tltui )
		{
			sl = tltui/sp[i].tluong;
			tlduoc = tlduoc + sl*sp[i].tluong;
			gtduoc = gtduoc + sl* sp[i].gtri;
			tltui = tltui - sl*sp[i].tluong;
			strcpy(xd[j].ten,sp[i].ten);
			xd[j].sluong = sl;
			j = j+1;
		}
		i = i+1;
	}
	printf("\n\nTrong luong tui la %d \n", tui);
	printf("\n\nTrong luong lay duoc la %d\n", tlduoc);
	printf("\n\nGia tri thu duoc la %f\n",gtduoc);
	i = 1;
	printf("\n\nSan pham co duoc la: \n");
	while ( i < j)
	{
		printf("\n\nSan pham : %s co so luong: %d\n",xd[i].ten,xd[i].sluong);
		i = i+1;
	}
}

int main()
{
	init();
	xacdinh();
	getch();
	return 0;
}
