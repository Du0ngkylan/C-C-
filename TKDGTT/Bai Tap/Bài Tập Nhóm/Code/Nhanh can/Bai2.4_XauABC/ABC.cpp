//Pham Kim Phuong _K51a2
#include"stdio.h"
#include"conio.h"
int N,T,Tmin;
char x[100],w[100];
//ham Kt xem 2 day co do dai l co giong nhau khong.
int Same(int i,int l)
{
    int j;
    for(j=0;j<l;j++)
        if(x[i-l-j]!=x[i-j]) return 0;
    return 1;    
}
// ham Kt day chua x[i] co 2 day con lien nhau trung nhau ko
int KT(int i)
{
    int j;
    for(j=1;j<=(i+1)/2;j++)
        if(Same(i,j)) return 0;
    return 1;
}
void Try(int i,int S)
{
     int j,v,T;
     for(v='A';v<='C';v++)
         {
          x[i]=v;
          if(KT(i))
                {
                if(v=='C')                          
                           T=S+1;
                else    T=S;                
                if((T+(N-i)/4)<Tmin)
                     {
                     if(i==N-1)
                          {
                          Tmin=T;
                          for(j=0;j<N;j++)
                          w[j]=x[j];
                          }      
                     else Try(i+1,T);     
                     }
                }
         } 
}
void ABC()
{
     int j;
     for(j=0;j<N;j++)
          {
          x[j]=0;
          w[j]=0;
          }
    Tmin=N;
    x[0]=65;
    Try(1,0);      
}
int main()
{
       printf("nhap N: ");
       scanf("%d",&N);
       int j;
       ABC();
       printf("so ki tu C it nhat la:%d \n",Tmin);
       for(j=0;j<N;j++)
            printf("%c",w[j]);
       getch();
}







}






