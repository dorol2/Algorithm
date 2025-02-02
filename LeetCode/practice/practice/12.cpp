#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

string intToRoman(int num) 
{
	int integers[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	
	for (int i = 0; i < 13; ++i)
	{
		if (num >= integers[i])
			return romans[i] + intToRoman(num - integers[i]);
	}
	return "";
}