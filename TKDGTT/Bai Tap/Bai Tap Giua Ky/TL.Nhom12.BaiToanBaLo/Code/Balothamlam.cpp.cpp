#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
  int n,M;
  int w[100],v[100],kq[100],teamp[100];
  float gt[100];
 
void DocDL()
{
    FILE *f;
	int i;
    f = fopen("Balo.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
		exit(0);
    }
    fscanf(f, "%d", &n);
    fscanf(f, "%d\n", &M);
    for(i=0; i<n; i++)
    {
        fscanf(f, "%d", &w[i]);
        fscanf(f, "%d\n", &v[i]);
		gt[i]=(float)v[i]/w[i];
		teamp[i]=i;
		kq[i]=0;
    }
    printf("%d   %d\n",n,M);
	for(i=0; i<n; i++)
	{
		printf("%d   %d\n", w[i], v[i]);
	}
    fclose(f);
}
void DoiCho(float &a, float &b){
    float temp=a;
    a=b;
    b=temp;
    }
      
void DoiCho(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
    }
    
void SapXep(){
     int i,j;
     for(i=0;i<n-1;i++)
         for(j=i+1;j<n;j++)
            if(gt[i] < gt[j]){
                    
                    DoiCho(gt[i],gt[j]);
                    DoiCho(w[i],w[j]);
                    DoiCho(v[i],v[j]);
                    teamp[i+1]=j+1;
                    teamp[j+1]=i+1;
                    }
     }
void PhuongAn(){
   int i;
   printf("\n Cac vat chon dua vao balo la: ");
   for(i=0;i<n;i++)
       if(kq[i] !=0)
               printf("\n Lay %d * Do vat %3d;",kq[i],teamp[i+1]);
   }

void Greedy(){
          int i =0,sumValue =0;
    while(i<n && M!=0)
  {
    if(w[i] <= M)   
    {       
           kq[i]=M/w[i];
           sumValue =sumValue +v[i]*kq[i];
           M=M-w[i]*kq[i];
     }   
  i++;
   }
       printf("\n Tong Gia Tri lon nhat la %d",sumValue);
       PhuongAn();
}           
int main()
{
    
  DocDL();
    SapXep();
    Greedy();
    getch();
    return 0;    
}
