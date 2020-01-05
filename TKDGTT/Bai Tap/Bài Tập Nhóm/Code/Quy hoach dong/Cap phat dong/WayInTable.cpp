/*
De bai:
    Cho 1 bang so nguyen kich thuoc MxN
    Tu 1 o co the di toi 4 o xung quanh
    Tim 1 cach di tu o (1, 1) toi o (M, N) sao cho tong so cac o tren duong di la be nhat

Thuat giai:
    Xet 1 o o giua bang, co the di toi o do tu 4 o xung quanh.
    Nen khong the lam theo phuong phap quy hoach dong binh thuong
    Tuy nhien, neu coi bang so la 1 do thi va thuc hien thuat toan Dijkstra thi van dat duoc muc dich
    Hon nua, Dijkstra cung la 1 loai thuat toan quy hoach dong.
    
    Chuyen bang thanh do thi:
        Do do thi nay co rat nhieu dinh nhung tu 1 dinh chi co the di toi da toi 4 dinh khac,
        Do do ta luu do thi duoi dang danh sach canh.
        Chu y cac dinh o vien cua bang ko co du 4 canh noi
        Co tong cong MN dinh
            ->toi da 4MN canh
                so o khong the di len tren (hang dau tien) = N
                so o khong the di xuong duoi (hang duoi cung) = N
                so o khong the di sang trai (cot dau tien) = M
                so o khong the di sang phai (cot cuoi cung) = M
                -> so canh cua do thi la 4MN - 2M - 2N
        Chi phi di tu o T[i][j] sang o T[k][l] la T[k][l]
    Thuat toan Dijkstra:
        Xem chi tiet trong file doc di kem.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define INPUT_FILE "wayInTable.txt"
#define INFINITY 32700

typedef struct edge{int begin, end, weight;};

bool input = false, *notFixed, *trace;
int m, n, *t, *prev, *label, start = 0, finish, numOfEdges;
struct edge *edges;

/*
Read data from file. Change file path by #define
*/
void readData(){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
    
    if(file!=NULL){    
        fscanf(file, "%d %d", &m, &n);    
        t = (int *)calloc(m*n, sizeof(int));
        trace = (bool *)calloc(m*n, sizeof(bool));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                fscanf(file, "%d", t+i*n+j);   
                trace[i*n+j] = false;
            }    
        }
    
        input = true;
    
        fclose(file);
    }
}

/*
Print data
*/
void printData(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(trace[i*n+j]==true)
                printf("[%3d] ", t[i*n+j]);
            else
                printf(" %3d  ", t[i*n+j]);
        }    
        puts("");
    }    
    puts("");
}

/*
Return index of upper cell. If that cell doesn't have upper cell, return -1
*/
int up(int i){
    if(i<n)
        return -1;
    else
        return i-n;        
}

/*
Return index of lower cell. If that cell doesn't have lower cell, return -1
*/
int down(int i){
    if(i/n == m-1)
        return -1;
    else
        return i+n;            
}

/*
Return index of left cell. If that cell doesn't have left cell, return -1
*/
int left(int i){
    if(i%n == 0)
        return -1;
    else
        return i-1;        
}

/*
Return index of right cell. If that cell doesn't have right cell, return -1
*/
int right(int i){
    if(i%n == n-1)  
        return -1;
    else
        return i+1;        
}

/*
Assign a new edge
*/
void assign(int k, int begin, int end){
    edges[k].begin = begin;
    edges[k].end = end;
    edges[k].weight = t[end];       
}

/*
Build graph from table of data
*/
void buildGraph(){
    finish = m*n-1;    
    numOfEdges = 4*m*n - 2*m -2*n;
    int k=0;
    edges = (edge *)calloc(numOfEdges, sizeof(edge));
    for(int i=start; i<=finish; i++){
        if(up(i) != -1){                    
            assign(k, i, up(i));
            k++;
        }
        if(down(i) != -1){            
            assign(k, i, down(i));
            k++;
        }
        if(left(i) != -1){
            assign(k, i, left(i));
            k++;
        }
        
        if(right(i) != -1){
            assign(k, i, right(i));                      
            k++;
        }
    }
}

/*
Print list of edges
*/
void printGraph(){
    puts("+---+-------+-----+--------+");
    puts("| # | Begin | End | Weight |");
    puts("+---+-------+-----+--------+");    
    for(int i=0; i<numOfEdges; i++){
        printf("|%3d|  %3d  | %3d |  %4d  |\n", i+1, edges[i].begin, edges[i].end, edges[i].weight);    
    }    
    puts("+---+-------+-----+--------+");
}

/*
Print label array
*/
void printLabels(){
    for(int i=start; i<=finish; i++){
        printf("%d->%d, ", i, label[i]);    
    }    
    puts("");
}

/*
If exist direct way from 'begin' to 'end', return 'weight'. Else return INFINITY
*/
int getWeight(int begin, int end){
    for(int i=0; i<numOfEdges; i++){
        if(edges[i].begin == begin && edges[i].end == end)
            return edges[i].weight;    
    }            
    return INFINITY;
}

/*
Find min label and still be notFixed
*/
int min(){
    int i=start+1, min = -1;
    while(min == -1){
        if(notFixed[i]==true){
            min = i;   
        }   
        i++;                                            
    }  
    while(i<=finish){
        if(label[i]<label[min] && notFixed[i]==true)
            min = i;     
        i++;               
    }      
    return min;
}

/*
Perform Dijkstra algorithm
*/
void performDijkstra(){
    /* Initialize */   
    puts("Initialzing data to find a way..."); 
    notFixed = (bool *)calloc(finish+1, sizeof(bool));
    prev = (int *)calloc(finish+1, sizeof(int));
    label = (int *)calloc(finish+1, sizeof(int));
    for(int i=start; i<=finish; i++){
        label[i] = INFINITY;
        notFixed[i] = true;
        prev[i] = start;
    }
    label[start] = 0; notFixed[start] = false; trace[start] = true;
    label[1] = t[1]; 
    label[n] = t[n];    
    puts("Finish!");
    
    /* Perform */
    puts("Finding way...");
    int i;
    while(true){
//        printLabels();
        i = min();
        if(i == finish)
            break;
//        printf("\tMin = %d, T[%d] = %d\n", i, i, t[i]);
        notFixed[i] = false;
        for(int j=start+1; j<=finish; j++){
            if(notFixed[j]==true && getWeight(i, j)<INFINITY){
                if(label[j] > label[i] + getWeight(i, j)){
                    label[j] = label[i] + getWeight(i, j);
                    prev[j] = i;
                }
            }
        }    
    }
    puts("Finish!\n");
}

/*
Show solution
*/
void showSolution(){
    int i=finish;
    while(i != 0){
        trace[i] = true;
        i = prev[i];    
    }
    printData();
    printf("\nTotal: %d\n", label[finish]+t[start]);
}

/*
Main function
*/
int main(){
    readData();
    
    if(input==true){
        printData();
        buildGraph();
//        printGraph();

        performDijkstra();
        
        showSolution();        
    } else{
        printf("Error in reading data from %s\n", INPUT_FILE);    
    }
    
    puts("Done!");
    getch();
    return 0;
}
