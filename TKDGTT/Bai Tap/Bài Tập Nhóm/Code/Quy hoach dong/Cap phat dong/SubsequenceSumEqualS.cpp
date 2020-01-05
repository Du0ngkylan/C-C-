/*
De bai:
    Cho day A co N phan tu
    Tim day con co tong = S.
    
Thuat toan:
    Xay dung bang phuong an:
        Goi F[i, j] = true/false = kha nang tao day con tong = j
            Khi chon day con tu trong tap A1...Ai
        Neu F[i-1, j] = true thi F[i, j] = true
        Neu F[i-1, j-a[i]] = true thi F[i, j] = true
        Ket qua la F[N, S]
        
    Co so:
        F[0, j] = false
        F[i, 0] = true
    
    Truy vet:
        Bat dau tu F[i, S]=1 voi i be nhat thi truy vet nhanh nhat
        Voi F[i, j]
            Neu F[i, j] = F[i-1, j] thi den do
            Ko thi den F[i-1, j-a[i]]
        Ket thuc neu i hoac j =0            
                    
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int n, s, *a;
bool *f;

void readData(){
    printf("Please enter number of elements: ");    
    scanf("%d", &n);
    a = (int *)calloc(n+1, sizeof(int));
    printf("Please enter value of each element.\n");
    for(int i=1; i<=n; i++){
        printf("A[[%d] = ", i);            
        scanf("%d", a+i);
    }
    printf("Please enter number you want to sum up (S): ");
    scanf("%d", &s);
}

void printData(){
    puts("Array:");
    for(int i=1; i<=n; i++){
        printf("%d ", a[i]);    
    }    
    puts("");
}

void buildSolution(){
    /*Prepare*/    
    f = (bool *)calloc((n+1)*(s+1), sizeof(bool));
    for(int j=0; j<=s; j++)
        f[j] = false;
    for(int i=0; i<=n; i++)        
        f[i*(s+1)] = true;
        
    /*Build solution table*/
    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            if(f[(i-1)*(s+1)+j]==true)    
                f[i*(s+1)+j] = true;
            else if(j>=a[i]){
                if(f[(i-1)*(s+1)+j-a[i]]==true)
                    f[i*(s+1)+j] = true;                        
            }                
        }    
    }
}

void showSolution(){
    if(f[n*(s+1)+s] == false){
        printf("Not exist subsequence which have sum = %d\n", s);
    } else{
        int i=0, j=s;
        while(f[i*(s+1)+j]==false)
            i++;
        while(i>0 && j>0){
            //printf("Go to (%d, %d)=%d\n", i, j, f[i*(s+1)+j]);            
            if(f[(i-1)*(s+1)+j-a[i]]==true){
                printf("%d + ", a[i]);    
                j -= a[i];                
            }                
            i--;                
        }
        printf("0 = %d\n", s);    
    }    
    
    free(f);
}

void findSolution(){
    /*
    Nhan xet 1:
        De tinh hang i cua F chi can hang i-1.
        Do do chi can hang gan nhat la du de tinh nhung khi do khong the truy vet duoc.
        Cach 1: dung 2 mang de tinh lan nhau
        Cach 2: dung 1 mang. Chu y la o sau phai tinh dua vao o truoc nen o sau phai duoc tinh truoc
            Neu khong o sau se lay gia tri moi de tinh dan den sai ket qua.
    Nhan xet 2:
        Neu den 1 buoc nao do ma F[i, s] = true thi khong can tinh nua                
    */
    
    puts("Advanced:");
    /*Prepare*/    
    f = (bool *)calloc(s+1, sizeof(bool));
    for(int j=0; j<=s; j++)
        f[j] = false;
    f[0] = true;
    
    /*Find solution*/        
    bool found = false;
    for(int i=1; i<=n && found==false; i++){
        for(int j=s; j>=1; j--){            
            if(f[j]==true){                
                if(j==s){                
                    found = true;
                }
            } else if(j>=a[i]){
                if(f[j-a[i]] == true){
                    f[j]=true;
                    if(j==s){
                        found = true;
                    }
                }    
            }  
        }    
    }
    if(found ==true)
        puts("Can be solved.");
    else
        puts("No solution.");        
    
}

int main(){
    readData();
    printData();

    buildSolution();
    
    /*
    for(int i=0; i<=n; i++){
        for(int j=0; j<=s; j++)
            printf("%d ", f[i*(s+1)+j]);    
        puts("");            
    }
    */
    
    showSolution();
    
    /*Advanced*/
    findSolution();
        
    puts("Done!");
    getch();
    return 0;
}
