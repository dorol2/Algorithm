#include <iostream>
#include <vector>
using namespace std;

void printPicked(vector<int>& picked, vector<char>& characters)
{
	for(int t : picked)
	{
		cout << characters[t];
	}

	cout << " / ";
}

// n : 전체 원소 수
// picked : 지금까지 고른 원소들 번호
// toPick : 남은 골라야하는 원소 갯수 
void Pick(int n, vector<int>& picked, int toPick, vector<char>& characters)
{
	// 더 고를 원소가 없을 때 고른 원소 출력
	if(toPick == 0)
	{
		printPicked(picked, characters);
		return;
	}

	// 고를 수 있는 가장 작은 원소 위치 가져오기
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	// 고른 원소를 넣고 이후부터 차례대로 넣어보면서 재귀
	for(int next = smallest; next < n; ++next)
	{
		picked.push_back(next);
		Pick(n, picked, toPick - 1, characters);
		picked.pop_back();
	}
}

int main()
{
	// 전체 원소의 갯수와 그 중 고를 원소의 갯수
	int n, toPick;
	cin >> n >> toPick;

	char t;
	vector<char> characters;
	vector<int> picked;
	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		characters.push_back(t);
	}

	Pick(n, picked, toPick, characters);

	cin >> n;

	return 0;
}