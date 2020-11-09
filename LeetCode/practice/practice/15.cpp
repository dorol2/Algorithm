#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.size() < 3)
		return result;

	sort(nums.begin(), nums.end());

	int preNum = nums[0];
	for (int i = 0; i < nums.size() - 2; ++i)
	{
		if (i != 0 && nums[i] == nums[i - 1])
			continue;

		int j = i + 1;
		int k = nums.size() - 1;

		while (j < k)
		{
			if (j != i + 1 && nums[j] == nums[j - 1])
			{
				++j;
				continue;
			}
			if (k != nums.size() - 1 && nums[k] == nums[k + 1])
			{
				--k;
				continue;
			}

			int t = nums[i] + nums[j] + nums[k];
			if (t < 0)
			{
				++j;
			}
			else if (t > 0)
			{
				--k;
			}
			else if (t == 0)
			{
				result.push_back({ nums[i], nums[j], nums[k] });
				++j; --k;
			}
		}
	}
	return result;
}

int main()
{
	//vector<int> test = { {0,0,0,0} };

	//threeSum(test);
	string s = "asdf";
	vector<int> test = { 0,0,0,0 };
	cout << endl << endl;
	int* t = new int[s.length()]{ -1 };

	for (int i = 0; i < s.length; i++)
	{
		cout << t[i];
	}
}