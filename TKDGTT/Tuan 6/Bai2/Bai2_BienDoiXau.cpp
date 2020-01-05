/*
Bai toan: Bien doi xau X cho truoc thanh xau Y 
    voi 3 phep bien doi: chen , xoa , thay the 
    sao cho so phep bien doi la it nhat

*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char x[100],y[100];
int m,n,c[100][100];

void docTep(){
    FILE *f;
    f = fopen("BienDoiXau.txt","r");
    if(!f){
        puts("Loi mo tep!");    
        getch();
        exit(0);
    }
    else{   
        fgets(x,255,f);
        fflush(stdin);       
        fgets(y,255,f);
        
        m=strlen(x)-1;
        n=strlen(y);
    }
    fclose(f);  
}


void In(){
    printf("M=%d, N=%d\n", m, n);
    printf("X=%s",x);
    printf("Y=%s\n",y);
}

int Min( int x, int y, int z)
{
    int t;
    if( x<y) t = x;
    else     t = y;
    if(z<t)  t =z;
    return t;
}

void dungBangPhuongAn()
{
  int i,j;
  for (i=0;i<m;i++) c[i][0]=i;
  for (j=0;j<n;j++) c[0][j]=j;

  for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
      if (x[i-1]==y[j-1])
            c[i][j]=c[i-1][j-1];
      else
       c[i][j]=Min(c[i][j-1],c[i-1][j-1],c[i-1][j])+1;
}

void truyVet()
{
    printf("\nPhuong an toi uu: %d \n",c[m][n]);
    while (m>0 || n>0)
    {
        if (x[m-1] == y[n-1])
        {
            m--;
            n--;
        }
        else
        {
            if (n>0 && c[m][n]-1==c[m][n-1])
            {
                printf("chen ky tu %c vao sau vi tri %d\n", y[n-1], m);    
                n--;
            }
            else if (m>0 && c[m][n]-1==c[m-1][n])
            {
                printf("xoa ky tu tai vi tri %d\n", m); 
                m--;
            }
            else
            {
                printf("thay the ky tu tai vi tri %d bang ky tu %c\n", m, y[n-1]);   
                x[m-1]=y[n-1];
                m--;
                n--;
            }
      
        }
    }

}
int main(){
    docTep();
    In();
    dungBangPhuongAn();
    truyVet();   
    getch();
    return 0;
}
