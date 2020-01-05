/*ho va ten: Bui Thi Thanh Huong*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char s1[100],s2[100],s;
int L[100][100], T[100][100], m, n, len;

/*ham doc tep*/
void docTep()
{
    FILE *f;
    f = fopen("xau_con_max.txt","r");
    
    if(f == NULL)
    {     
        puts("Khong tim thay file");    
        getch();
        exit(0);
    }
    else
    {
        fgets(s1,255, f);
        fflush(stdin);
        fgets(s2, 255, f);
        fflush(stdin);
        m=strlen(s1)-1;
        n=strlen(s2);
    }
    fclose(f);
}

/*ham in ra ket qua*/
void in()
{
    printf("m=%d, n=%d\n", m, n);
    printf("s1=%s",s1);
    printf("s2=%s\n",s2);
}

/*ham tim xau con dai nhat*/
void Xau_con()
{
     int i, j;
     /*co so quy hoach dong*/
     for (i=0; i<m; i++)
         L[i][0]=0;
     for (j=0; j<n; j++)
         L[0][j]=0;
         
     /*bang phuong an*/
     for (i=0; i<m; i++)
     {
         for (j=0; j<n; j++)
         {
             if (s1[i] = s2[j])
             {
                       L[i][j] = L[i-1][j-1] + 1;
                       T[i][j] = 0;
             }
             else
             {
                 if (L[i-1][j]>L[i][j-1])
                 {
                                       L[i][j] = L[i-1][j];
                                       T[i][j] = 1;
                 }
                 else
                 {
                     L[i][j] = L[i][j-1];
                     T[i][j] = -1;
                 }
             }
         }
     }
}

/* ham truy vet*/
void Tr()
{
     len = L[m][n];
     s = ' ';
     while (m>0 && n>0)    
     {
           if (T[m][n] == 0)
           {
                      s = s1[m] + s;
                      m--;
                      n--;
           }
           else
           {
               if (T[m][n] == 1)
                  m--;
               else
                   n--;
           }
     }
}

/*ham chinh*/
int main()
{
    docTep();
    Xau_con();
    Tr();
    in();
    getch();
    return 0;
}

