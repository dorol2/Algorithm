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

// n : ��ü ���� ��
// picked : ���ݱ��� �� ���ҵ� ��ȣ
// toPick : ���� �����ϴ� ���� ���� 
void Pick(int n, vector<int>& picked, int toPick, vector<char>& characters)
{
	// �� �� ���Ұ� ���� �� �� ���� ���
	if(toPick == 0)
	{
		printPicked(picked, characters);
		return;
	}

	// �� �� �ִ� ���� ���� ���� ��ġ ��������
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	// �� ���Ҹ� �ְ� ���ĺ��� ���ʴ�� �־�鼭 ���
	for(int next = smallest; next < n; ++next)
	{
		picked.push_back(next);
		Pick(n, picked, toPick - 1, characters);
		picked.pop_back();
	}
}

int main()
{
	// ��ü ������ ������ �� �� �� ������ ����
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