#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct ol_info {
	int line, num, dir;
};

struct ans {
	int x, y, num;
};

int K;
int board[9][9];
int tmpboard[9][9];
vector<ol_info> overlap;
vector<pair<int, int>> emptyspace;
vector<ans> answer;

void DFS(int idx);

void CheckPossible(int y, int x, int idx)
{
	bool num[10] = { 0, };

	for (int i = 0; i < 9; ++i)
	{
		if (board[y][i]) num[board[y][i]] = true;
		if (board[i][x]) num[board[i][x]] = true;
	}

	int cnt = 0;

	for (int i = 1; i <= 9; ++i)
	{
		if (!num[i])
		{
			board[y][x] = i;

			DFS(idx + 1);

			board[y][x] = 0;
		}
		else cnt++;
	}

	if (cnt == 9) return;
}

void DFS(int idx)
{
	if (idx == emptyspace.size())
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (tmpboard[i][j] != board[i][j])
				{
					answer.push_back({ i, j, board[i][j] });
				}
			}
		}

		return;
	}

	int y = emptyspace[idx].first;
	int x = emptyspace[idx].second;

	CheckPossible(y, x, idx);
}

// 중복된 부분 삭제
void DeleteOverlap()
{
	for (int i = 0; i < overlap.size(); ++i)
	{
		int line = overlap[i].line;
		int num = overlap[i].num;
		int dir = overlap[i].dir;

		if (dir == 1)
		{
			for (int j = 0; j < 9; ++j)
				if (board[line][j] == num) board[line][j] = 0;
		}
		else if (dir == 2)
		{
			for (int j = 0; j < 9; ++j)
				if (board[j][line] == num) board[j][line] = 0;
		}
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			if (!board[i][j]) emptyspace.push_back({ i, j });
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	overlap.clear();
}

// 중복을 찾아낼 거임
void CheckOverlap()
{
	// 가로
	for (int i = 0; i < 9; ++i)
	{
		bool num[10] = { 0, };

		for (int j = 0; j < 9; ++j)
		{
			if (num[board[i][j]]) overlap.push_back({ i, board[i][j], 1 });
			else num[board[i][j]] = true;
		}
	}

	// 세로
	for (int i = 0; i < 9; ++i)
	{
		bool num[10] = { 0, };

		for (int j = 0; j < 9; ++j)
		{
			if (num[board[j][i]]) overlap.push_back({ i, board[j][i], 2 });
			else num[board[j][i]] = true;
		}
	}

	DeleteOverlap();
}

void Solve(int tc)
{
	memcpy(tmpboard, board, sizeof(tmpboard));

	CheckOverlap();

	DFS(0);

	cout << "#" << tc << " ";
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i].x + 1 << " " << answer[i].y + 1 << " " << answer[i].num << " ";
	cout << "\n";
}

void Input()
{
	memset(board, 0, sizeof(board));
	memset(tmpboard, 0, sizeof(tmpboard));
	emptyspace.clear();
	answer.clear();

	cin >> K;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> board[i][j];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		Input();
		Solve(tc);
	}
}