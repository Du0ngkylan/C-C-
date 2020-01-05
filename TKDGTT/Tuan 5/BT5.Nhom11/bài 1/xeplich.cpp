#include<stdio.h>
#include<conio.h>
typedef struct
{
int s;
int f;
} lich;
int n;
lich a[50];
void NhapDL()
{
	 int i,t1,t2;
	 do{
	    printf("\n Nhap so hoat dong can sap xep: ") ;
	    scanf("%d",&n);
        }
     while(n<=0);
	 for(i=1;i<=n;i++)
	 {           do{
                    printf("\nNhap hoat dong thu %d:\n",i);
                    printf("a[%d].s=",i);                  scanf("%d",&a[i].s);
                    printf("a[%d].f=",i);                  scanf("%d",&a[i].f);
                    }
                 while(a[i].s>a[i].f);
	 }
}
void swap(lich *a,lich *b)
{
     lich temp;
     temp=*a;
     *a=*b;
     *b=temp;
}
void sapxep()
	{
		int i,j;
		lich t;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
			{
				if(a[j].f<=a[i].f)
					swap(&a[i],&a[j]);
			}
}
int saplich()
{
			int j,t,i;
			j=1;
			t=1;			
			for(i=2;i<=n;i++)
				{
					if(a[i].s>=a[j].f)
					{	t+=1;
					    a[t]=a[i];
						
						j=i;
					}                
                }
return t;
}
int main()
{
    int t,i;
	NhapDL();
	sapxep();
	t=saplich();
    printf("\n_______________KET QUA_____________\n");
	printf("cong viec\tthoi gian\n");
	for(i=1;i<=t;i++)
    printf("viec %d: \t%d->%d\n",t,a[i].s,a[i].f) ;
	getch();
}
