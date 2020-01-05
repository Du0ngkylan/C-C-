#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



int KtXau(char *a, int k){
    int t = 0;
    for(int i=1; i<=k/2; i++){
        for(int j=1; j<=i; j++)
            if(*(a+k-j)!=*(a+k-j-i)){
                t++;
                break;
            }
    }
    if(t==k/2)
        return 1;
    return 0;
}

void InXau(char *a, int n){
    puts("");
    for(int i=0; i<n; i++)
        printf("%c", *(a+i));
    puts("");
}

void Try(char *a, int k, int n, int *BestC, int c){
    for(char i='a'; i<='c'; i++){
        int c1;
        *(a+k-1) = i;
        if(i == 'c')
            c1 = c + 1;
        else
            c1 = c;
        if(KtXau(a, k) && c1 < *BestC){
            if(k==n){
                InXau(a, n);
                *BestC = c1;
            }
            else
            Try(a, k+1, n, BestC, c);
        }
    }
}

int main(){
    int n;
    char *a;
    int BestC;
    printf("BAI TOAN XAU ABC\n\n");
    do
    {
        printf("Nhap n = ");
        scanf("%d", &n);
    }
    while(n<=0 || n>=100);
    a = (char *)calloc(n, sizeof(char));
    BestC = n;
    Try(a, 1, n, &BestC, 0);
    getch();
}
