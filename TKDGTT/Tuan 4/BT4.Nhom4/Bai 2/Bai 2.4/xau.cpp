/*tim 1 xau con do dai N chi gom 3 ki tu A B C, so ki tu C la it nhat, trong xau khong co 2 doan con lien ke giong nhau*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
//kiem tra xau a co 2 doan con gan nhau giog nhau khong
int KtXau(char *a, int k)
{
    int t = 0;
    for(int i=1; i<=k/2; i++)
    {
            for(int j=1; j<=i; j++)
                    if(a[k-j]!=a[k-j-i])
                    {
                      t++;
                      break;
                    }
    }
    if(t==k/2)
              return 1;
    return 0;
}

void InXau(char *a, int n)
{
    puts("");
    for(int i=0; i<n; i++)
       printf("%c", a[i]);
    puts("");
}

void Try(char *a, int k, int n, int *BestC, int c,char *b)
{

    for(char i='a'; i<='c'; i++)
    {
        int c1;//dem so ki tu C trong chuoi
        a[k-1] = i;
        if(i == 'c')
             c1 = c + 1;
        else
             c1 = c;
        
        //kiem tra so ki tu c co nho hon soki tu C nho nhat hien co khong va trong a co 2 doan con gan nhau giong nhau khong
        if(KtXau(a, k) && c1 < *BestC)
        {
                    if(k==n)
                    {
                       
                         *BestC = c1;
                         //luu lai xau tot nhat hien co vao mang b
                         int j;
                         for(j=0;j<n;j++)
                                        b[j]=a[j];
                         
                    }
                     else
                         Try(a, k+1, n, BestC, c1,b);
        }
    }
}

int main()
{
    int n;//do dai xau
    char *a;//mang chua cac ki tu trong xau
    int BestC;
    printf("BAI TOAN XAU ABC:\n\n");
    do
    {
                printf("Nhap n = ");
                scanf("%d", &n);
    }while(n<=0 || n>=100);
    a = (char *)calloc(n, sizeof(char));
    char *b;
    b = (char *)calloc(n, sizeof(char));
    BestC = n;//so ki tu C it nhat trong thoi diem hien tai
    Try(a, 1, n, &BestC, 0,b);
    InXau(b, n);
    printf("==>so ki tu C it nhat co the la %d",BestC);
    getch();
  
}
