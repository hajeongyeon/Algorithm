#include <iostream>
#include <queue>
using namespace std;

struct info {
	int x, y, day;
};

int arr[1000][1000];
bool visited[1000][1000];

int main() 
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int m, n, dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 }, answer = 0;
	queue<info> tmt;
	
	cin >> m >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 1)
			{
				tmt.push({ i, j, 0 });
				visited[i][j] = true;
			}
		}
	}
	
	while (!tmt.empty())
	{
		int x = tmt.front().x;
		int y = tmt.front().y;
		int day = tmt.front().day;
		tmt.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || arr[nx][ny] == -1) continue;

			arr[nx][ny] = 1;
			tmt.push({ nx, ny, day + 1 });
			visited[nx][ny] = true;
		}

		answer = day;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!arr[i][j])
			{
				cout << "-1";
				return 0;
			}
		}
	}

	cout << answer;
}