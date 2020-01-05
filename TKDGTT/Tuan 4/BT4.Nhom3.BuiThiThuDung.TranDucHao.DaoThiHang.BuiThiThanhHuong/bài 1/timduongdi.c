#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define hs 50

int dich,xp,dau[hs],cuoi[hs],n,m,b[hs],q[hs],i,k, Tr[hs];

void thongbao(char *s)
{
	puts (s);
	getch();
	exit (0);
}

void nhap()
{
	    FILE *f ; int k; char s[200];
	    f = fopen ("dt.txt","r");
	    if (!f)
	       thongbao("LOi mo tep");
	       fscanf (f,"%d%d",&n, &m);
	       fgets(s,200,f);
	       for (k=1; k<=m; k++)
        {
            fscanf (f,"%d%d", &dau[k],&cuoi[k]); 
        }
	fclose(f);
}

int cung (int i, int j)
{
	int k;
	for (k=1; k<=m; k++)
	     if (dau[k]==i && cuoi[k]== j)
	     return 1;
	     return 0;
}

int khoitao()
{
	int i;
	for (i=1; i<=n; i++)
	     b[i]=1;
}

void in_kq()
{
	    int x;
	    x= Tr[dich];
	    printf ("%d",dich);
	    while  (x!=xp)
	    {   
		          printf("%d",x);
		          x= Tr[x];
     }
     printf("%d",xp);
}

void tim ()
{
	    int d,c, x,i;
	    d=c=1;
	    q[d]=xp;
	    b[xp]=0;
	    while (d<=c)
	    {
          x=q[d];
		        if (x==dich)
		        in_kq();
		        for (i=1; i<=n; i++)
	               if (b[i]==1 && cung (x,i))
			             {
					              c++;
					              b[i]= 0;   
					              q[c]=i;
					              Tr[i]=x;
                }
			             d++;
	}              printf ("\n Khong co duong di ");
}

int main()
{
	nhap();
	khoitao();
	printf ("Nhap gia tri cua xp= ");
	scanf ("%d",&xp);
	printf("Nhap gia tri cua dich = ");
	scanf ("%d",&dich);
	tim();
	getch();
}
        
	
	
