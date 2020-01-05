#include <iostream>
using namespace std;
#include <string>
#include <fstream>

string X,Y;
int F[1000][1000];

void ReadFile()
{
  ifstream fi("str.inp");
  fi>>X;
  fi.ignore();
  fi>>Y;
  fi.close();
}

int Min3(int a, int b,int c)
{
  int min=a;
  if (b<min) min=b;
  if (c<min) min=c;
  return min;
}

void Optimize()
{
  int Lx=X.length();
  int Ly=Y.length();
  int i,j;
  for (i=0;i<Lx;i++) F[i][0]=i;
  for (j=0;j<Ly;j++) F[0][j]=j;

  for (i=1;i<=Lx;i++)
    for (j=1;j<=Ly;j++)
      if (X[i-1]==Y[j-1])
        F[i][j]=F[i-1][j-1];
      else
        F[i][j]=Min3(F[i][j-1],F[i-1][j-1],F[i-1][j])+1;
}

void Trace()
{
  int Lx=X.length();
  int Ly=Y.length();
  ofstream fo("str.out");
  fo<<F[Lx][Ly]<<endl;
  while (Lx>0 || Ly>0)
  {
    if (X[Lx-1] == Y[Ly-1])
    {
      Lx--;
      Ly--;
    }
    else
    {
      fo<<X<<" -> ";
      if (Ly>0 && F[Lx][Ly]-1==F[Lx][Ly-1])
      {
        fo<<"Insert("<<Lx<<","<<(char)Y[Ly-1]<<")";
        X.insert(Lx,Y.substr(Ly-1,1));
        Ly--;
      }
      else if (Lx>0 && F[Lx][Ly]-1==F[Lx-1][Ly])
      {
        fo<<"Delete("<<Lx<<")";
        X.erase(Lx-1,1);
        Lx--;
      }
      else
      {
        fo<<"Replace("<<Lx<<","<<(char)Y[Ly-1]<<")";
        X[Lx-1]=Y[Ly-1];
        Lx--;
        Ly--;
      }
      fo<<" -> "<<X<<endl;
    }
  }
  fo.close();

}

int main()
{
  ReadFile();
  Optimize();
  Trace();
  return 0;
}
