#include "all.h"

using namespace std;

int removeElement(vector<int>& nums, int val) 
{
	vector<int>::iterator it = nums.begin();
	for (int i = 0; i < nums.size();)
	{
		if (nums[i] == val)
			nums.erase(it + i);
		else
			++i;
		if (i == 0)
			it = nums.begin();
	}
	return nums.size();
}
