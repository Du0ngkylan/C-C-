#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
// Viết bằng chuỗi ký tự của C
//void reverse(char *s) {
//        int len = strlen(s), i, j = 0;
//        char *move, *tmp = new char[len + 1];
//        //Con trỏ tmp sẽ cố định để không xảy ra memory leak
//        move = tmp;
//        for (i = len - 1; i > -1; --i) {
//                if (s[i] == ' ') {
//                        for (j = i + 1; j < len && s[j]; ++j)
//                                *move++ = s[j];
//                        *move++ = s[i];
//                        s[i] = 0;
//                }
//        }
//        j = 0;
//        while (*move++ = s[j++]);
//        for (i = 0; i <= len; ++i) s[i] = tmp[i];
//}
// 
//string s = "Toi la Lap   Trinh Vien C/C++  ^^";
void DaoChuoi(string& s)
{
	string mangchuoi[20];
	int n = 0;
	for(int i = 0; i < s.length(); i++)
	{
		int start = i;
		while(s[i] != ' ' && s[i] != NULL)
		{
			i++;
		}
		int finish = i;
		mangchuoi[n] = s.substr(start, finish - start);
		n++;
	}
	// Thực hiện đảo các từ
	for(int i = 0; i < n / 2; i++)
	{
		string temp = mangchuoi[i];
		mangchuoi[i] = mangchuoi[n - 1 - i];
		mangchuoi[n - 1 - i] = temp;
	}
	s = "";
	for(int i = 0; i < n; i++)
	{
		s = s + mangchuoi[i];
		s = s + " ";
	}
}
int main(void) {
    /*    char original[] = "Day la bai giai su dung thu vien stdio.h :v";
        reverse(original);
        printf("%s\n", original);*/
	string s = "Toi la Lap   Trinh Vien C/C++  ^^";
	DaoChuoi(s);
	cout<<endl<<s;
	system("pause");
        return 0;
}