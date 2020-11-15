#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
	if (nums.size() == 0 || nums.size() == 1)
		return nums.size();
	
	vector<int>::iterator iter = nums.begin();

	for (int i = 0; i < nums.size();)
	{
		if (i == 0)
			++i;
		else if (nums[i] == nums[i - 1])
		{
			nums.erase(iter + i);
		}
		else
			++i;
	}

	return nums.size();
}
