#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
//Tim cap diem gan nhat tren mat phang

//struct luu toa do (x,y) cua diem
int N;
struct coordinate {
       float x;
       float y;
       } coordinate;
       
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
//ham truyen gia tri cho doi
void input(struct coordinate point[]) {
     FILE *fp;
     int i=0;
     char s[20];
     printf("Cac cap diem la:\n\n");
     fp = fopen("input.txt","r");
     if(fp==NULL)  printf("Can not open file.\n");
     while(fgets(s,80,fp) !=NULL) {
                          sscanf(s,"%f%f",&point[i].x,&point[i].y);
                          printf("%f,%f\n",point[i].x , point[i].y);
                          i++;
                          }
     }
int main() {
    int i,j;
    float result,temp;
    struct coordinate point[N],point2[2];
    input(point);
    result = distance(point[0],point[1]);
    point2[0]=point[0];
    point2[1] = point[1];
    for(i=0;i<2;i++)
    for(j=i+1;j<2;j++) {
                       temp = distance(point[i],point[j]);
                       if(temp < result) {
                               point2[0] = point[i];
                               point2[1] = point[j];
                               result = temp;
                               }
                       }
    printf("\nKhoang cach gan nhat la: %2.2f\n",result);
    printf("\ncap diem la: (%2.2f , %2.2f) va (%2.2f , %2.2f)",point2[0].x,point2[0].y,point2[1].x,point2[1].y);
    getch();
    return 0;
    }
