// Bai toan: Tim cay bao trum toi thieu bang thuat toan prim

#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#define max 100
#define maxint 32767
char *tenfile="data2.txt";
int a[max][max];
int n;
void docfile()
{
    FILE *f=fopen(tenfile,"rt");
    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            fscanf(f,"%d",&a[i][j]);
    fclose(f);
}
void xuat()
{
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<n;j++)
            printf("%2d  " ,a[i][j]);
            printf("\n");
        }
}
void prim()
{
int vh[max];
int sodinh=0;    //Luu cac dinh da duoc xet
vh[sodinh]=0,sodinh++;    //Xet bat dau tu dinh 0

int daxet[max];
for(int i=0;i<n;i++)
    daxet[i]=0;
int dinhdau,dinhcuoi;    //dinh dau dinh cuoi cua 1 canh
int tongdodai=0;         

while(sodinh<n-1)
    {
        int imin=maxint;
            for(int i=0;i<sodinh;i++)    //Cac dinh duoc xet trong VH
                for(int j=0;j<n;j++)    //Cac dinh ke voi no
    //Neu cac dinh ke cua no chua xet thi tim dinh co kcach toi cac dinh trong VN min
                    if(vh[i]!=j && a[vh[i]][j]!=0 && daxet[j]==0 && a[vh[i]][j]<imin)
                    {
                        imin=a[vh[i]][j];            //tim gia tri min
                        dinhdau=vh[i],dinhcuoi=j;                   
                    }
    //Sau khi tim dinh chua xet co ddai min voi 1 trong so cac dinh VH
            daxet[dinhcuoi]=1;    //Xetdinhdo va dua vao VH 
            vh[++sodinh]=dinhcuoi;
            tongdodai+=a[dinhdau][dinhcuoi];
    //Dinh dau dinh cuoi co the in ra
            printf("\n(%d %d)",dinhdau,dinhcuoi);
    }
    printf("\n",tongdodai);
}
int main()
{
    docfile();
    xuat();
    prim();
    getch();
    return 0;

}  
