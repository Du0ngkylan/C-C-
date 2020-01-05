#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int n,m,c[100][100];
char x[100],y[100],x1[100],y1[100];
void dichxau(char *nguon,char *dich)
{
     int i;
     int dodai = strlen(nguon);
     dich[0] =' ';
     for(i=0;i<= dodai;i++){
                 dich[i+1] = nguon[i];
                 }
}
void doctep()
{
     int i,j;
     FILE *f;
     f = fopen("doixau.txt","r");
     if(!f){
            puts("loi mo tep");
            }
     fgets(x1,255,f);
     fflush(stdin);
     fgets(y1,255,f);
     m = strlen(x1)-1;
     n = strlen(y1)-1;
     dichxau(x1,x);
     dichxau(y1,y);
     fclose(f);
}
void in()
{
     printf("do dai cua xau X = %d\n",n);
     printf("do dai cua xau Y = %d\n",m);
     printf("X = %s\n",x);
     printf("Y = %s\n",y);
}
int min(int a,int b,int c)
{
     int min =a;
     if(min > b)
            min =b;
     if(min> c)
             min =c;
     return min;
}
void bangphuongan()
{
     int i,j;
     for(i=0;i<=m;i++){
                       c[i][0] = i;//so phep bien doi it nhat x1..xi thanh xau rong= i lan su dung phep xoa
                       }
     for(j=0;j<=n;j++){
                       c[0][j] = j;//so phep bien doi it nhat bien xau rong thanh y1..yj = j lan su dung phep chen
                       }
     for(i=1;i<=m;i++){
                       for(j=1;j<=n;j++){
                                         if(x[i] == y[j]){
                                                  c[i][j] = c[i-1][j-1];
                                                  }
                                         else{
                                              c[i][j] = min(c[i][j-1],c[i-1][j-1],c[i-1][j] )+1;
                                              }
                                              }
                                              }
}

void truyVet(){
    int i=m, j=n;
    while(i>0 && j>0){
        if(x[i]==y[j]){
            i--;
            j--;
        }    
        else{
            if(i>0){
                if(j>0){
                    if(c[i][j]==c[i-1][j-1]+1){
                        printf("su dung phep thay the ky tu tai vi tri %d bang ky tu %c\n", i, y[j]);    
                        i--;
                    }                                        
                    else
                        printf("Su dung phep chen ky tu %c vao sau vi tri %d\n", y[j], i);    
                    j--;
                }   
                else{
                    printf("Su dung phep xoa ky tu %c tai vi tri %d\n",x[i], i);    
                    i--;
                }
            }else if(j>0){
                printf("Su dung phep chen ky tu %c vao sau vi tri %d\n", y[j], i);    
                j--;
            }    
        }
    }    
}
int main()
{
    doctep();
    in();
    bangphuongan();
    truyVet();
    getch();
    return 0;
}
                                  
     
     
     
     
