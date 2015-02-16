#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	string input, tmp;
	set<string> dictionary;
	while( getline(cin, input) ) {
		for_each(input.begin(), input.end(), [](char &x) { if(!isalpha(x)) x=' '; x=tolower(x); });
		stringstream ss(input);
		while( ss >> tmp ) dictionary.insert(tmp);
	}
	for_each(dictionary.begin(), dictionary.end(), [](const string &str) { cout << str << endl; });

	return 0;
}