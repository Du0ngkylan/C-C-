#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

enum {hs=100};
int a[hs][hs],b[hs],v[hs];
int x,y,m,n;

void tb(char *s){
    puts(s);
    getch();
    exit(0);
}

char *fi="dothi.txt";

void doctep(){
    FILE *f;
    f = fopen(fi,"r");
    if (!f) tb("loi mo tep!");
    fscanf(f,"%d%d",&n,&m);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            a[i][j] = 0;
        }
    }
    for (int k = 0; k < m; k++){
        fscanf(f,"%d%d",&i,&j);
        a[i][j]=1;
        a[j][i]=1;
    }
    fclose(f);
}

void inmatran(){
    for (int i = 1; i <= n; i++){
        for (int j = 1;j <= n; j++){
            printf("%5d",a[i][j]);
        }
        puts("");
    }
}

void khoi_dau(){
    for (int i = 1; i <= n; i++){
         b[i] = 1;
    }
}

int cung(int i, int j){
    return a[i][j] > 0;
}

void tim(int k){
    if (k==y) tb("co\n");
    for (int i=1;i<=n;i++){
        if (b[i]==1 && cung(k,i)){
            b[i]=0;
            tim(i);
        }
    }
}
int main(){
    doctep();
    inmatran();
    printf("nhap hai dinh cua do thi: \n "); scanf("%d%d",&x,&y);
    khoi_dau();
    b[1]=0;
    tim(x);
    puts("khong co\n");
   
    
    getch();
}
