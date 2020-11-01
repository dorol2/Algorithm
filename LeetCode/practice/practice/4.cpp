#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	if (nums1.size() > nums2.size())
		return findMedianSortedArrays(nums2, nums1);

	int start = 0;
	int end = nums1.size(); 
	int partition1 = (start + end) / 2;
	int partition2 = (nums1.size() + nums2.size() + 1) / 2 - partition1;

	int leftNums1 = 0, rightNums1 = -1; 
	int leftNums2 = 0, rightNums2 = -1; 

	if (partition1 == 0)
		leftNums1 = INT_MIN;
	if (partition2 == nums2.size())
		rightNums2 = INT_MAX;

	while (!((leftNums1 <= rightNums2) &&
		(leftNums2 <= rightNums1)))
	{
		partition1 = (start + end) / 2;
		partition2 = (nums1.size() + nums2.size() + 1) / 2 - partition1;

		if (partition1 == 0)
			leftNums1 = INT_MIN;
		else 
			leftNums1 = nums1[partition1 - 1];

		if (partition1 == nums1.size())
			rightNums1 = INT_MAX;
		else
			rightNums1 = nums1[partition1];

		if (partition2 == 0)
			leftNums2 = INT_MIN;
		else
			leftNums2 = nums2[partition2 - 1];

		if (partition2 == nums2.size())
			rightNums2 = INT_MAX;
		else
			rightNums2 = nums2[partition2];

		if (leftNums1 > rightNums2)
		{
			//nums1�� left�� nums2�� right���� Ŭ ��
			//partition1�� �ϳ� �մ���. 
			end = partition1 - 1;
		}
		else if (leftNums2 > rightNums1)
		{
			//nums2�� left�� nums1�� right���� Ŭ ��
			//partition1�� �ϳ� �ڷ� ������. 
			start = partition1 + 1;
		}
	}

	double median = 0;
	if ((nums1.size() + nums2.size()) % 2 != 0)
	{
		//��ü ������ Ȧ���� ��
		median = (double) max(leftNums1, leftNums2);
	}
	else
	{
		//��ü ������ ¦���� ��
		median = (double)((max(leftNums1, leftNums2)) + min(rightNums1, rightNums2)) / 2;
	}

	return median;
}

double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() > nums2.size()) {
		return findMedianSortedArrays(nums2, nums1);
	}
	int x = nums1.size();
	int y = nums2.size();

	int low = 0;
	int high = x;

	while (low <= high) {
		int partitionX = (low + high) / 2;
		int partitionY = ((x + y + 1) / 2) - partitionX; //+1 bcz it goes well with both odd and even numbers

		int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
		int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

		int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
		int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

		//If we find the break point 
		if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
			if ((x + y) % 2 == 0) {
				return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
			}
			else {
				return (double)max(maxLeftX, maxLeftY);
			}
		}
		else {
			if (maxLeftX > minRightY) {
				high = partitionX - 1;
			}
			else {
				low = partitionX + 1;
			}
		}
	}
	//If the array is not sorted i.e. the input is wrong
	return -1;
}


int main()
{
	vector<int> nums1 = { };
	vector<int> nums2 = { 1 };

	cout << findMedianSortedArrays2(nums1, nums2);
}



