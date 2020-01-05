#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
using namespace std;
const int n = 18;  // Số cột
const int m = 18;
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}


void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void KhoiTao(char a[][n])
{
	   for(int i = 0; i < m; i++)
	{
	   for(int j = 0; j < n; j++)
	   {
		   a[i][j] = '.';
	   }
	}
}
void XuatMang(char a[][n])
{
	for(int i = 0; i < m * n; i++)
	{
		   if(a[i / n][i % n] == 'X')
		   {
			   textcolor(12);
		   }
		   else if(a[i / n][i % n] == 'O')
		   {
			   textcolor(14);
		   }
		   else 
			   textcolor(15);
		   		     cout<<a[i/ n][i % n]<<"   ";
	if((i + 1) % n == 0)
	   cout<<endl<<endl;
	}
}
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
bool CheckRowsandColum(char a[][n], int r, int c)
{
	int dem, j;
	dem = 0;            // Mục đích để đểm số ô liên tiếp

	for(int i = c; i < n; i++)              // Kiểm tra hàng ngang
	{
		if(a[r][i] != a[r][c])
		{
				for(j = i - 1; j >= 0; j--)
				{
					if(a[r][j] == a[r][c])
						dem++;
					else
						break;
				}
				break;
		}
	}
	if(dem  == 5)		
			return true;
	dem = 0;
	for(int i = c; i >= 0; i--)
	{
		if(a[r][i] != a[r][c])
		{
			for(int j = i + 1; j < n; j++)
			{
				if(a[r][j] == a[r][c])
					dem++;
				else
					break;
			}
			break;
		}
	}	
	if(dem  == 5)		
			return true;

	dem = 0;
	for(int j = r; j >= 0; j--)
	{
		if(a[j][c] != a[r][c])
		{
			for(int i = j + 1; i < m; i++)
			{
				if(a[i][c] == a[r][c])
					dem++;
				else
					break;
			}
			break;
		}
		
	}
	if(dem  == 5)
			return true;
	dem = 0;
	for(int j = r; j < m; j++)
	{
		if(a[j][c] != a[r][c])
		{
			for(int i = j - 1; i >= 0; i--)
			{
				if(a[i][c] == a[r][c])
					dem++;
				else
					break;
			}
			break;
		}
	}
	if(dem  == 5)
			return true;
	return false;
}

bool Checkdiagonal(char a[][n], int r, int c)
{
	int dem;
	dem = 0;

	int rowtemp = r;
	int columtemp = c;
	while( rowtemp  >= 0 && columtemp>= 0)             //  Kiểm tra Chéo lên trên và về bên trái
	{
			if(a[rowtemp][columtemp] != a[r][c])
			{
				rowtemp ++;
				columtemp ++;
				while(rowtemp < m && columtemp < n)
				{
					if(a[rowtemp][columtemp] == a[r][c])
						dem++;
					else
						break;
					rowtemp ++;
					columtemp++;
				}
				break;
			}
				
			rowtemp --;
			columtemp --;
	}
	if(dem  == 5)
				return true;
	dem = 0;
	rowtemp = r;
	columtemp = c;
	while( rowtemp  >= 0 && columtemp < n)  // Xét chéo lên bên phải
	{
			if(a[rowtemp][columtemp] != a[r][c])			
			{
				rowtemp ++;
				columtemp --;
				while(rowtemp < m && columtemp >= 0)
				{
					if(a[rowtemp][columtemp] == a[r][c])
						dem++;
					else
						break;
					rowtemp++;
					columtemp --;
				}
				break;
			}
			rowtemp --;
			columtemp ++;
	}
	if(dem  == 5)
				return true;
	dem = 0;
	rowtemp = r;
	columtemp = c;
	while( rowtemp  < m && columtemp < n)           // Xét xuống dưới về bên phải
	{
		if(a[rowtemp][columtemp] != a[r][c])
		{
			rowtemp --;
			columtemp --;
			while(rowtemp >= 0 && columtemp >= 0)
			{
				if(a[rowtemp][columtemp] == a[r][c])
					dem++;
				else
					break;
				rowtemp --;
				columtemp --;
			}
			break;
		}		
		rowtemp ++;
		columtemp ++;
	}
	if(dem  == 5)
				return true;

	dem = 0;
	rowtemp = r;
	columtemp = c;
	while( rowtemp  < m && columtemp >= 0)            // Xét đường chéo duới về bên trái
	{
		if(a[rowtemp][columtemp] != a[r][c])
		{
			rowtemp --;
			columtemp ++;
			while(rowtemp >= 0 && columtemp < n)
			{
				if(a[rowtemp][columtemp] == a[r][c])
					dem++;
				else 
					break;
				rowtemp --;
				columtemp ++;
			}
			break;
		}	
		rowtemp ++;
		columtemp --;
	}
	if(dem  == 5)
				return true;
	return false;
	
}

