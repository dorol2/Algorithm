#include "all.h"

using namespace std;

int strStr(string haystack, string needle) 
{
	if (needle == "")
		return 0;

	if (haystack.length() < needle.length())
		return -1;
	
	for (int i = 0; i < haystack.length(); ++i)
	{
		if (i + needle.length() > haystack.length())
			break;

		if (haystack.at(i) == needle.at(0))
		{
			bool a = true;
			for (int j = 1; j <= needle.length()/2; ++j)
			{
				if ((haystack.at(i + j) != needle.at(j)) ||
					(haystack.at(i + needle.length() - j) != needle.at(needle.length() - j)))
				{
					a = false;
					break;
				}
			}
			if (a)
				return i;
		}
	}
	return -1;
}