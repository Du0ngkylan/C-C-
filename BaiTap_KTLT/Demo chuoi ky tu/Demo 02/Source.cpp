#include <stdio.h>
#include <conio.h>

int Length(char* s)
{
	int dem = 0;
	for(int i = 0; s[i] != NULL; i++)
	{
		dem++;
	}
	return dem;
}
//   s1 = "ABC"     s2 = "CD"
// i = 0; i < 2; i++
// s1[i] = s2[i]  <=> s1[0] = 'C'
// s1[1] = 'D'


void StringCopy(char* s1, char* s2)
{
	int i;
	for(i = 0; i < Length(s2); i++)
	{
		s1[i] = s2[i];
	}

	// i = Length
	s1[i] = NULL;
}
void StringLower(char* s)
{
	int  i;
	for(i = 0; i < Length(s); i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] += 32;
		}
	}
}
void StringUpper(char* s)
{
	int  i;
	for(i = 0; i < Length(s); i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
	}
}

void XoaKyTu(char* s,int vitrixoa)
{
	for(int i = vitrixoa; i < Length(s) - 1; i++)
	{
		s[i] = s[i+1];
	}
	s[Length(s) - 1] = NULL;
}

void ChuanHoa(char* s)
{
	for(int i = 0; i < Length(s) - 1; i++)
	{
		if(s[i] == ' ' && s[i+1] == ' ')
		{
			XoaKyTu(s, i);
			i--;
		}
	}
	if(s[0] == ' ')
	{
		XoaKyTu(s, 0);
	}
	if(s[Length(s) - 1] == ' ')
	{
		XoaKyTu(s, Length(s) - 1);
	}

}
void main()
{
	char s[50];
	printf("Nhap chuoi s:\n");
	fflush(stdin);
	gets(s);
	StringLower(s);
	ChuanHoa(s);
	puts(s);
	getch();
}