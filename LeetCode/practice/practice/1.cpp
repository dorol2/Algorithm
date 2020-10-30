#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> k;//¼ö, À§Ä¡
	vector<int> answer;

	for (int i = 0; i < nums.size(); ++i)
	{
		int t = target - nums[i];
		if (k.find(t) != k.end())
		{
			answer.push_back(k[t]);
			answer.push_back(i);
			return answer;
		}
		else
			k.insert(make_pair(nums[i], i));
	}
	return answer;
}

int main()
{
	vector<int> test = {2, 7, 11, 15};
	vector<int> test2 = twoSum(test, 9);
	for(int i = 0; i < test2.size(); ++ i)
	{
		cout << test2[i] << " ";
	}

	return 0;
}