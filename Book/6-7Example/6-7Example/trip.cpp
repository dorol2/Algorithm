#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int MAX = 100000;

double shortestPath(vector<int>& path, vector<bool> visited, double currentLength, int n, double** dist)
{
	//��� ���ø� �� �湮���� �� -> ���� ���÷� ���ư��� return;
	if (path.size() == n)
		return currentLength + dist[path[0]][path.back()];
	double ret = 100000;
	for (int next = 0; next < n; ++next)
	{
		if (visited[next])
			continue;
		int here = path.back();
		path.push_back(next);
		visited[next] = true;

		double cand = shortestPath(path, visited, currentLength + dist[here][next], n, dist);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}
	return ret;
}



int main()
{
	int n;

}