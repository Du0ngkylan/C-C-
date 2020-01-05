/*
De bai:
    Kim tu thap co n tang
    Tang 1 o tren cung, tang n o duoi cung. Tang i co i phong
    Tu 1 phong tang tren chi di xuong dc 2 phong ngay duoi chan no.
    Moi phong co luong vang G[i][j]
    Tim duong di tu dinh xuong chan kim tu thap sao cho so vang lay duoc la toi da.    

Thuat giai:
    Xay dung bang phuong an:
        Phong (i, j) la phong j cua tang i.
        Goi C[i, j] la so vang lay duoc nhieu nhat khi toi phong (i,j).
        De den duoc phong (i, j) co the di tu (i-1, j-1) hoac (i-1, j)
        -> C[i, j] = max {C[i-1, j-1], C[i-1, j]} + G[i, j]
        C[i, 0] = 0
        
        Ket qua cuoi cung: so vang toi da co the lay la gia tri lon nhat cua C[n, j]
    
    Truy vet:        
        Neu C[i, j] = C[i-1, j]+G[i, j] thi xet o C[i-1, j]
        Neu khong xet o C[i-1, j-1]
        Xet toi khi gap C[1, 1]
            
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define INPUT_FILE "pyramid.txt"

bool input = false;
int *g, n, *c, *room;

/*
Read data from file. Change file path by #define
*/
void readData(){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
     
    fscanf(file, "%d", &n);
    g = (int *)calloc((n+1)*(n+1), sizeof(int));
    room = (int *)calloc(n+1, sizeof(int));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            fscanf(file, "%d", g+i*(n+1)+j);
        }
        for(int j=i+1; j<=n; j++){
            g[i*(n+1)+j] = 0;    
        }
        room[i] = 0;
    }

    input = true;

    fclose(file);
}

/*
Print pyramid
*/
void printData(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(room[i] == j)
                printf("[%3d] ", g[i*(n+1)+j]);    
            else
                printf(" %3d  ", g[i*(n+1)+j]);    
        }    
        puts("");
    }
    puts("");
}

/*
Build solution table
*/
void buildSolution(){
    /*Prepare*/
    c = (int *)calloc((n+1)*(n+1), sizeof(int));    
    for(int i=0; i<=n; i++){
        c[i*(n+1)] = 0;
        c[i] = 0;
    }
    
    /*Build solution table*/
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            c[i*(n+1)+j] = c[(i-1)*(n+1)+j];    
            if(c[(i-1)*(n+1)+j-1] > c[i*(n+1)+j])
                c[i*(n+1)+j] = c[(i-1)*(n+1)+j-1];
            c[i*(n+1)+j] += g[i*(n+1)+j];
        }    
    }
}

void showSolution(){
    /*Find max c[n, j]*/    
    int i=n, j=1;
    for(int k=2; k<=n; k++){
        if(c[n*(n+1)+j] < c[n*(n+1)+k])    
            j=k;
    } 
    printf("Max gold can carry: %d\n", c[n*(n+1)+j]);
    
    /*Trace*/
    while(i>0){
        room[i] = j;
        if(c[i*(n+1)+j] == c[(i-1)*(n+1)+j-1] + g[i*(n+1)+j])    
            j--;
        i--;            
    }
    
    /*Display*/
    printData();
}

/*
Main function
*/
int main(){
    readData();

    if(input==true){
        printData();
        buildSolution();
        showSolution();
    }
    else
     puts("Error in reading data!");

    puts("Done!");
    getch();
    return 0;
}
