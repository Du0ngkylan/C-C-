#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void DoiThuongThanhHoa(string& s)
{
	for (int i = 0 ; s[i] != NULL; i++ )
			if (((s[i] >= 'a') && ( s[i] <= 'z'))  || (s[i] >= 130 && s[i] <= 165))
				s[i] -= 32 ; 
}

int main()
{
	
	ifstream Infile;
	string Filename;
	cout<<"Nhap file muon doc:\n";
	getline(cin, Filename);
	Infile.open(Filename,ios::in);

	if(Infile.is_open() == false)
	{
		cout<<"Ko the mo tap tin de doc!";
		cin.get();
		return 0;
	}
	int dem = 0 ; 
	string Sum = "";
	string s ;
	while(getline(Infile,s))
	{
		DoiThuongThanhHoa(s);
		Sum += s;
		Sum += "\n";
	}
	cout<<Sum;
	Infile.close();
	ofstream Outfile;
	string FileName2;
	cout<<"Nhap noi muon xuat ket qua:\n";
	getline(cin, FileName2);
	Outfile.open(FileName2, ios::out);
	Outfile<<Sum;
	Outfile.close();
	system("pause");
	return 0;
}
