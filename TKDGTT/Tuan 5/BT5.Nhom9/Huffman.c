#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAXSIZE 511

typedef struct HuffTree
{
	unsigned char c;
	long w;
	int left;
	int right;
}HuffTree;

typedef struct HuffTable
{
	unsigned char c;
	char code[256];
	int codeLength;
}HuffTable;

HuffTree HuffNode[MAXSIZE];
HuffTable table[256];
int first = 0, last = 0;	// chi so dau va cuoi cua cay
int iTable = -1;	// Chi so cua bang
int bitThua;


void readFile(char *);
void quickSort(int , int );
void createTree();

/* Tao bang ma hoa */
void createTable(int pos, unsigned char c, char code[], int length)
{
	if (c != ' ')
	{
		code[length] = c;
		code[length+1] = '\0';
	}
	if (HuffNode[pos].left == -1 && HuffNode[pos].right == -1)
	{
		iTable++;
		table[iTable].c = HuffNode[pos].c;
		strcpy(table[iTable].code, code);
		table[iTable].codeLength = length+1;
	}
	else
	{
		createTable(HuffNode[pos].left, '0', code, length+1);
		createTable(HuffNode[pos].right, '1', code, length+1);
	}
}

/* Tao mang chua thong tin cua cac ki tu */
void makeNode()
{
	int i;
	for (i = 0; i <= 255; i++)
	{
		HuffNode[i].c = i;
		HuffNode[i].left = -1;
		HuffNode[i].right = -1;
		HuffNode[i].w = 0;
	}
}

/* Tim kiem ban ma hoa cua ki tu */
void Search(unsigned char c, char a[])
{
	/*int i;
	for (i = 0; i <= iTable; i++)
		if (table[i].c == c)
		{
			strcpy(a, table[i].code);
			break;
		}*/
	int i = 0, f = 0;
    while (f==0)
    {
		if(table[i].c == c)
			f = 1;
        else
			i++;
	}
	if(f == 1)
		strcpy(a, table[i].code);
}


/* Doc tep */
void readFile(char *fname)
{
	FILE *f;
	unsigned char c;
	int i, j;
	char code[8];
	makeNode();
	f = fopen(fname, "rb");
    while (fread(&c, sizeof(char), 1, f), !feof(f))
    {
		HuffNode[c].w++;
    }
    fclose(f);
	quickSort(0, 255);
	i = 0;
	while (HuffNode[i].w == 0)
		i++;
	for (j = 0; j <= 255-i; j++)
		HuffNode[j] = HuffNode[j+i];
	last = 255-i;
	createTree();
	createTable(first, ' ', code, -1);
}


void catChuoi(char source[], int count, char preDes[], char lastDes[])
{
	int i, j;
	for (i = 0; i < count; i++)
		preDes[i] = source[i];
	preDes[i] = '\0';
	for (j = count; j < (int)strlen(source); j++)
		lastDes[j-count] = source[j];
	lastDes[j-count] = '\0';
}


void CharToBinary(unsigned char w, char s[])
{
	int i, x = w;
	s[8] = '\0';
	for (i = 7; i >= 0; i--)
	{
		s[i] = '0' + (x%2);
		x = x/2;
	}
}


unsigned char BinaryToChar(char w[])
{
	int i, x = 0;
	for (i = strlen(w)-1; i >= 0; i--)
		if (w[i] == '1')
		{
			x = x + (1 << (7-i));
		}
	return x;
}


void writeFile(char *fileIn, char *fileOut)
{
	FILE *fIn, *fOut;
	int i;
	unsigned char c, write, cEnd	/*ki tu thua*/;
	char x[256], sCode[256], forWrite[256];
	x[0] = '\0';

	fIn = fopen(fileIn, "rb");
	if (!fIn)
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	fOut = fopen(fileOut, "wb");
	/* Ghi bang ma */
	cEnd = ' ';
	fwrite(&cEnd, sizeof(char), 1, fOut);
	fwrite(&bitThua, sizeof(int), 1, fOut);
	fwrite(&last, sizeof(int), 1, fOut);
	for (i = 0; i <= last; i++)
		fwrite(&HuffNode[i], sizeof(HuffTree), 1, fOut);

	while (fread(&c, sizeof(char), 1, fIn), !feof(fIn))
	{
		Search(c, sCode);
		if (strlen(x) == 0)
		{
			strcpy(x, sCode);
		}
		else
			strcat(x, sCode);
		while (strlen(x) >= 8)
		{
			catChuoi(x, 8, forWrite, x);
			write = BinaryToChar(forWrite);
			fwrite(&write, sizeof(char), 1, fOut);
		}
	}
	/*while (strlen(x) >= 8)
	{
		catChuoi(x, 8, forWrite, x);
		write = BinaryToChar(forWrite);
		fwrite(&write, sizeof(char), 1, fOut);
	}*/

	fclose(fIn);
	fclose(fOut);

	bitThua = strlen(x);
	for (i = bitThua; i < 8; i++)
		x[i] = '0';
	x[i] = '\0'; 
	cEnd = BinaryToChar(x);

	fOut = fopen(fileOut, "r+b");
	fwrite(&cEnd, sizeof(char), 1, fOut);
	fwrite(&bitThua, sizeof(int), 1, fOut);
	fclose(fOut);
}


