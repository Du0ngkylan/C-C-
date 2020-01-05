#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"string.h"
char X[100],Y[100];//2 xau
int F[100][100];
int m,n;// luu do dai cua xau X va xau Y
//F[i][j] so phep bien doi i ki tu dau cua xau X thanh Y ki tu dau cua xau Y
void nhap()
{
     FILE *f;
     f=fopen("doiXau_input.txt","r");
     if(!f)
     {
           printf("Loi mo tep!");    getch();
           exit(0);
     }
     fflush(stdin);
     fscanf(f,"%s",&X);
     char s[100];
     fgets(s,100,f);
     fscanf(f,"%s",&Y);
     m=strlen(X);
     n=strlen(Y);
    
}
int min(int x,int y,int z)
{
    int min;
    min=(x<y)?x:y;
    min=(min<z)?min:z;
    return min;
}
void DoiXau()
{
     int i,j;
     //co so quy hoach dong
     for(i=0;i<=m;i++)
          F[i][0]=i;//so phep bien doi i ki tu da cua X thanh xau rong 
     for(i=0;i<=n;i++)
          F[0][i]=i;//so phep bien doi xau rong thanh i ki tu dau trong Y
     // tinh toan bang phuong an
     for(i=1;i<=m;i++)
     {
          for(j=1;j<=n;j++)
          {
               if(X[i-1]==Y[j-1])
               {
                    F[i][j]=F[i-1][j-1];
               }
               else
                    F[i][j]=min(F[i-1][j],F[i][j-1],F[i-1][j-1])+1;
          }
     }
}
void insert(char a,int i)
{
     i--;
     int j=m-1;
     while(j>i)
     {
               X[j+1]=X[j];
               j--;
     }
     X[i+1]=a;
     m++;
}
void Delete(int i)
{
     i--;
     
     while(i<m-1)
     {
               X[i]=X[i+1];
               i++;
     }
     m--;
}
void Replace(char c, int i)
{
     i--;
     X[i]=c;
}
void inXau(char a[],int k)
{
     int i;
     printf("X=");
     for(i=0;i<k;i++)
                     printf("%c",a[i]);
     
}
void Truyvet()
{
     int i=m,j=n;
     int a;
     while(i!=0||j!=0)
     {
         if(X[i-1]==Y[j-1])
         {
                       i--;
                       j--;
         }
         else//ca 1 phep bien doi
         {
             a=F[i][j]-1;
             inXau(X,m);

             if(a==F[i][j-1])
             {
                       printf("-->Insert(%c,%d)",Y[j-1],i);
                       insert(Y[j-1],i);
                       printf("-->");inXau(X,m);    printf("\n");
                       j--;
             }
             else if(a==F[i-1][j])
             {
                       printf("-->Delete(%c,%d)",X[i-1],i);
                       Delete(i);
                       printf("-->");inXau(X,m);   printf("\n");
                       i--;
             }
             else
             {
                       printf("-->Replace(%c,%d)",Y[j-1],i);//thay the ki tu tai vi tri thu i bang Y[j]
                       Replace(Y[j-1],i);
                       printf("-->");inXau(X,m);   printf("\n");
                       i--;
                       j--;
             }
             
         }
     }
}
void in()
{
     printf("\n\n");
     int i,j;
     for(i=0;i<=m;i++)
     {
            for(j=0;j<=n;j++)
                 printf("%d\t",F[i][j]);
            printf("\n");
     }
     printf("\n");
}
int main()
{
    nhap();  
    DoiXau();
    in();
    printf("X=%s\tY=%s\n",X,Y);
    printf("\n");
    printf("so phep bien doi it nhat co the la:%d nhu sau\n",F[m][n]);
    Truyvet();
    getch();
}
