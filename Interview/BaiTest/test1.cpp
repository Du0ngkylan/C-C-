#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;


string const g_source = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz1234567890";
string const g_destination = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";


bool containsKey(unordered_map<string, int> const &wordMap, string const &key)
{
	return wordMap.find(key) != wordMap.end();
}


template <typename ForwardIterator>
unordered_map<char, char> translationTable(
	ForwardIterator first,
	ForwardIterator last,
	ForwardIterator dFirst)
{
	unordered_map<char, char> table;

	for (; first != last; ++first, ++dFirst) {
		table[*dFirst] = *first;
	}

	return table;
}


void formatToken(string &rawString)
{
	static unordered_map<char, char> charTranslationTable = translationTable(
		g_source.begin(),
		g_source.end(),
		g_destination.begin());

	transform(
		rawString.begin(),
		rawString.end(),
		rawString.begin(),
		[](char c) { char ret = charTranslationTable[c]; return ret ? ret : ' '; });
}


unordered_map<string, int> wordOccurences(ifstream &is)
{
	unordered_map<string, int> result;
	string inputString{ istreambuf_iterator<char>(is), istreambuf_iterator<char>() };
	formatToken(inputString);

	istringstream stream(inputString);
	string token;

	while (stream) {
		stream >> token;
		result[token] += 1;
	}

	return result;
}


double documentMagnitude(unordered_map<string, int> const &document)
{
	double magnitude = 0.0;

	for (auto const &word : document) {
		magnitude += double(word.second * word.second);
	}

	//return sqrt(magnitude);
	return magnitude;
}


int main(int argc, char *argv[])
{
	//string filename1 = argv[1];
	//string filename2 = argv[2];

	//ifstream file1(filename1);
	//ifstream file2(filename2);

	ifstream file1("file1.txt");
	ifstream file2("file2.txt");

	unordered_map<string, int> document1 = wordOccurences(file1);
	unordered_map<string, int> document2 = wordOccurences(file2);

	double magnitude1 = documentMagnitude(document1);
	double magnitude2 = documentMagnitude(document2);

	double innerProduct = 0.0;

	for (auto const &word : document2) {
		if (containsKey(document1, word.first)) {
			innerProduct += double(word.second * document1[word.first]);
		}
	}

	double cosAngle = innerProduct / magnitude1 / magnitude2;

	cout << "Distance: " << acos(cosAngle) << '\n';
}