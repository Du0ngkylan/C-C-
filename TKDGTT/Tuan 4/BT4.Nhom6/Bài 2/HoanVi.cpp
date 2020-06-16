#include<stdio.h>
#include<conio.h>
// hoan vi 1
void liet_ke(int *b,int n)
{
	int i;
	for(i=1;i<=n;i++)
    {
		printf("%d",b[i]);
    }
    printf("\n");
}

void Try(int *b,int n,int i,int *p)
{
	int j;
	for(j=1;j<=n;j++)
    {
		if (p[j] == 1)
		{
			b[i] = j;
			p[j] = 0;
			if (i == n)
			{
				liet_ke(b,n);
            }
			else
			{
				Try(b,n,i+1,p);
            }
			p[j]=1;
		}
    }
}

int main()
{
	int b[10],n,i,p[10];
	printf("Nhap n = ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
		p[i]=1;
    }
	Try(b,n,1,p);
	getch();
	return 0;
}
