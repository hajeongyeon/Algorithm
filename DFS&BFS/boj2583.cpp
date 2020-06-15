// 2020.06.15 15:25~16:00
// 백준 2583 영역 구하기
// BFS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
bool board[100][100], visited[100][100];
vector<int> answer;

void Input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < k; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		for (int i = b; i < d; ++i)
			for (int j = a; j < c; ++j)
				board[i][j] = true;
	}
}

void Solve()
{
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };
		 
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] || visited[i][j]) continue;

			queue<pair<int, int>> q;
			q.push({ i, j });
			int sqrsize = 1;
			visited[i][j] = true;

			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int p = 0; p < 4; ++p)
				{
					int nx = x + dx[p];
					int ny = y + dy[p];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (board[nx][ny] || visited[nx][ny]) continue;

					q.push({ nx, ny });
					visited[nx][ny] = true;
					sqrsize++;
				}
			}

			answer.push_back(sqrsize);
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << " ";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
