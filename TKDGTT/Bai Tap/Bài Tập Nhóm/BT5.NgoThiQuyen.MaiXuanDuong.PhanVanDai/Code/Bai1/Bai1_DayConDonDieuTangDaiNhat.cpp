/*
Bai toan: day con don dieu tang dai nhat.
    Tim day con dai nhat cua mot day da cho. Cac phan tu co the khong lien tiep
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int a[100],n,l[100];
void Doctep(){
    int i;
    FILE *f;
    f = fopen("DayConDonDieuTangDaiNhat.txt","r");
    if(!f){
        puts("Loi mo tep!");    
        getch();
        exit(0);
    }
    else{    
        fscanf(f,"%d",&n);
        for(i=1;i<=n;i++)
        fscanf(f,"%d",&a[i]);
    }
    fclose(f); 
}

void In(){
    int i;
    printf("\na[i]:  ");
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
}

int max(int i){
    int max=0,j;
    for(j=1; j<i; j++)
            if(l[j]>max && a[j]<a[i])    
                max = l[j];
    return max;
}

void BangPhuongAn(){
    int i;
    l[1] = 1;
    for(i=2;i<=n;i++)
        l[i] = max(i)+1;
    printf("\nl[i]:  ");       
    for(i=1;i<=n;i++)
        printf("%d ",l[i]);
}

void TruyVet(){
    int i=1,j; 
    for(int j=2; j<=n; j++)
        if(l[j]>l[i])
            i=j; 
    printf("\n\nDo dai day con don dieu tang dai nhat: %d\n", l[i]);  
    printf("\nTruy vet:\n"); 
    while(l[i]>1){
        printf("%d, ",a[i]);              
        for(j=i-1; j>0; j--)
            if(l[j]==l[i]-1 && a[j]<a[i]){
                i=j;
                break;                
            }                                   
    }
    printf("%d ", a[i]);
}

int main(){
    Doctep();
    In();
    BangPhuongAn();
    TruyVet();   
    getch();
    return 0;
}

