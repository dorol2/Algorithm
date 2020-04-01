#include <iostream>
#include <vector>
#include <string>
using namespace std;

//���� x, y��ǥ���� 8���� Ȯ��
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, -1, 1, 0, 1, -1, 1 };

string BoolToString(bool b)
{
	return b ? "true" : "false";
}

bool InRange(int y, int x, int n)
{
	if (x > n || x < 0)
		return false;
	if (y > n || y < 0)
		return false;
	return true;
}

bool HasWord(int y, int x, const string& word, string** board, int n)
{
	//���� ���� �ִ���
	if (!InRange(y, x, n))
		return false;
	//ù ���ڰ� ��ġ�ϴ� ��
	if (board[y][x].at(0) != word[0])
		return false;
	//�ܾ� ���̰� 1�� ��� ����
	if (word.size() == 1)
		return true;
	//������ 8ĭ �˻�
	for (int direction = 0; direction < 8; ++direction)
	{
		int nextY = y + dy[direction];
		int nextX = x + dx[direction];
		if (HasWord(nextY, nextX, word.substr(1), board, n))
			return true;
	}
	return false;
}

int main()
{
	//nxn
	int n; 
	cin >> n;

	string** board = new string*[n];

	for (int i = 0; i < n; ++i)
	{
		board[i] = new string[n];
	}

	string bString[] = { "U", "R", "L", "P", "M",
						 "X", "P", "R", "E", "T",
						 "G", "I", "A", "E", "T",
						 "X", "T", "N", "Z", "Y",
						 "X", "O", "Q", "R", "S" };

	int k = 0;
	//���� �Է�
	for (int i = 0 ; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			board[i][j] = bString[k];
			++k;
		}
	}

	//���� �ܾ� �Է�
	string word = "PRETTY";
	//cin >> word;

	bool result = false;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (HasWord(i, j, word, board, n))
			{
				result = true;
				break;
			}
		}
		if (result)
			break;
	}

	cout << BoolToString(result);

	cin >> n;
	
	return 0;
}

