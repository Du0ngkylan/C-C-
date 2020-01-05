#include<stdio.h>
#include<conio.h>
#define max 100

int n, weight, w[max], v[max], a[max],x[max];
int maxV =0;

void doctep()
{
     FILE *f;
     f = fopen("Balo.txt","r");
           fscanf(f,"%d",&weight);   
		   fscanf(f,"%d",&n);   
           int i;
           for(i=0; i<n; i++) 
                fscanf(f,"%d%d",&w[i],&v[i]);
    if(f == NULL )
     	printf("\nLoi mo tep");
    fclose(f);
}

void in()
{
	printf("\nTrong luong toi da la : %d",weight);	
	printf("\nSo do vat co la: %d",n);
	int i,j;
	printf("\nTrong luong - gia tri :\n");
	for(i=0; i<n; i++)
		printf("%d - %d\n",w[i],v[i]);
}

int tonggt()
{
     int i;
     int Tonggt =0;
     for(int i=0; i<n; i++)  
             Tonggt += v[i] * x[i];
     return Tonggt;
}

int tongtl()
{
     int i;
     int Tongtl =0;
     for(int i=0; i<n; i++)  
             Tongtl += w[i] * x[i];
     return Tongtl;
}

void inkqua()
{
	int i;
	printf("\nGia tri lon nhat la : %d",maxV);
	printf("\nCac do vat duoc chon la: ");	
	for(i=0; i<n; i++)	
		if(a[i]== 1)
			printf("%5d",i+1);
}

void copy()
{
	int i;
	for(i=0; i<n; i++)
		a[i] = x[i];
}

void Try(int i)
{
     int j;
     for(j=0; j<= 1; j++)     
     {
              x[i] = j;
              if(i== n-1)         
              {
				printf("%5d",tonggt());
            	if(tonggt() > maxV && tongtl() <= weight)
            	{
					maxV = tonggt();
					copy();	
				}
              }
              else 
              	Try(i+1);
     }
}
int main()
{
	doctep();
	in();
	Try(0);
	inkqua();
	getch();
	return 0;	
}
