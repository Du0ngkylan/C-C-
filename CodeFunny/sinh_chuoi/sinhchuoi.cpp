/******************************************************************************

sinh hoán vị chuỗi
ví dụ : bui => [bui Bui bUi BUi buI BuI bUI BUI]

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<string> result;
  string origin = "bui";

  for (int i = 0; i < (1 << origin.length()); i++) {
    string strTemp = "";
    for (int j = 0; j < origin.length(); j++) {
      string str = "";
      str.assign(1, (i & (1 << j)) ? toupper(origin[j]) : origin[j]);
      strTemp.append(str);
    }
    result.push_back(strTemp);
  }

  for (auto str: result) {
    cout << str << endl;
  }

  return 0;
}
