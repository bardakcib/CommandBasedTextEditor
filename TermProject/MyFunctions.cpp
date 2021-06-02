#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "intSLList.h"
#include "MyFunctions.h"

using namespace std;

string MyFunctions::LeftTrim(const string& s)
{
	size_t start = s.find_first_not_of(whitespaces);
	return (start == string::npos) ? "" : s.substr(start);
}

string MyFunctions::RightTrim(const std::string& s)
{
	size_t end = s.find_last_not_of(whitespaces);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

string MyFunctions::LeftAndRightTrimSpaces(const string& s)
{
	return RightTrim(LeftTrim(s));
}

string MyFunctions::ToLowerCase(string input)
{
	// by using & does NOT create a copy of each element of input
	// but instead directly referencesand stores it in c as an alias.
	// This means that modifying c does modify input.
	for (char& c : input)
		c = tolower(c);

	return input;
}

int MyFunctions::PageCountCalculator(int lineCount, int pageSize) {

	int totalPageCount = (lineCount / pageSize);

	if (totalPageCount == 0)
		totalPageCount++;
	else if (lineCount % pageSize != 0)
		totalPageCount++;

	return totalPageCount;
}

string* MyFunctions::SplitStringBySpaceToArray(string data)
{
	int i = 0;

	string* input = new string[3];
	string temp = LeftAndRightTrimSpaces(data); // remove spaces from begin and end of the string

	stringstream ssin(temp);

	while (ssin.good() && i < 3) {
		ssin >> temp;
		if (i == 2)
		{
			// if it is the 3 part of the comment for ex 'insert 5 basdas asnd asd'
			// I dont want to remove spaces of this part
			data.replace(0, input[0].length(), ""); // input[0] olarak belirledigimiz insert i '' ile replace eder yani siler
			data = LeftAndRightTrimSpaces(data);
			data.replace(0, input[1].length(), ""); // input[1] olarak belirledigimiz 5 i '' ile replace eder yani siler
			input[i] = LeftAndRightTrimSpaces(data);
		}
		else {
			input[i] = temp;
		}

		i++;
	}
	return input;
}

string* MyFunctions::SplitStringByDelimiterToArray(string s, string delim) {
	int i = 0;
	string* input = new string[5];
	int start = 0;
	int end = s.find(delim);

	while (end != string::npos)
	{
		input[i] = s.substr(start, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(end) - start);
		i++;
		start = end + delim.length();
		end = s.find(delim, start);
	}

	input[i] = s.substr(start, end);

	return input;
}



