#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int n,a[100],t=0;
struct toado{
       int x;
       int y;
       }toado;
struct toado point[100],diem;  
void doctep()
{
     int i,x,y;
     printf("Toa do cac dinh:\n");
     FILE *f;
     f= fopen("dodaimin.txt","r");
     if(!f)
     {
           printf("Loi mo tep.");      
           getch();
           exit(1);
     }
     fscanf(f,"%d",&n);
     for(i=1;i<=n;i++)
     {
           fscanf(f,"%d%d",&point[i].x,&point[i].y);
           printf("%d %d\n",point[i].x,point[i].y);                            
     }          
     printf("===============\n");
}

float khoangcach(struct toado point1, struct toado point2)
{
      float temp1,temp2;
      temp1 = point2.x - point1.x;
      temp2 = point2.y - point1.y;
      return sqrt(temp1*temp1 + temp2*temp2);      
}

void swap(int x, int y)
{
    int temp; 
      temp=x;
      x=y;
      y=temp;             
}

void sapxepX(struct toado point3[100])
{
    int i;
    for(i=1;i<=n;i++)
    for(int j=i+1;j<n;j++)
    {
       if(point[i].x>point[j].x)
       {
        swap(point[i].x,point[j].x);                       
       }                 
    }      
}

int toadoXmin()
{
    
    int i,min=point[1].x;
    for(i=1;i<=n;i++)
    {
       if(point[i].x<min)
       {
        min=point[i].x;
       }                          
    }
    return min;    
}

int toadoXmax()
{
    int i,max=point[1].x;
    for(i=1;i<=n;i++)
    {
       if(point[i].x>max)
       {
        max=point[i].x;
       }                          
    }
    return max;    
}

/*struct toado timYgannhat(struct toado point1)
{
     int i,k;
     int temp= abs(point1.y  - point[1].y);
     for(i=1;i<=n;i++)
     {
        if(abs(point1.y-point[i].y)<temp)
        {
        temp=abs(point1.y-point[i].y);                               
        k=i;
        }
     }
     return point[k];
}*/

int kiemtra(int left,int right)
{
    int dem=0,t=0;
    for(int i=1;i<=n;i++)
    {
     if(left<=point[i].x<=right)
     {
      a[t]=i;
      t++; 
      dem++;
      }
    }

    if(dem>=2) return 1;
    return 0;
}
float khoangcachMin(int left, int right)
{
      
    int mid = (left+right)/2;
    int i,j;
    float d1,d2;
    if(kiemtra(left,right)==1)
    {                         
     khoangcach(point[a[0]],point[a[1]]);                
    }
    else{
        d1=khoangcachMin(left,mid);
        d2=khoangcachMin(mid,right);                                
        }
    if(d1<d2) return d1;
    return d2;      
}
int main()
{
        int min,max;  
        doctep();
        printf("%f",khoangcach(point[1],point[2]));
        printf("\n%d",toadoXmin());
        min=toadoXmin();
        max=toadoXmax();
        printf("\n%d",toadoXmax());
        printf("\n%f",khoangcachMin(min,max));
        getch();
}
