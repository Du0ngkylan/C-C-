//Tim cap diem gan nhat tren mat phang
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define N 8000

//struct luu toa do (x,y) cua diem
struct coordinate {
       float x;
       float y;
       } coordinate;

//ham truyen gia tri cho cac diem
void input(struct coordinate point[]) {
     FILE *fp;
     int i=0;
     char s[20];
     fp = fopen("input.txt","r");
     if(fp==NULL)  printf("Canot open file.\n");
     while(fgets(s,80,fp) !=NULL) {
                          sscanf(s,"%f%f",&point[i].x,&point[i].y);
                          printf("%f,%f\n",point[i].x , point[i].y);
                          i++;
                          }
     }
//struct luu tham so truyen vao cho ham closest_pair
struct thamso {
       int left;
       int right;
       struct coordinate point[N];
       } thamso;
//ham sap xep cac diem tqang dan theo toa do x
void quicksortX(struct coordinate arr[],int low, int high) {
     int i=low;
     int j=high;
     float x=0,y=0;
     float z = arr[(i+j)/2].x;
     do {
         while (arr[i].x<z) i++;
         while (arr[j].x >z) j--;
         if(i <=j) {
              x=arr[i].x;
              y=arr[i].y;
              arr[i].x = arr[j].x;
              arr[i].y = arr[j].y;
              arr[j].x = x;
              arr[j].y =y;
              i++;
              j--;
              }
         }
         while (i<=j);
         if(low <j) quicksortX(arr,low,j);
         if(i<high) quicksortX(arr,i,high);
     }
//tinh khoang cach hai diem
float distance(struct coordinate point1,struct coordinate point2) {
      float temp1,temp2;
      temp1=point2.x - point1.x;
      temp2 = point2.y-point1.y;
      return sqrt(temp1*temp1 + temp2*temp2);
      }
//ham tinh min cua 2 gia tri
float min(float a,float b) {
      if(a<b) return a;
      return b;
      }
//ham sap xep cac diem tang dan theo toa do y
void quicksortY(struct coordinate arr[],int low,int high) {
     int i=low;
     int j=high;
     float x=0,y=0;
     float z=arr[(low+high)/2].y;
     do {
         while (arr[i].y <z) i++;
         while (arr[j].y >z) j--;
         if(i<=j) {
                  x=arr[i].x;
                  y=arr[i].y;
                  arr[i].x = arr[j].x;
                  arr[i].y = arr[j].y;
                  arr[j].x =x;
                  arr[j].y =y;
                  i++;
                  j--;
                  }
         }
         while (i<=j);
         if(low < j)  quicksortY(arr,low,j);
         if(i<high)   quicksortY(arr,i,high);
     }
void sortX(struct coordinate toado[],int n) {
     quicksortX(toado,0,n-1);
     }

void sortY(struct coordinate toado[], int n) {
     quicksortY(toado,0,n-1);
     }
//tao 1 stack luu gia tri tra ve cua ham closest_pair.
//Ham push() day 1 gia tri vao stack
//Ham pop() lay gia tri ra khi stack
float stack[100];
int ip=-1;
void push(float v) {
     ip++;
     stack[ip] =v;
     
     return;
     }
float pop() {
      if(ip >=0) {
            float v = stack[ip];
            
            ip--;
            return v;
            }
      else {
           printf("error: ip = %d\n",ip);
           return -1;
           }
      }
// ham tinh toan khoang cah ngan nhat
void closest_pair(void *args) {
     struct thamso *temp = (struct thamso*)args;
     int i,j,mid,countL =0,countR =0,tempLeft,tempRight;
     float midX,dL,dR,temp1,delta;
     struct coordinate tempL[N],tempR[N];
     tempLeft = temp->left;
     tempRight = temp ->right;
     mid = (temp->left + temp->right) /2;
     midX = temp->point[mid].x;
     if((temp ->right - temp ->left) ==1){
              push(distance(temp->point[temp->right],temp->point[temp->left]));
              return;
              }
     //de qui ben trai , gan lai
    // left =0; right = mid;
    temp->left = tempLeft;
    temp->right =mid;
    closest_pair(temp);
    dL = pop();
    //de qui ben phai, gan lai left = mid, right = N-1
    temp->left = mid;
    temp ->right = tempRight;
    closest_pair(temp);
    dR = pop();
    delta = min(dL,dR);
    //lay ra nhung phan tu nam trong khoang delta ben trai
    for(i=tempLeft;i<mid;i++) {
                              if(fabs(temp->point[i].x - midX) <=delta) {
                                                      tempL[countL] = temp->point[i];
                                                      countL ++;
                                                      }
                              }
    // Lay ra nhung phan tu nam trong khoang delta ben phai 
    for(i=mid;i<tempRight;i++) {
                               if(fabs(temp->point[i].x - midX) <=delta) {
                                                       tempR[countR] = temp->point[i];
                                                       countR ++;
                                                       }
                               }
    // Sap xep nhung phan tu trong khoang toa do Y
    sortY(tempL,countL);
    sortY(tempR,countR);
    temp1=delta;
    //kiem tra xem trong khoang delta co ton tai cap diem nao co khoang cach nho hon delta hay khong
     for(i=0;i<countL;i++) {
                           j=0;
                           while((j<countR) &&(fabs(tempR[j].y - tempL[i].y) <=2*delta)) {
                                            j++;
                                            temp1 = min(temp1,distance(tempL[i],tempR[j]));
                                            }
                           }
     delta = min(temp1,delta);
     push(delta);
     return;
     }

int main() {
        float result;
        struct thamso temp;
        struct coordinate doc;
        temp.left =0;
        temp.right = N-1;
        struct coordinate point[N];
        input(&temp.point[N]);
        sortX(temp.point,N);
        closest_pair(&temp);
        result = pop();
        printf("Khoang cach ngan nhat la: %2.2f\n",result);
        getch();
        return 0;
        }
