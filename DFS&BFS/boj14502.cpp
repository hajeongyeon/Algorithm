#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, arr[8][8], pick[3], answer = -1;
vector<pair<int, int>> emp, virus;

void BFS()
{
	int tmparr[8][8] = { 0, };
	int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };
	bool visited[8][8] = { 0, };

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			tmparr[i][j] = arr[i][j];

	for (int i = 0; i < 3; ++i)
		tmparr[emp[pick[i]].first][emp[pick[i]].second] = 1;

	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); ++i)
	{
		q.push(virus[i]);
		visited[virus[i].first][virus[i].second] = true;
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || tmparr[nx][ny] == 1) continue;

			tmparr[nx][ny] = 2;
			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	int candid = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!tmparr[i][j]) candid++;

	answer = max(answer, candid);
}

void Comb(int idx, int n, int r, int cnt)
{
	if (r == 0) BFS();
	else if (cnt == n) return;
	else
	{
		pick[idx] = cnt;
		Comb(idx + 1, n, r - 1, cnt + 1);
		Comb(idx, n, r, cnt + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 2) virus.push_back({ i, j });
			else if (arr[i][j] == 0) emp.push_back({ i, j });
		}
	}

	Comb(0, emp.size(), 3, 0);
	cout << answer;
}