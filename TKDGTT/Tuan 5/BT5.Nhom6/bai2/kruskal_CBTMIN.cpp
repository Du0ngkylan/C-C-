#include <conio.h>
#include <stdio.h>
#include<stdlib.h>
int n, m, Index[100], Distance[100], Dau[100], Cuoi[100], K_Dau[100], K_Cuoi[100];

/*
  Name: Nhóm 12
  Copyright: Bài toán tìm cây khung nho nhat bang Kruskal.
  Date: 15/04/12 16:33
*/

/*------------------------------------------------------------------------*/
int Input();
int MakeHeap(int *A, int i, int n);
int Kruscal();

void DocDL()
{
    FILE *f;
    f = fopen("Kruskal.txt", "r");
    if(!f)
    {
        puts("Loi mo tep");
        getch();
        exit(0);
    }
    
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);
    
    for(int i=1; i<=m; i++)
    {
        fscanf(f, "%d", &Dau[i]);
        fscanf(f, "%d", &Cuoi[i]);
        fscanf(f, "%d", &Distance[i]);
    }
    fclose(f);
}

/*------------------------------------------------------------------------*/

void InDL()
{
    printf("BAI TOAN KRUSKAL TIM CAY KHUNG NHO NHAT : \n\n");
    printf("%d      %d\n\n",n,m);     
    for (int i = 1;i <= m;i ++)
    {
       printf("%d    %d    %d\n",Dau[i],Cuoi[i],Distance[i]);     
    }
    printf("\n\n");
}
/*------------------------------------------------------------------------*/

int MakeHeap(int *A, int i, int m)
{
    int temp, j=2*i;
    int key=A[i];
    
    while(j<=m)
    {
        if((j<m)&&(A[j]>A[j+1]))
        j=j+1;
        if(key<=A[j])
        return 1;
        else
        {
            A[j/2]=A[j];	
            A[j]=key;
            
            temp=Dau[j];
            Dau[j]=Dau[j/2];
            Dau[j/2]=temp;
            
            temp=Cuoi[j];
            Cuoi[j]=Cuoi[j/2];
            Cuoi[j/2]=temp;
            
            j=j*2;
        }
    }
    
    return 1;
}
    /*------------------------------------------------------------------------*/
int Kruscal()
{
    int t, i, j, count, temp1, temp2;
    
    t=1;
    i=m-1;
    count=1;
    for(j=m/2;j>=1;j--)
    MakeHeap(Distance,j,m);
    
    while(t<=n-1)
    {
        if((Index[Dau[1]]!=Index[Cuoi[1]]))
        // Kiem tra xem canh bo sung co tao thanh chu trinh khong qua chi so Index cua dinh
        {
        K_Dau[t]=Dau[1];
        K_Cuoi[t]=Cuoi[1];
        t++;
        
        if(Index[Dau[1]]>Index[Cuoi[1]])
        {
            temp1=Index[Dau[1]];
            temp2=Index[Cuoi[1]];
            // danh dau cac dinh trong cung mot cay cung mot chi so.
            for(j=1;j<t;j++)
            {
                if(Index[K_Dau[j]]==temp2)
                Index[K_Dau[j]]=temp1;
                
                if(Index[K_Cuoi[j]]==temp2)
                Index[K_Cuoi[j]]=temp1;
            }
        }
        if(Index[Dau[1]]<=Index[Cuoi[1]])
        {
            temp1=Index[Cuoi[1]];
            temp2=Index[Dau[1]];
            // danh dau cac dinh trong cung mot cay cung mot chi so.
            for(j=1;j<t;j++)
            {
                if(Index[K_Dau[j]]==temp2)
                Index[K_Dau[j]]=temp1;
                
                if(Index[K_Cuoi[j]]==temp2)
                Index[K_Cuoi[j]]=temp1;
            }
        }
    }
    
    if((Index[Dau[1]]==0)&&(Index[Cuoi[1]]==0)) // Truong hop hai dinh tu do chua tham gia vao cay nao
    {
        K_Dau[t]=Dau[1];
        K_Cuoi[t]=Cuoi[1];
        t++;
        // Danh chi so cay khung .
        Index[Dau[1]]=count;
        Index[Cuoi[1]]=count;
        count++;
    }
    // Tao lai dong .
    
    temp1=Distance[1];
    Distance[1]=Distance[i+1];
    Distance[i+1]=temp1;
    
    temp1=Dau[1];
    Dau[1]=Dau[i+1];
    Dau[i+1]=temp1;
    
    temp1=Cuoi[1];
    Cuoi[1]=Cuoi[i+1];
    Cuoi[i+1]=temp1;
    
    MakeHeap(Distance,1,i);
    i--;
    }
    // Hien thi cay khung nho nhat.
    
    printf("\n CAC CANH CUA CAY KHUNG NHO NHAT: \n");
    for(j=1;j<t;j++)
    printf("\n %d-%d",K_Dau[j],K_Cuoi[j]);
    return 1;
}
/*------------------------------------------------------------------------*/

int main(int argc, char* argv[])
{

    DocDL();
    InDL();
    Kruscal();
    
    getch();
    return 0;
}
