#include "all.h"
using namespace std;

void nextPermutation(vector<int>& nums) 
{
	int i = nums.size() - 1;
	for (; i > 0; --i)
	{
		if (nums[i] > nums[i - 1])
			break;
	}

	if (i == 0)
		return sort(nums.begin(), nums.end());
	
	--i; 
	int j = i + 1;
	int min = j;
	for (; j < nums.size(); ++j)
	{
		if (nums[j] == nums[i] + 1)
			break;
		else if ((nums[j] < nums[min]) && (nums[j] > nums[i]))
			min = j;
	}
	if (j == nums.size())
		j = min;

	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;

	vector<int>::iterator iter = nums.begin() + i + 1;
	sort(iter, nums.end());
}

int main()
{
	vector<int> nums = { 2,3,0,2,4,1 };

	nextPermutation(nums);

	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}