// 2020.06.21 23:23~2020.06.22 12:03
// 백준 2239 스도쿠
// 백트래킹

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char board[9][9];
vector<pair<int, int>> space;

void Solve(int);

void Input()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == '0') space.push_back({ i, j });
		}
	}
}

void check(int x, int y, int idx)
{
	bool check[10] = { 0, };

	// 가로 체크
	for (int i = 0; i < 9; ++i)
		if (board[x][i] != '0')
			check[board[x][i] - '0'] = true;

	// 세로 체크
	for (int i = 0; i < 9; ++i)
		if (board[i][y] != '0')
			check[board[i][y] - '0'] = true;

	// 사각형 체크
	int tmpx = (x / 3) * 3;
	int tmpy = (y / 3) * 3;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (board[tmpx + i][tmpy + j] != '0')
				check[board[tmpx + i][tmpy + j] - '0'] = true;

	int cnt = 0;
	for (int k = 1; k < 10; ++k)
	{
		if (!check[k])
		{
			board[x][y] = k + '0';
			Solve(idx + 1);
			board[x][y] = '0';
		}
	}

	if (cnt == 9) return;
}

void Solve(int idx)
{
	if (idx == space.size())
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				cout << board[i][j];
			cout << "\n";
		}

		exit(0);
	}
	
	int x = space[idx].first;
	int y = space[idx].second;

	check(x, y, idx);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve(0);
}
