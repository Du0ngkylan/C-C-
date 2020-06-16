#include<stdio.h> 
#include<conio.h> 
int x[100];//mag luu gia tri can tim 
int count; 

void nhap(int &n,int &k) 
{ 
     printf("nhap : n = "); 
     scanf("%d",&n); 
     printf("nhap : k = "); 
     scanf("%d",&k); 
     for(int i=1;i<=k;i++) 
     x[i]=i; 
} 

void xuatx(int &k) 
{ 
     for(int i=1;i<=k;i++) 
     printf("%5d",x[i]); 
} 
  
void tohop(int i,int &n, int &k) 
{ 
     int j; 
     for(j=1;j<=n;j++) 
     if(x[i-1]+1 <= j && j <= n-k+i) 
     { 
                           x[i]=j; 
                           if(i<k) 
                           tohop(i+1,n,k); 
                           else 
                           { 
                           printf("\nnghiem thu %3d la :  ",++count); 
                           xuatx(k); 
                           printf("\n"); 
                           } 
     } 
} 
int main() 
{ 
    int n,k; 
    nhap(n,k); 
    tohop(1,n,k); 
    getch(); 
    return 0; 
} 
