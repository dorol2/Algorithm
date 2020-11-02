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
		//�Ʒ��� �������� ���ںκ�
		for (int j = 0; j < numRows && i < s.length(); ++j)
		{
			str[j] += s.at(i);
			++i;
		}
		//�ö󰡴� �밢�� �κ�
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
