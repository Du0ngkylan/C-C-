/*
De bai:
    Co N goi keo.
    Goi thu i co A[i] vien keo.
    Chia n goi keo ra thanh 2 phan sao cho so keo giua 2 phan chenh lech it nhat.
    
Thuat giai:
    Vi phai chia ra lam 2 phan nen ta di tim phan it hon.
    Goi S la so keo cua phan it hon -> S<=T/2 voi T la tong so keo.
    Phan con lai la T-S => chenh lech giua 2 phan la T-2S (min -> S max)
    Vay, phai tim Smax<=T/2 va co day con tong=S.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INPUT_FILE "candy.txt"

bool input = false, *f, *part1;
int *a, n, t1=0, t=0, s=0;

void readData(){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
     
    fscanf(file, "%d", &n);
    a = (int *)calloc(n+1, sizeof(int));
    for(int i=1; i<=n; i++){
        fscanf(file, "%d", a+i);                
        t1+=a[i];
    }
    t = t1/2;        

    input = true;

    fclose(file);
}

void printData(){
    puts("+----+-------+");    
    puts("| #  | Candy |");
    puts("+----+-------+");    
    for(int i=1; i<=n; i++)
        printf("| %-3d| %-5d |\n", i, a[i]);
    puts("+----+-------+");            
}

void buildSolution(){
    /*Preapare*/    
    f = (bool *)calloc((n+1)*(t+1), sizeof(bool));
    for(int j=0; j<=t; j++)
        f[j] = false;
    for(int i=0; i<=n; i++)        
        f[i*(t+1)] = true;
        
    /*Build solution table*/        
    for(int i=1; i<=n; i++){
        for(int j=1; j<=t; j++){
            if(f[(i-1)*(t+1)+j] == true)
                f[i*(t+1)+j] = true;    
            else if(j>=a[i]){
                if(f[(i-1)*(t+1)+j-a[i]] == true)    
                    f[i*(t+1)+j] = true;    
            }                
        }    
    }
}

void showSolution(){
    puts("\nSolution");
    /*Find s max*/
    int i, j;
    for(j=t; j>0 && s==0;j--){
        for(i=1; i<=n; i++){
            if(f[i*(t+1)+j] ==true){
                s = j;
                break;   
            }                   
        }
    }
    
    /*Prepare part1*/
    part1 = (bool *)calloc((n+1), sizeof(bool));
    for(int k=1; k<=n; k++)
        part1[k]=false;
    
    /*Empty part 1*/                      
    while(i>0 && j>0){                    
        if(f[(i-1)*(s+1)+j-a[i]]==true){
            part1[i] = true;
            j -= a[i];                
        }                
        i--;                
    }
    
    /*Part 1*/
    puts("+------------+");        
    puts("|Part 1      |");
    puts("+----+-------+");    
    puts("| #  | Candy |");
    puts("+----+-------+");
    for(int k=1; k<=n; k++){
        if(part1[k] == true)
            printf("| %-3d| %-5d |\n", k, a[k]);
    }
    puts("+----+-------+");
    printf("|    | %-5d |\n", s);
    puts("+----+-------+");

    /*Part 2*/
    puts("\n+------------+");        
    puts("|Part 2      |");
    puts("+----+-------+");    
    puts("| #  | Candy |");
    puts("+----+-------+");
    for(int k=1; k<=n; k++){
        if(part1[k] == false)
            printf("| %-3d| %-5d |\n", k, a[k]);
    }
    puts("+----+-------+");
    printf("|    | %-5d |\n", t1-s);    
    puts("+----+-------+");    
    
    /*Different*/
    printf("Different: %d", t1-s-s);
}

int main(){
    readData();

    if(input==true){
        printData();
        buildSolution();

       /*
        for(int i=0; i<=n; i++){
            for(int j=0; j<=t; j++)
                printf("%d ", f[i*(t+1)+j]);    
            puts("");            
        }
        */
        
        showSolution();
    }
    else
     puts("Error in reading data!");

    getch();
    return 0;
}
