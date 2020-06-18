#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>

typedef std::map<std::string, int> document;

// Return a dictionary mapping words to frequency
document CountWords(std::ifstream &fin) {
	document result;
	std::string str;

	while (fin >> str) {
		++result[str];
	}
	return result;
}

// Inner product between two vectors
int InnerProduct(document d1, document d2) {
	int sum = 0;
	for (auto w : d1) {
		if (d2.find(w.first) != d2.end()) {
			sum += w.second * d2[w.first];
		}
	}
	return sum;
}

// Return the angle between these two vectors
double VectorAngle(document d1, document d2) {
	int numerator = InnerProduct(d1, d2);
	double denominator = sqrt(InnerProduct(d1, d1) * InnerProduct(d2, d2));
	return acos(numerator / denominator);
}

int main(int argc, char **argv) {
	if (argc != 3) {
		std::cout << "Usage: ccdist path_to_first_doc path_to_second_doc" << std::endl;
		return 1;
	}

	std::string path_to_first_doc = argv[1];
	std::string path_to_second_doc = argv[2];

	std::ifstream fin_first_doc, fin_second_doc;
	fin_first_doc.open(path_to_first_doc);
	fin_second_doc.open(path_to_second_doc);

	if (!fin_first_doc || !fin_second_doc) {
		std::cout << "Error opening or reading input file" << std::endl;
		return 1;
	}

	document d1 = CountWords(fin_first_doc);
	document d2 = CountWords(fin_second_doc);

	if (0 == d1.size() || 0 == d2.size()) {
		std::cout << "Error document empty" << std::endl;
		return 1;
	}
	auto distance = VectorAngle(d1, d2);
	std::cout << "The distance between the documents is = " << distance << " radians" << std::endl;

	return 0;
}