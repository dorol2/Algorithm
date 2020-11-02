#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

string convert(string s, int numRows) 
{
	string answer = "";
	string* str = new string[numRows];

	int i = 0;
	while (i < s.length())
	{
		//아래로 떨어지는 일자부분
		for (int j = 0; j < numRows && i < s.length(); ++j)
		{
			str[j] += s.at(i);
			++i;
		}
		//올라가는 대각선 부분
		for (int k = numRows - 2; k > 0 && i < s.length(); --k)
		{
			str[k] += s.at(i);
			++i;
		}
	}

	for (int t = 0; t < numRows; ++t)
		answer += str[t];
	
	return answer;
}
