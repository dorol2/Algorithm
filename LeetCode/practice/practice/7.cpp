#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

int reverse(int x) 
{
	vector<int> num;
	long k = abs(x);
	long t = 0;
	while ((k / 10) > 0)
	{
		num.push_back(k % 10);
		k = k / 10;
		++t;
	}
	num.push_back(k);

	k = 0; 
	long i = 0;
	while (t > 0)
	{
		long s = pow(10, t);
		k += num[i] * s;
		++i; --t;
	}
	k += num[i];

	if (k > INT_MAX || k < INT_MIN)
		return 0;

	if (x < 0)
		k *= -1;

	return k;
}

int main()
{
	cout << reverse(327681);
}