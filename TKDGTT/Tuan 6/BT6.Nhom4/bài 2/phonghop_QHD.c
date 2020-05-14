//Bai toan bo tri phong hop
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[100],b[100],l[100],n;
void sapxep()
{
     int i,j;
     for(i=1;i<n;i++){
                      for(j=i+1;j<=n;j++){
                                          if(b[i]>b[j]){
                                                        a[i]=a[i]+a[j];
                                                        b[i]=b[i]+b[j];
                                                        a[j]=a[i]-a[j];
                                                        b[j]=b[i]-b[j];
                                                        a[i]=a[i]-a[j];
                                                        b[i]=b[i]-b[j];
                                                        }
                                          }
                      }
}
void lapbang()
{
     int i,j;
     for(i=1;i<=n;i++) l[i]=1;
     for(i=2;i<=n;i++) for(j=i-1;j>0;j--) if(a[i]>=b[j]&&l[i]<l[j]+1) l[i]=l[j]+1;
     printf("\nBang phuong an: \n");
     for(i=1;i<=n;i++) printf("%d\t",l[i]);
}
void truyvet()
{
     int toiuu=1,i,j,lanmo,truoc;
     for(i=1;i<=n;i++) if(toiuu<l[i]) toiuu=l[i];
     printf("\nCo the bo tri duoc %d cuoc hop la toi da\n",toiuu);
     for(i=1;i<=n;i++){
                       if(l[i]==toiuu){
                                       printf("S\tE\n");
                                       lanmo=toiuu;
                                       for(j=i;j>0;j--){
                                                        if(lanmo==toiuu||(l[j]==lanmo&&b[j]<=a[truoc])){
                                                                        printf("%d\t%d\n",a[j],b[j]);
                                                                        truoc=j;
                                                                        lanmo--;
                                                                        }
                                                        }
                                       }
                       }
}
int main()
{
    int i,j;
    printf("Nhap so cuoc hop can phong hop: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
                      printf("Nhap thoi gian bat dau va ket thuc cua cuoc hop thu %d\n",i);
                      scanf("%d%d",&a[i],&b[i]);
                      }
    sapxep();
    lapbang();
    truyvet();
    getch();
    return 0;
}
                                       
                                       
