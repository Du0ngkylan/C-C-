#include <stdio.h>
#include <conio.h>
#include <string>
void main()
{
	//char HoTen[50];
	//gets(HoTen);
	//printf("hoten = %s\n",HoTen);
	//fflush(stdin);
	//int len = strlen(HoTen);  // Hàm string len trả về độ dài của chuỗi
	//printf("Ho ten co %d ky tu\n",len);
	//char HoTen2[50];
	//strcpy(HoTen2, HoTen); // Gán chuỗi
	//strlwr(HoTen2);         // Hàm string lower đổi chuỗi sang dạng in thường
	//printf("\n%s",HoTen2);
	//strupr(HoTen2);         // Hàm string upper đổi chuỗi sang dạng in hoa
	//printf("\n%s",HoTen2);
	//strrev(HoTen2);          // Hàm đảo ngược chuỗi
	//printf("\n%s",HoTen2);
	if(strcmpi("Nguyen Ai Tuan","nguyen ai tuan") == 1)  // Hàm string compare 
		printf("str1 > str2");
	else if (strcmpi("Nguyen Ai Tuan","nguyen ai tuan") == -1)
		printf("str1 < str2");
	else 
		printf("str1 == str2");

	//char s1[50],s2[20];
	//gets(s1);
	//fflush(stdin);
	//gets(s2);
	//strcat(s1,s2);     // Hàm nối chuỗi từ s2 vào sau s1

	//printf("\n%s",s1);

	//strcpy(s1,strstr(s1,"Ai")); 
	getch();
}