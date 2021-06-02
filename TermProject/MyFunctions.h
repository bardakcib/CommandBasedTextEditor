#include <string>
#include "intSLList.h"

#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H


using namespace std;

class MyFunctions {
public:
	string LeftTrim(const string& s);
	string RightTrim(const string& s);
	int PageCountCalculator(int, int);
	string* SplitStringBySpaceToArray(string data);
	string* SplitStringByDelimiterToArray(string, string);
	string LeftAndRightTrimSpaces(const string& s);
	string ToLowerCase(string);

private:
	string whitespaces = " \n\r\t\f\v";
};
#endif

