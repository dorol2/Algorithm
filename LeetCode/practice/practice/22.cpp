#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

void Backtracking(vector<string> &answer, string current, int open, int close, int max)
{
	if (current.length() == max * 2)
	{
		answer.push_back(current);
		return;
	}

	if (open < max)
		Backtracking(answer, current + "(", open + 1, close, max);
	if (close < open)
		Backtracking(answer, current + ")", open, close + 1, max);
}

vector<string> generateParenthesis(int n) 
{
	vector<string> answer;
	Backtracking(answer, "", 0, 0, n);
	return answer;
}

int main()
{
	int num = 3;
	vector<string> t = generateParenthesis(num);
	vector<string>::iterator str;
	for (str = t.begin(); str != t.end(); ++str)
	{
		cout << *str << endl;
	}
}