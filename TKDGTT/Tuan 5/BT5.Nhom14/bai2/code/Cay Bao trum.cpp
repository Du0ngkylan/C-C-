
#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#define max 100
//Khai bao cau truc cho canh
typedef struct canh
{
        int dau,cuoi,w;
};
canh a[max];
int m,n;
char *tenfile="danhsachcanh_dodai.txt";
int daxet[max][max];


void docfile()
{
     FILE *f=fopen(tenfile,"rt");
     fscanf(f,"%d%d",&n,&m);
     for(int i=0;i<m;i++)
     fscanf(f,"%d%d%d",&a[i].dau,&a[i].cuoi,&a[i].w);
     fclose(f);
     for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
     {
             if(i==j) daxet[i][j]=1;
             else daxet[i][j]=0;
     }
}
void xuat()
{
     cout<<"Dinh:"<<n<<",Canh:"<<m;
     for(int i=0;i<m;i++)
     cout<<a[i].dau<<"---"<<a[i].cuoi<<"--"<<a[i].w<<endl;
}
void swap(canh &a,canh &b)
{
     canh temp=a;a=b;b=temp;
}
void sort() //Co the dung nhieu cach de sort
{
     for(int i=0;i<m-1;i++)
     for(int j=i+1;j<m;j++)
     if(a[i].w>a[j].w)
     swap(a[i],a[j]);
}
void xet(int i,int j)
{
     daxet[i][j]=1,daxet[j][i]=1;
     for(int k=0;k<n;k++)
     for(int l=0;l<n;l++)
     if(daxet[k][i]==1&&daxet[j][l]==1)
     daxet[k][l]=1,daxet[l][k]=1;
}
void Kruskal()
{
     int tongdodai=0;
     int tongcanhchon=0;
     int dinhdau,dinhcuoi;
     int i=0;
     while(tongcanhchon<m&&i<n)
     {
                               dinhdau=a[i].dau,dinhcuoi=a[i].cuoi;
                               if(daxet[dinhdau][dinhcuoi]==0)
                               {
                                                              tongcanhchon++;
                                                              xet(dinhdau,dinhcuoi);
                                                              cout<<dinhdau<<"--"<<dinhcuoi<<","<<a[i].w<<endl;
                                                              tongdodai+=a[i].w;
                               }
                               i++;
     }
     cout<<tongdodai;
}
int main()
{
    docfile(),xuat();
    sort(),xuat();
    Kruskal();
    getch();
}
