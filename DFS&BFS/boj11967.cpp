#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;

vector<pair<int, int>> room[101][101];
bool visited[101][101];
bool light[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool flag;

void BFS()
{
	bool lo_visited[101][101] = { 0, };
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	lo_visited[1][1] = true;
	light[1][1] = true;
	flag = false;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// room에 스위치가 있으면
		if (!visited[x][y] && room[x][y].size())
		{
			for (int i = 0; i < room[x][y].size(); ++i)
			{
				light[room[x][y][i].first][room[x][y][i].second] = true;
			}
			visited[x][y] = true;
			flag = true;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			if (lo_visited[nx][ny]) continue;
			if (!light[nx][ny]) continue;
			
			q.push({ nx, ny });
			lo_visited[nx][ny] = true;
		}
	}
}

void Solve()
{
	int answer = 0;

	while (1)
	{
		BFS();

		if (!flag) break;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (light[i][j]) answer++;
		}
	}

	cout << answer;
}

void Input()
{
	int M;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		room[x][y].push_back({ a, b });
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}