void UnHuff(char *fileIn, char *fileOut)
{
	FILE *fIn, *fOut;
	unsigned char c, write, kt;
	char code[9], x[10];
	int i, bitDu, size, s;
	HuffTree tree[MAXSIZE], node;
	x[0] = '\0';
	fIn = fopen(fileIn, "rb");
	if (!fIn)
	{
		printf("\nLoi mo file");
		getch();
		exit(0);
	}
	fOut = fopen(fileOut, "wb");
	fread(&kt, sizeof(char), 1, fIn);
	fread(&bitDu, sizeof(int), 1, fIn);
	fread(&size, sizeof(int), 1, fIn);
	s = size;
	for (i = 0; i <= size; i++)
	{
		fread(&node, sizeof(HuffTree), 1, fIn);
		tree[i] = node;
	}
	while (fread(&c, sizeof(char), 1, fIn), !feof(fIn))
	{
		CharToBinary(c, code);
		strcpy(x, code);
		i = 0;
		while (i < (int)strlen(x))
		{
			//if (i < (int)strlen(x))
				if (x[i] == '0')
					s = tree[s].left;
				else
					s = tree[s].right;
			if (tree[s].left == -1 && tree[s].right == -1)
			{
				write = tree[s].c;
				s = size;
				fwrite(&write, sizeof(char), 1, fOut);
			}
			i++;
		}
	}
	CharToBinary(kt, code);
	i = 0;
	while (i < bitDu)
	{
		if (code[i] == '0')
			s = tree[s].left;
		else
			s = tree[s].right;
		if (tree[s].left == -1 && tree[s].right == -1)
			{
				write = tree[s].c;
				s = size;
				fwrite(&write, sizeof(char), 1, fOut);
			}
		i++;
	}
	fclose(fOut);
	fclose(fIn);
}


/* Tao cay ki tu */
void createTree()
{
	while (first < last)
	{
		quickSort(first, last);
		HuffNode[last+1].left = first;
		HuffNode[last+1].right = first+1;
		HuffNode[last+1].w = HuffNode[first].w + HuffNode[first+1].w;
		first += 2;
		last++;
	}
}

/* Sap xep cac ki tu theo thu tu tang dan tan so xuat hien */
void quickSort(int left, int right)
{
	int i, j;
	long x;
	HuffTree temp;
	i = left;		
	j = right;
	x = (HuffNode[i].w + HuffNode[j].w)/2;
	do {
		while (HuffNode[i].w < x)
			i++;
		while (HuffNode[j].w > x)
			j--;
		if (i <= j)
		{
			temp = HuffNode[i];
			HuffNode[i] = HuffNode[j];
			HuffNode[j] = temp;
			i++;
			j--;
		}
	} while (i < j);
	if (i < right)
		quickSort(i, right);
	if (j > left)
		quickSort(left, j);
}


void main()
{
	char s[200], w[200];
	int c;
	printf("\n1. Nen");
	printf("\n2. Giai nen");
	printf("\n3. Thoat");
	printf("\nChon hinh thuc: ");	scanf("%d", &c);
	if (c == 1)
	{
		printf("\nNhap duong dan den file can ma hoa:\n");
		fflush(stdin);
		gets(s);
		printf("\nNhap duong dan luu file da ma hoa:\n");
		fflush(stdin);
		gets(w);
		readFile(s);
		writeFile(s, w);
		printf("\nDone");
	}
	else if (c == 2)
	{
		printf("\nNhap duong dan den file can giai nen:\n");
		fflush(stdin);
		gets(s);
		printf("\nNhap duong dan luu file giai nen:\n");
		fflush(stdin);
		gets(w);
		UnHuff(s, w);
		printf("\nDone");
	}
	else if (c == 3)
		exit(0);
	else
		printf("\nChon sai");
	getch();
}