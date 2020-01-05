/*Tim chu trinh Hamilton bang quay lui
Hamilton.txt
10 
0 1 1 0 1 1 0 0 0 0 
1 0 1 0 0 0 0 0 1 0 
1 1 0 1 0 0 1 0 0 0 
0 0 1 0 1 0 0 0 0 1 
1 0 0 1 0 0 0 1 0 0 
1 0 0 0 0 0 1 0 0 1 
0 0 1 0 0 1 0 1 0 0 
0 0 0 0 1 0 1 0 1 0 
0 1 0 0 0 0 0 1 0 1 
0 0 0 1 0 1 0 0 1 0  
Ket qua la:
   1   2   9   8   5   4  10   6   7   3   1 
   1   2   9  10   6   7   8   5   4   3   1 
   1   3   2   9   8   7   6  10   4   5   1 
   1   3   2   9  10   4   5   8   7   6   1 
   1   3   4   5   8   7   6  10   9   2   1 
   1   3   7   6  10   4   5   8   9   2   1 
   1   5   4  10   6   7   8   9   2   3   1 
   1   6   7   8   5   4  10   9   2   3   1  
*/   
#include<stdio.h>
#define max 20

int a[max][max];
int b[max], c[max];
int n;

void init()
{
    FILE *f = fopen("Hamilton.txt","r");
    fscanf(f,"%d",&n);
    for (int k=0; k < n; k++)
        for (int j=0; j < n; j++)
            fscanf(f,"%d",&a[k][j]);
    for (k=0; k < n; k++) b[k] = 0;
    c[0] = 0; b[0] = 1;// Xu?t phát t? d?nh 0
}

void showpath()
{
    for (int k=0; k < n; k++) printf("%4d",c[k]+1);//In ra s? hi?u d?nh+1
    printf("%4d\n",c[0]+1);
}
void Hamilton(int j)
{
    for (int k = 0; k < n; k++)
        if (b[k]==0 && a[c[j-1]][k])
        {
            b[k] = 1; c[j] = k;
            if (j==n-1)
            {
                if(a[c[j]][c[0]])showpath();
            }
            else Hamilton(j+1);
            b[k] = 0;
        }
}

void main()
{
    init();
    Hamilton(1);
}
