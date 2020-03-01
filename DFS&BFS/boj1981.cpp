#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, arr[101][101], low = 222, high = -1;
bool visited[101][101];

bool BFS(int m)
{
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };

	queue<pair<int, int>> q;

	for (int i = low; i <= high; ++i)
	{
		memset(visited, true, sizeof(visited));

		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				if (arr[j][k] >= i && arr[j][k] <= i + m)
					visited[j][k] = false;

		q.push({ 0, 0 });

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (visited[x][y]) continue;
			visited[x][y] = true;

			if (x == n - 1 && y == n - 1) return true;

			for (int j = 0; j < 4; ++j)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

				q.push({ nx, ny });
			}
		}
	}

	return false;
}

void B_Search()
{
	int s = 0, e = high - low, mid = 0;

	while (s <= e)
	{
		mid = (s + e) / 2;
		if (BFS(mid)) e = mid - 1;
		else s = mid + 1;
	}

	cout << e + 1;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];

			if (arr[i][j] < low) low = arr[i][j];
			if (arr[i][j] > high) high = arr[i][j];
		}
	}

	B_Search();
}