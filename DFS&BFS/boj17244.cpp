#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char board[55][55];
vector<pair<int, int>> obj;

void Input()
{
	pair<int, int> finish;

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 'S')
				obj.insert(obj.begin(), { i, j });
			else if (board[i][j] == 'E')
			{
				finish.first = i;
				finish.second = j;
			}
			else if (board[i][j] == 'X')
				obj.push_back({ i, j });
		}
	}

	obj.push_back(finish);
}

int FindMinRoute(pair<int, int> a, pair<int, int> b)
{
	int minRoute = 0;
	queue<pair<int, int>> q;
	bool visited[55][55] = { 0, };

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	q.push(a);
	visited[a.first][a.second] = true;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == b.first && y == b.second) return minRoute;

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
				if (visited[nx][ny]) continue;
				if (board[nx][ny] == '#') continue;

				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}

		++minRoute;
	}

	return -1;
}

void Solve()
{
	int dist[15][15] = { 0, };

	for (int i = 0; i < obj.size(); ++i)
	{
		for (int j = 0; j < obj.size(); ++j)
		{
			if (i >= j) continue;
			dist[i][j] = dist[j][i] = FindMinRoute(obj[i], obj[j]);
		}
	}

	vector<int> vec;
	for (int i = 1; i < obj.size() - 1; ++i) vec.push_back(i);

	int answer = 1e9;

	do {
		int sum = 0, start = 0;
		for (auto i : vec)
		{
			sum += dist[start][i];
			start = i;
		}
		sum += dist[start][obj.size() - 1];

		answer = min(answer, sum);
	} while (next_permutation(vec.begin(), vec.end()));

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}