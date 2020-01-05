#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <math.h>
#include <fstream.h>
#define B 1000000 
int n;
double a[100][100],bestcost=B;// ma tran ke va gia tri lon nhat.
int x,y,p[100],q[100];
void doctep(char * tep)// lay du lieu cua n,M va cac gia tri aij tu file ban dau
{
    double t;
    ifstream f(tep,ios::in);
    if(!f)
    {     
          cerr<< "Loi mo tep" ; getch(); exit(0);  
    }
    f >> n;    //lay gia tri n
    cout<<n<<"\n";
    for(int i=1;i<=n;i++)
    {   for(int j=1;j<=n;j++)             
        {
            f >> t;
            a[i][j]=t;
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
    f >> x >> y;    //lay diem dau va diem cuoi cua do thi            
    cout<<"Diem xuat phat la "<<x <<" va diem ket la "<<y;
    getch();
}
void search(int i,double V){
    for(int j=1;j<=n;j++){         // cac truong hop co the
                                   // neu co duong di tu i->j voi chi phi nho hon bestcost thi ket nap vao
            if((a[i][j]!=0)  && (V + a[i][j] < bestcost) && p[j]==0){
                    p[j]=1;       // danh dau diem j da di qua             
                    if(j==y){     // neu toi dich
                             bestcost = V + a[i][y]; //cap nhat lai bestcost
                             for(int k=1;k<=n;k++)   //luu ket qua
                             {        q[k]=p[k];                                                                          
                             }                             
                    }
                    else{
                             search(j,V + a[i][j]); // tim duong                               
                    }
                    p[j]=0;       // bo danh dau diem j da qua           
            }                    
    }     
}
int main(){
    doctep("data1.txt");
    search(x,0);
    if(bestcost==B) cout<<"Khong co duong di tu "<<x<<" den"<<y;
    else  {
          cout<<"\nDuong di ngan nhat trong do thi la:"<<bestcost<<"\n";
          cout<<x;
          for(int i=1;i<=n;i++)
                  if(q[i]==1)
                       cout<<"->"<<i;
    }                      
    getch();         
    return 0;          
}
