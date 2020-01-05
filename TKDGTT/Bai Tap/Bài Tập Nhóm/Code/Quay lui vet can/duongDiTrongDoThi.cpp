#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 
int x,y,n,d[50],a[50][50];

void doctep(char *s)
{
    FILE *f;
    int i,j;
    f=fopen(s,"r");
    fscanf(f,"%d %d %d",&n,&x,&y);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            fscanf(f,"%d",&a[i][j]);
    printf("So phan tu cua ma tran : %d \n",n);
    printf("xuat phat tu : %d \n",x);
    printf("ket thuc o : %d \n",y);
    puts("Ma tran bieu dien do thi la :");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d    ",a[i][j]);
        puts("");
    }
    fclose(f);
}
void khoitao()
{
    int i;
    for(i=1;i<n;i++)
    {
        d[i]=0;// chua di qua dinh nao
    }
    d[x]=1;// dinh xuat phat bi danh dau
} 
void timduong(int i)
{
    int j;
    for(j=0;j<n;j++)
    {
        if(a[i][j] && !d[j])
        {
            d[j]=i;
            if(j!=y)
            timduong(j);
        }
    }
}  
void in()
{
    if(!d[y])
        puts("khong co duong di tu x den y trong do thi");
    else
    {
        puts("Duong di trong do thi");
        while(y!=x)
        {
             printf("%d <-- ",y);
             y=d[y];
        }
        printf("%d",x);
    }
}
int main()
{
    doctep("dothi.txt");
    khoitao();
    timduong(x);
    in();
    getch();
    return 0;
}

