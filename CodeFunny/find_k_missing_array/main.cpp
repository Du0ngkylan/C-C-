#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> input = { 1, 1, 2, 3, 5, 5, 7, 9, 9, 9 };
	vector<int> reg(input.size(), 0);
	for (auto it : input) {
		reg[it] = 1;
	}

	// now, let's print all the absentees
	cout << "missing numbers in given array" << endl;
	for (int i = 1; i < reg.size(); i++) {
		if (reg[i] == 0) {
			cout << i << endl; 
		} 
	}

	cout << "end =====================>" << endl;
  return 0;
}

// Output
// missing numbers in given array
// 4
// 6
// 8
