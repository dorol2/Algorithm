#include "all.h"
using namespace std;

int longestValidParentheses(string s) 
{
	int result = 0; 
	int count = 0;
	stack<int> check;
	stack<int> none;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s.at(i) == '(')			
			check.push(i);
		else if(s.at(i) == ')')
		{
			if (check.size() == 0)
				none.push(i);
			else
			{
				check.pop();
				int t = -1;
				if (!check.empty())
					t = check.top();
				if (!none.empty() && none.top() > t)
					t = none.top();
				result = max(i - t, result);
			}
		}
	}
	return result;
}

int main()
{
	string s = ")(((((()())()()))()(()))(";
	string ss = ")()())";
	cout << longestValidParentheses(ss) << endl;
}