#include <iostream>
#include <queue>
using namespace std;

char board[5][5];
bool visited[25];
int answer;

void BFS()
{
	queue<pair<int, int>> q;
	bool check[5][5] = { 0, }, qcheck[5][5] = { 0, };
	int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

	bool tmp = false;
	for (int i = 0; i < 25; ++i)
	{
		if (visited[i])
		{
			check[i / 5][i % 5] = true;

			if (!tmp)
			{
				q.push({ i / 5, i % 5 });
				qcheck[i / 5][i % 5] = true;
				tmp = true;
			}
		}
	}

	int cnt = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (cnt == 7)
		{
			answer++;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

			if (check[nx][ny] && !qcheck[nx][ny])
			{
				qcheck[nx][ny] = true;
				q.push({ nx, ny });
				cnt++;
			}
		}
	}
}

bool CheckFour()
{
	int cnt = 0;
	for (int i = 0; i < 25; ++i)
		if (visited[i])
			if (board[i / 5][i % 5] == 'S') cnt++;

	if (cnt >= 4) return true;
	return false;
}

void DFS(int n, int cnt)
{
	// 7명 뽑았고, 이다솜파 4명 이상이면 BFS 돌림
	if (cnt == 7)
	{
		if (CheckFour()) BFS();
		return;
	}

	// 범위가 n부터임.. n+1부터해서 틀림 ㅠㅠ -> 반례 : 전부다 S
	for (int i = n; i < 25; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			DFS(i, cnt + 1);
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> board[i][j];

	DFS(0, 0);
	cout << answer;
}