#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;


int myAtoi(string str)
{
	if (str.empty() || str.length() == 0)
		return 0;
	
	int i = 0;
	bool negative = false;

	while (i < str.length() && str.at(i) == ' ')
		++i;
	
	str = str.substr(i);

	if (str.empty() || str.length() == 0)
		return 0;

	i = 0;
	if (str.at(i) == '-')
	{
		negative = true;
		str = str.substr(1);
	}
	else if (str.at(i) == '+')
		str = str.substr(1);

	i = 0;
	double answer = 0;
	while (i < str.length())
	{
		char c = str.at(i);
		if (c >= '0' && c <= '9')
			answer = answer * 10.0 + (c - '0');
		else
			break;
		++i;
	}

	if (negative)
		answer *= -1;

	if (answer > INT_MAX)
		return INT_MAX;
	else if (answer < INT_MIN)
		return INT_MIN;

	return (int) answer;
}


int main()
{
	cout << myAtoi(" ") << endl;
}




