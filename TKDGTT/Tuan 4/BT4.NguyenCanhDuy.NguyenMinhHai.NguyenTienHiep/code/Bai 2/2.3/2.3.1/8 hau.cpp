#include<stdio.h>
#include<conio.h>

int Test_Col[100],Test_Up[500],Test_Down[500], S[100],Hau[100];
int count=0,n;
int r, c, i;

/*ham kiem tra o hang r, cot c co chap nhan hay khong*/
/* ham tra ve 0 neu chap nhan va tra ve 1 neu nguoc lai*/
int Test(int r,int c)
{
    int ok;
    if(Test_Col[c]==0&&Test_Up[c+r]==0&&Test_Down[r-c+n]==0)
    return ok=0; 
    else return ok=1;
}
    
//Chen 1 con hau vao hang r, cot c
void Insert(int r, int c)
{ 
                 
    Hau[r]=c;                                                                              
    Test_Col[c]=1;
    Test_Up[c+r]=1;
    Test_Down[r-c+n]=1;
}
     
//Lay lai 1 con hau o hang r, cot c
void Remote(int r, int c)
{
    Test_Col[c]=0;
    Test_Up[c+r]=0;
    Test_Down[r-c+n]=0;
}

//Xet cach xep quan hau vao hang row
void PutQueen(int r){
     if (r==n+1){
                 count++;
                 printf("\n%3d.",count);
                 for (i=1;i<=n;i++)
                    printf("%3d",Hau[i]);
  
                 }
     else{
          for (int c=1; c<=n; c++)
              if (Test(r,c)==0){
                               Insert(r,c);
                               PutQueen(r+1);
                               Remote(r,c);
                               }
          }            
}
      
main()
{       
    printf("\n so luong quan hau = ");
    scanf("%d",&n);
    printf("====Tat ca cac cach xep\nMoi hang xep mot quan hau, cac hang duoc liet ke tu hang thu nhat den hang cuoi cung====");
    
    //Bat dau dat cac quan hau, tu hang thu nhat
    PutQueen(1);
    printf("\nSo cach xep la %d",count);
    printf("\nNhan phim bat ky de ket thuc!");
    getch();
}
