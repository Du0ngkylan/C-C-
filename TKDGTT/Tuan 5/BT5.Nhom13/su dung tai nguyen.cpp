#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct cv
{
	int s;
	int f;
} cv;
int n;
cv viec[50];
void nhapdulieu()
{
	int t1,t2,i;
	FILE *f;
	f=fopen("test.txt","r");
	char s[200];
	if(!f)
	{
		printf("loi mo tep");	getch();	exit(0);
	}
	fscanf(f,"%d",&n);printf(" So cong viec la n=%d",n);
	for(i=1;i<=n;i++)
	{
		fscanf(f,"%d%d",&t1,&t2);
		viec[i].s=t1;
		viec[i].f=t2;
		fgets(s,200,f);
		printf("\nCv%d.  %d ---> %d",i,viec[i].s,viec[i].f);
	}
	fclose(f);	
	
}
void swap(cv &a , cv &b)
{
	cv tmp;
	tmp= a;
	a=b;
	b=tmp;	
}
void SapXep(cv viec[], int n)
{
	int i,j;
	cv tmp;
	for(i=1;i<n;i++)
	for(j=i+1;j<=n;j++)
	{
		if(viec[j].f<=viec[i].f)
		{
			swap(viec[i],viec[j]);
		}
	}		
}
void LapLich()
{
			int j,i,count;
			i=1;
			count=1;
			printf("\n Cac cong viec duoc sap xep nhu sau:");
			printf("\nCong viec 1: %5d %5d\n",viec[1].s,viec[1].f);
			for(j=2;j<=n;j++)
				{
					if(viec[j].s>=viec[i].f)
					{	count++;
						printf("Cong viec %d: %5d %5d\n",count,viec[j].s,viec[j].f) ;
						i=j;
					}
				}
}
int main()
{
	int i;
	nhapdulieu();
	SapXep(viec,n);		
	LapLich();
	getch();
	return 0;
}
