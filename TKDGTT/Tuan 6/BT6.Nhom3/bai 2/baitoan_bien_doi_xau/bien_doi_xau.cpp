/*ho ten: Bui Thi Thanh Huong*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char x[100], y[100], x1[100], y1[100];
int m, n, C[100][100];

void xu_ly_xau(char *xp, char *dich)
{
    int i;
    int len = strlen(xp);
    dich[0]=' ';
    for(i=0; i<=len; i++)
       dich[i+1] = xp[i];    
}

void docTep()
{
    FILE *f;
    f = fopen("bien_doi_xau.txt","r");
    
    if(f == NULL)
    {     
        puts("Khong tim thay file");    
        getch();
        exit(0);
    }
    else
    {
        fgets(x1, 255, f);
        fflush(stdin);
        fgets(y1, 255, f);
        
        m=strlen(x1)-1;
        n=strlen(y1);
        
        xu_ly_xau(x1, x);
        xu_ly_xau(y1, y);
    }
    fclose(f);
}

void in()
{
    printf("M=%d, N=%d\n", m, n);
    printf("X=%s",x);
    printf("Y=%s\n",y);
}

int min(int i, int j, int k)
{
    int min = i;
    if(min > j)
        min = j;
    if(min > k)
        min = k;
    return min;    
}

void BangPhuongAn()
{
     int i, j;
    /*Co so quy hoach dong*/    
    for(i=0; i<=m; i++)
        C[i][0] = i;
    for(j=0; j<=n; j++)
        C[0][j] = j;
        
    /*Dung bang phuong an*/        
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            if(x[i] == y[j])
                C[i][j] = C[i-1][j-1];
            else
                C[i][j] = min(C[i-1][j-1], C[i-1][j], C[i][j-1])+1;          
        }
}

/* truy vet */
void Tr()
{
    int i=m, j=n;
    while(i>0 || j>0)
    {
        if(x[i] == y[j])
        {
            i--;
            j--;
        }    
        else
        {
            if(i>0)
            {
                if(j>0)
                {
                    if(C[i][j] == C[i-1][j-1]+1)
                    {
                        printf("thay the ky tu tai vi tri %d bang ky tu %c\n", i, y[j]);    
                        i--;
                    }                                        
                    else
                    {
                        printf("chen ky tu %c vao sau vi tri %d\n", y[j], i);    
                        j--;
                    }
                }   
                else
                {
                    printf("xoa ky tu tai vi tri %d\n", i);    
                    i--;
                }
            }
            else 
                 if(j>0)
                 {
                        printf("chen ky tu %c vao sau vi tri %d\n", y[j], i);    
                        j--;
                 }    
        }
    }    
}

int main(){
    docTep();
    in();
    BangPhuongAn();
    Tr();   
    getch();
    return 0;
}

