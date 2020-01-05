#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct
{
	int bd;
	int kt;
}tn;

tn *Input(char* filename, int *n)
{
    int x,y;
  	tn *p,*i;
	FILE *f = fopen(filename,"r");
	if(!f)
	{
		printf("Khong doc duoc tep");
		getch();
		exit(0);
	}
	fscanf(f,"%d",n);
 	p = (tn *)malloc(*n*sizeof(tn));
	for(i = p;i<(p+(*n));i++)
	{
		fflush(stdin);
		fscanf(f,"%d%d",&x,&y);
 		i->bd = x;
  		i->kt = y;
	}
	fclose(f);
	return p;
}

void Output(tn *p, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\n%d --> %d",p[i].bd, p[i].kt);
	}
}

// sap xep day hoat dong theo thu tu tang dan cua thoi gian ket thuc
void swap(tn *x, tn *y)
{
	tn tg;
	tg = *x;
	*x = *y;
	*y = tg;
}

tn *sap_xep(tn *p, int n)
{
	tn *i,*j;
	for(i = p;i<p+n-1;i++)
	{
		for(j = i+1; j<p+n; j++)
		{
			if((i->kt) > (j->kt))
			{
				swap(i,j);
			}
		}
	}
	return p;
}

int them(tn *p, int n, tn k)
{
	p[n].bd = k.bd;
	p[n].kt = k.kt;
	n++;
	return n;
}
// Thuat giai lap lich su dung tai nguyen
int Activity_Selector(tn *S, int t, tn *p, int n)
{
	t = them(S,t,p[0]);
	int j = 0;
	for(int i=1;i<n;i++)
	{
		if(p[i].bd >= p[j].kt)
		{
			t = them(S,t,p[i]);
			j = i;
		}
	}
	return t;
}


int main()
{
	tn *p,*S;
	p = (tn *)malloc(100*sizeof(tn));
	S = (tn *)malloc(100*sizeof(tn));
	int n,t = 0;
	p = Input("tai_nguyen.inp", &n);
	printf("\n\nCac hoat dong:\n\n");
	printf("%d",n);
	Output(p,n);
	printf("\n\n");
	p = sap_xep(p,n);
	t = Activity_Selector(S,t,p,n);
	printf("\n\nLap lich su dung tai nguyen:\n\n");
	Output(S,t);
	getch();
	return 0;
}
