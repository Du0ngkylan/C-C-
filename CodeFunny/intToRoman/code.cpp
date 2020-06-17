//================================================
// Chuyển số nguyên sang số la mã
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
//================================================
#include <iostream>
#include <vector>
#include <map>

using namespace std;

string intToRoman(int num) {
  std::map<int, string> map = { {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
                                {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
                                {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} };
  string ret;
  for (auto iter = map.rbegin(); iter != map.rend(); ++iter) {
    while (num >= iter->first) {
      ret += map[iter->first];
      num -= iter->first;
    }
  }
  return ret;
}

int main() {

  auto result = intToRoman(12); // =====> "XII"

  return 0;
}
