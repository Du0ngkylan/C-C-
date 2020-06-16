#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int KtXau(char *a, int k)
{
    int i, j, t = 0;
    for(i=1; i<=k/2; i++)
    {
        for(j=1; j<=i; j++)
        if(*(a+k-j)!= *(a+k-j-i))
        {
            t++;
            break;
        }
    }
    if(t == k/2)
        return 1;
    return 0;
}

void InXau(char *a, int n)
{ 
    int i;
    puts("");
    for(i=0; i<n; i++)
    printf("%c", *(a+i));
    puts("");
}

void Tim_xau(char *a, int k, int n, int *LeastC, int c)
{
    char i;
    for(i='a'; i<='c'; i++)
    {
        int c1;
        *(a+k-1) = i;
        if(i == 'c')
             c1 = c + 1;
        else
            c1 = c;
        if(KtXau(a, k) && c1 < *LeastC)
        { 
          if(k==n)
          {
            InXau(a, n);
            *LeastC = c1;
          }
          else
              Tim_xau(a, k+1, n, LeastC, c);
        }
    }
}

int main()
{
    int n, LeastC;
    char *a;

    printf("BAI TOAN XAU ABC\n\n");
    do
    {
        printf("Nhap n = ");
        scanf("%d", &n);
    }while(n<=0 || n>=100);
    a = (char *)calloc(n, sizeof(char));
    LeastC = n;
    Tim_xau(a, 1, n, &LeastC, 0);
    getch();
}
