#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int CountPairings(bool* taken, int n, bool** friendPair)
{
	int firstFree = -1;
	for (int i = 0; i < n; ++i)
	{
		if (!taken[i])
		{
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1)
		return 1;
	
	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith)
	{
		if (!taken[pairWith] && friendPair[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += CountPairings(taken, n, friendPair);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}

int main()
{
	int n, m;
	n = 6;
	m = 10;

	bool* taken = new bool[n];
	for (int i = 0; i < n; ++i)
		taken[i] = false;
	bool** areFriends = new bool*[m];
	for (int i = 0; i < m; ++i)
		areFriends[i] = new bool[m];

	map<string, int> studentMap;

	string example[10] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
	string* students = new string[n];
	copy(example, example + 6, students);

	string example2[100][2] = { {"a", "b"}, {"a", "c"}, {"b", "c"}, {"b", "d"}, {"b", "e"}, {"c", "d"}, {"c", "e"}, {"d", "e"}, {"d", "f"}, {"e", "f"} };

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
			areFriends[i][j] = false;
	}

	for (int i = 0; i < n; ++i)
		studentMap.insert(make_pair(students[i], i));
	
	for (int i = 0; i < m; ++i)
	{
		int x = studentMap.find(example2[i][0])->second;
		int y = studentMap.find(example2[i][1])->second;
		areFriends[x][y] = true;
		areFriends[y][x] = true;
	}

	cout << CountPairings(taken, n, areFriends);
	
}