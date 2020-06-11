#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int m, n, k, board[50][50];
bool visited[50][50];

void BFS()
{
	int ans = 0, dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!board[i][j] || visited[i][j]) continue;

			queue<pair<int, int>> cab;
			cab.push({ i, j });
			visited[i][j] = true;

			while (!cab.empty())
			{
				int x = cab.front().first;
				int y = cab.front().second;
				cab.pop();

				for (int i = 0; i < 4; ++i)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (visited[nx][ny]) continue;

					if (board[nx][ny] == 1) 
					{
						visited[nx][ny] = true;
						cab.push({ nx, ny });
					}
				}
			}

			ans++;
		}
	}

	cout << ans << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;

	for (int tc = 0; tc < t; ++tc)
	{
		memset(visited, false, sizeof(visited));
		memset(board, 0, sizeof(board));
		
		cin >> m >> n >> k;
		
		for (int i = 0; i < k; ++i)
		{
			int a, b; cin >> a >> b;
			board[b][a] = 1;
		}

		BFS();
	}
}