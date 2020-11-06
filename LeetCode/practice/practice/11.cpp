#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

int maxArea(vector<int>& height) 
{
	int start = 0;
	int end = height.size() - 1;
	int result = 0;
	while (start < end)
	{
		int t = min(height[start], height[end]) * (end - start);
		result = max(result, t);
		if (height[start] > height[end])
			--end;
		else
			++start;
	}
	return result;
}