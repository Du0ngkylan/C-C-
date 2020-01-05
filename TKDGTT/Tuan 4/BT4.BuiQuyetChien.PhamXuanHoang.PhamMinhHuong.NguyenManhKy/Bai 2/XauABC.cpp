//Giai bai toan ABC su dung ky thuat nhanh can
                      
#include<stdio.h>
#include<conio.h>
#define MAX 101
#define TRUE 1
#define FALSE 0

char X[MAX], Best[MAX];  //X[] de luu cac ky tu trong qua trinh xet
                         // Best[] de luu phuong an toi uu nhat        
int MinC;
int T[MAX];  // T[i] luu so luong ky tu C tu X[1] den X[i]
int N;       // Do dai cua xau can tim

//Ham same cho biet xau l ky tu ket thuc boi X[i] 
int Same( int i, int l )
{
     int j,k;
     j = i-l; //{ j la vi tri cuoi doan lien truoc no}
     for( k =0; k < l;++k)
     if ( X[i-k] != X[j-k]) return 0; // 2 xau khac nhau
     return  1; // 2 xau giong nhau
     
}

int Check( int i ) 
//Ham check cho biet phan tu X[i] 
//co lam mat tinh khong lap cua day X[1...i] khong
{
     int k = i + 1;
     for( int l = 1;l<= k;++l)
     if (Same(i,l))return 0; // X[i] khong thoa man
     return 1; // X[i] thoa man
     
}

void KeepResult()
{
     MinC = T[N];
     for (int i =1;i<= N;++i)
     Best[i] = X[i];
     
}


//THUAT TOAN QUAY LUI CO NHANH CAN

void Attempt( int i)
{
     
     for(char j = 'A';j<= 'C';++j)
     {
          X[i] =j ;
          if(Check(i))
          {
                      if(j == 67)T[i] = T[i-1] +1; // Xac dinh T[i] dua vao T[i-1];
                      else T[i] = T[i-1];
                      
                      if( T[i] + (N-i)>>2 < MinC)
                      {
                          if( i == N)KeepResult();
                          else 
                              Attempt(i+1);
                      }
          }
     }
}

void PrintResult()
{
     int i;
     printf("Xau ABC thoa man : ");
     for( int i =1;i<= N;++i)
     printf("%c",Best[i]);
     
}


int main()
{
    printf("bai toan xau ABC \n\n");
    do
    {
        printf("Nhap vao so n: ");
        scanf("%d", &N);
    }while(N<=0 || N>=100);
     T[0] = 0;
     MinC = N; //Khoi tao cau hinh toi nhat
     Attempt(1); //Xet cac kha nang cua X[1];
     PrintResult();
     getch();
     return 0;
}
