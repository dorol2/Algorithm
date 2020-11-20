#include "all.h"
using namespace std;

vector<int> findSubstring(string s, vector<string>& words)
{
	unordered_map<string, int> check;

	for (int i = 0; i < words.size(); ++i)
	{
		if (check.find(words[i]) != check.end())
			check[words[i]]++;
		else
			check.insert(make_pair(words[i], 1));
	}

	int wordLength = words[0].length();
	vector<int> result;
	//뒤에 갯수가 적게 남은 경우 확인 안해도 됨.

	for (int i = 0; i < s.length() - words.size() * wordLength + 1; ++i)
	{
		unordered_map<string, int> checkCount;

		for (int j = 0; j < words.size(); ++j)
		{
			string str = s.substr(i + j * wordLength, wordLength);
			if (check.find(str) != check.end())
			{
				if (checkCount.find(str) != checkCount.end())
					checkCount[str]++;
				else
					checkCount.insert(make_pair(str, 1));

				if (checkCount[str] > check[str])
					break;
			}
			else
				break;
			if (j == words.size() - 1)
				result.push_back(i);
		}
	}
	return result;
}

int main()
{
	string s = "barfoothefoobarman";
	vector<string> vs = { "foo", "bar" };
	findSubstring(s, vs);
}