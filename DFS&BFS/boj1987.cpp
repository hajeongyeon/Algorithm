// 2020.09.04 20:00~20:32
// 백준 1987 알파벳
// DFS

#include <iostream>
#include <algorithm>
using namespace std;

int r, c, answer;
char board[21][21];
bool visited[21][21], alpha[26];

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void Input()
{
	cin >> r >> c;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			cin >> board[i][j];
}

void DFS(int x, int y, int val)
{
	if (x == r && y == c)
	{
		answer = max(answer, val);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 1 || ny < 1 || nx > r || ny > c || visited[nx][ny]) continue;

		int na = board[nx][ny] - 'A';
		if (alpha[na]) continue;

		alpha[na] = true;
		visited[nx][ny] = true;
		DFS(nx, ny, val + 1);
		visited[nx][ny] = false;
		alpha[na] = false;
	}

	answer = max(answer, val);
}

void Solve()
{
	alpha[board[1][1] - 'A'] = true;
	visited[1][1] = true;
	DFS(1, 1, 1);

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
