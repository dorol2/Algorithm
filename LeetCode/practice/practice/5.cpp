#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

string longestPalindrome(string s) 
{
	if ((s.length() < 0) || s.empty())
		return "";

	int start = 0, end = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		int lenStartOne = Counter(s, i, i);
		int lenStartTwo = Counter(s, i, i + 1);
		int maxLength = max(lenStartOne, lenStartTwo);
		if (maxLength > end - start)
		{
			start = i - (maxLength - 1) / 2;
			end = i + (maxLength) / 2;
		}
	}
	return s.substr(start, end + 1);
}

int Counter(string s, int start, int end)
{
	while ((start >= 0) && (end < s.length()) && (s.at(start) == s.at(end)))
	{
		--start;
		++end;
	}

	return end - start - 1;
}

