/*
  BAI 1
Tim duong di tu A toi B trong me cung
*/

#include<stdio.h>
#include<conio.h>
int a[100][100],n,x[100],dd[100],S,F;
void nhap()
{
     int i,j;
     printf("\n----BAI TOAN ME CUNG----\n");
     do
     {
        printf("Nhap so cac phong cua me cung:\n"); scanf("%d",&n);
     }
     while(n<1);
     
     printf("Nhap phong xuat phat va phong dich:\n"); scanf("%d%d",&S,&F);
     while (S<1||F<1||S>n||F>n||F<S)
     {
        	printf("De nghi nhap lai!!!\n");
            printf("Nhap phong xuat phat va phong dich:\n");
            scanf("%d%d",&S,&F);
     }
     if (n>1)
     	printf("Nhap a[i][j]=\t 1.Neu co duong di tu phong i toi phong j\n\t\t 0.Neu nguoc lai\n");
     for(i=1;i<=n;i++)
     {
        a[i][i]=1;
       	for(j=i+1;j<=n;j++)
       	{
            printf("a[%d][%d]=",i,j);
            scanf("%d",&a[i][j]);
            while (a[i][j]!=0&&a[i][j]!=1)
            {
                	printf("nhap lai a[%d][%d]=",i,j);
                    scanf("%d",&a[i][j]);
            }
            a[j][i]=a[i][j];
    	}
	   
	}
}
void in()
{
    int i,j;
    printf("\nMa tran canh cua me cung:\n");
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)                                    
            printf("|%d\t|",a[i][j]);                           
        printf("\n");
    }
}
void khoitao()
{
     int i;
     for(i=1;i<=n;i++)
     	dd[i]=0;
}
void printresult(int dem)
{
     int i;
     for(i=1;i<=dem;i++)
     {                       
        if(x[i]!=F)
            printf("%d->",x[i]);
        else 
			printf("%d",x[i]);
     }
}
void tim(int i,int dem)
{
     int v;
     for(v=1;v<=n;v++)
     if(a[x[i-1]][v]==1&&dd[v]==0)
     {
        dem=dem+1;
        x[i]=v;
        dd[v]=1;
        if (x[i]==F)
        {
            printresult(dem);
            dd[v]=0;
            dem=dem-1;
            return;
        }
        tim(i+1,dem);
        dd[v]=0;
        dem=dem-1;
     }
}
int main()
{
      int t;
      do
	  {
          nhap();
          khoitao();
          in();
          x[1]=S;
          printf ("Ket qua tim duong trong me cung bang phuong phap quay lui:\n\n");
          if(S==F)
          printf("Phong xuat phat chinh la phong dich\n");
          else
          {
          dd[S]=1;          
          tim(2,1);
          }
      printf(" \nBan muon thuc hien tiep khong?\n""An:\t1 neu co\n\t:1 so bat ki + enter neu muon thoat");
      scanf("%d",&t);
      }
      while(t==1) ;
      getch();
}
                            
                            
     
     