void Randomcaunoi()
{
	int caunoi;
				srand(time(0));
				caunoi = rand()%5 + 1;
				switch(caunoi)
				{
				case 1:cout<<endl<<"BAN THAT LA HAY DO ^~^";break;
				case 2:cout<<endl<<"DUONG DI VUA ROI DA GIUP BAN CHIEN THANG THAT NHANH ^_<. 1 CU DANH HOAN HAO";break;
				case 3:cout<<endl<<"CU DANH RAT HIEM. BAN DA CHIEN THANG ^_^";break;
				case 4:cout<<endl<<"BAN THONG MINH LAM ^^";break;
				case 5:cout<<endl<<"KHONG CON GI HON LA CHIEN THANG 1 DOI THU NANG KY. VERY GOOD!";break;
				}
}
void PlayGamePlayerAndPlayer(char a[][n])
{
	char chon;            // Chính là con nháy khi nhấn mũi tên
	bool check = true; // Biến để phân biệt lượt chơi
	int i = 0, j = 0;       // vị trí đầu là [0][0] .
	int dem = 0;          // dem để sét xem người chơi nào đó đã tạo được 5 ô liên tiếp chưa
	do 
	{
		fflush(stdin);        // Xóa bộ nhớ đệm
		chon = _getch();   // Bắt key bàn phím
		if(chon == 72)            // Khi người dùng nhấn nút mũi tên lên
		{
			if(a[i][j] != 'X' && a[i][j] != 'O')      // Cho ô đi qua nhưng ko đánh và cho nó về giá trị cũ . 
			{
				   a[i][j] = '.';  
				   gotoxy((j * 4) + 1, (i * 2) + 1);
				   textcolor(15);
				   cout<<".";
			}
			int k = i;                      // Gán i qua biến k để canh 
			i--;
			while(a[i][j] == 'X' || a[i][j] == 'O')       // Để có thể cho nháy xuyên qua  những ô đã đánh
			{
				i--;
				if(i == -1)
					break;
			}
			if(i == -1)
			{
					i = k;
			}
			if(a[i][j] ==  'X' || a[i][j] == 'O')     
				continue;
		    
			a[i][j] = 'S';                     // Ký tự biểu hiện ô đang đứng nhưng chưa đánh.S viết tắt từ Start
			gotoxy((j * 4) + 1, (i * 2) + 1);
			 textcolor(15);
			cout<<"S";
		}
		else if(chon == 80)                    // Khi người dùng nhấn phím mũi tên xuống
		{
			if(a[i][j] != 'X' && a[i][j] != 'O')
			{
				   a[i][j] = '.';  
				   gotoxy((j * 4) + 1, (i * 2) + 1);
				    textcolor(15);
				   cout<<".";
			}
			int k = i;
			i++;
			while(a[i][j] == 'X' || a[i][j] == 'O')
			{
				i++;
				if(i == m)
				{
					break;
				}
			}
			if(i == m)
				i = k;
			if(a[i][j] ==  'X' || a[i][j] == 'O')     
				continue;
			a[i][j] = 'S';
			gotoxy((j * 4) + 1, (i * 2) + 1);
			 textcolor(15);
			cout<<"S";
		}
		else if(chon == 75)                 // Khi người dùng nhấn phím mũi tên trái
		{
			if(a[i][j] != 'X' && a[i][j] != 'O')
			{
				   a[i][j] = '.';  
				   gotoxy((j * 4) + 1, (i * 2) + 1);
				   cout<<".";
			}
			int k = j;
			j--;
			while(a[i][j] == 'X' || a[i][j] == 'O')
			{
				j--;
				if(j == -1)
				{
					break;
				}
			}
			if(j == -1)
				j = k;
			if(a[i][j] ==  'X' || a[i][j] == 'O')     
				continue;
			a[i][j] = 'S';
			gotoxy((j * 4) + 1, (i * 2) + 1);
			 textcolor(15);
			cout<<"S";
		}
		else if(chon == 77)                              // Khi người dùng nhấn phím mũi tên phải
		{
			if(a[i][j] != 'X' && a[i][j] != 'O')
			{
				   a[i][j] = '.';  
				   gotoxy((j * 4) + 1, (i * 2) + 1);
				   textcolor(15);
				   cout<<".";
				   
			}
			int k = j;
			j++;
			while(a[i][j] == 'X' || a[i][j] == 'O')
			{
				j++;
				if(j == n)
				{
					break;
				}
			}
			if(j == n)
				j = k;
			if(a[i][j] ==  'X' || a[i][j] == 'O')     
				continue;
			a[i][j] = 'S';
			gotoxy((j * 4) + 1, (i * 2) + 1);
			textcolor(15);
			cout<<"S";
			
		}
		else if(chon == 13)          // Khi người chơi nhấn Enter để đánh
		{
			if(check == true)       // X đi trước
			{
				if(a[i][j] == 'O' || a[i][j] == 'X')      // Phát hiện đánh vào ô đã có người đi lượt trước
				{
					cout<<"Da co nguoi danh o nay!"; // Báo lỗi
					continue;            // Tiếp tục lần lặp khác
				}
				a[i][j] = 'X';
				gotoxy((j * 4) + 1, (i * 2) + 1);
				textcolor(12);
				cout<<"X";
				if(CheckRowsandColum(a, i, j)|| Checkdiagonal(a, i, j))
			   {		
				   XoaManHinh();
				   XuatMang(a);
				cout<<endl<<"X win";
				Randomcaunoi();
				break;
			   }
				check = false;
				dem++;
			}
			else 
			{
				if(a[i][j] == 'O' || a[i][j] == 'X')      // Phát hiện đánh vào ô đã có người đi lượt trước
				{
					cout<<"Da co nguoi danh o nay!"; // Báo lỗi
					continue;            // Tiếp tục lần lặp khác
				}
				a[i][j] = 'O';
				gotoxy((j * 4) + 1, (i * 2) + 1);
				textcolor(14);
				cout<<"O";
				if(CheckRowsandColum(a, i, j)|| Checkdiagonal(a, i, j))
			   {		
				   XoaManHinh();
				   XuatMang(a);
				cout<<endl<<"O win";
				Randomcaunoi();
				break;
			   }
				check = true;
				dem++;
			}
		}
		if(dem == 324)
			KhoiTao(a);
	}while(chon != 27);        // khi người người dùng chưa nhấn phím 'ESC'
}
void main()
{
	resizeConsole(900, 500);
	int chonmenu;
	char a[m][n];
	do 
	{
		system("cls");
		textcolor(14);
		cout<<"======================> GAME CARO IN CONSOLE BY TUAN NGUYEN <===================\n\n";
		textcolor(15);
		cout<<"1.Choi Game\n\n";
		cout<<"2.Thoat\n\n";
		cout<<"Moi ban chon:\n";
		cin>>chonmenu;
		switch (chonmenu)
		{
		case 1:
			{
				    system("cls");
					KhoiTao(a);
	                XuatMang(a);
	                PlayGamePlayerAndPlayer(a);
					_getch();
					break;
			}
		case 2:break;
		default:
			cout<<"Ban chon menu sai.!";
			_getch();
			break;
		}
	}while(chonmenu != 2);
}