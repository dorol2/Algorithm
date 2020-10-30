#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int blockType[4][3][2] =
	{
		{{0, 0}, {1, 0}, {0, 1} },
		{{0, 0}, {0, 1}, {1, 1}},
		{{0, 0}, {1, 0}, {1, 1}},
		{{0, 0}, {1, 0}, {1, -1}},
	};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; ++i)
	{
		const int ny = y + blockType[type][i][0];
		const int nx = x + blockType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}
	return ok;
}

//board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환
int cover(vector<vector<int>>& board)
{
	//가장 윗 줄, 왼쪽부터 채워 나가서 다 채울 수 있는 지 확인
	int y = -1;
	int x = -1;
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)
			break;
	}
	
	// 모든 칸을 채운 경우, return;
	if (y == -1)
		return 1;

	int ret = 0;
	for (int type = 0; type < 4; ++type)
	{
		//type의 형태블럭으로 매울 수 있는 경우 재귀
		if (set(board, y, x, type, 1))
			ret += cover(board);
		//덮을 수 없는 경우 블럭을 제거하고 다음 타입을 넣어본다.
		set(board, y, x, type, -1);
	}	
	return ret;
}

vector<vector<int>> StringBoardToIntBoard(vector<string> stringBoard)
{
	string str = stringBoard[0];
	vector<vector<int>> intBoard(stringBoard.size(), vector<int> (str.length()));

	for (int i = 0; i < stringBoard.size(); ++i)
	{
		str = stringBoard[i];
		for (int j = 0; j < str.length(); ++j)
		{
			if (str.at(j) == '#')
				intBoard[i][j] = 1;
			else
				intBoard[i][j] = 0;
		}
	}
	return intBoard;
}

int main()
{
	int n, m; // 가로, 세로 칸의 수
	vector<string> boardString;
	string board = "";

	cin >> n >> m;

	for (int i = 0 ; i < n; ++i)
	{
		cin >> board;
		boardString.push_back(board);
	}

	vector<vector<int>> intBoard = StringBoardToIntBoard(boardString);

	cout << cover(intBoard) << endl;

	return 0;
}

/*
example

3 7
#.....#
#.....#
##..###

output : 2
*/