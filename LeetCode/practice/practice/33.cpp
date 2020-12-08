#include "all.h"
using namespace std;

int Find(vector<int>& nums, int start, int end, int target)
{
	int mid = start + (end - start) / 2;
	
	if (start > end)
		return -1;

	if (nums[mid] == target)
		return mid;

	if (nums[start] <= nums[mid])
	{
		if (nums[start] <= target && nums[mid] > target)
			return Find(nums, start, mid - 1, target);
		else
			return Find(nums, mid + 1, end, target);
	}

	if (nums[mid] <= nums[end])
	{
		if (nums[mid] <= target && nums[end] >= target)
			return Find(nums, mid + 1, end, target);
		else
			return Find(nums, start, mid - 1, target);
	}

	return -1;
}

int search(vector<int>& nums, int target)
{
	return Find(nums, 0, nums.size() - 1, target);
}

int main()
{
	int target = 5;
	vector<int> nums = { 4,5,6,7,0,1,2 };
	cout << search(nums, target) << endl;
}