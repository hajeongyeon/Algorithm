#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int R, C, N;
char board[105][105];
int stick[100];

vector<pair<int, int>> cluster;
bool visited[101][101];

void Input()
{
	cin >> R >> C;

	for (int i = 1; i <= R; ++i)
		for (int j = 1; j <= C; ++j)
			cin >> board[i][j];

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> stick[i];
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first > b.first;
}

void Gravity()
{
	int g = 1e9;

	for (int i = 0; i < cluster.size(); ++i)
	{
		int y = cluster[i].first;
		int x = cluster[i].second;

		int tmpG = 0;

		// y + 1부터 바닥까지 검사
		// 바닥에 닿기 전에 미네랄을 만났는데 클러스터면 1e9로 만들어버림
		for (int j = y + 1; j <= R; ++j)
		{
			if (board[j][x] == 'x')
			{
				if (visited[j][x]) tmpG = 1e9;
				break;
			}
			else tmpG++;
		}

		// 클러스터가 아니라면 가장 작은 높이로 갱신해줌
		if (tmpG != 1e9) g = min(g, tmpG);
	}

	// 가장 밑에부터 가라앉힐거기 때문에 높이의 내림차순으로 정렬해줌
	sort(cluster.begin(), cluster.end(), cmp);

	// 가라앉힘
	for (int i = 0; i < cluster.size(); ++i)
	{
		int y = cluster[i].first;
		int x = cluster[i].second;

		board[y + g][x] = 'x';
		board[y][x] = '.';
	}
}

void FindCluster(int y, int x)
{
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };

	// 깨진 미네랄 4방향 탐색
	for (int i = 0; i < 4; ++i)
	{
		cluster.clear();
		memset(visited, 0, sizeof(visited));

		int cluster_y = y + dy[i];
		int cluster_x = x + dx[i];

		// 빈공간이거나, 범위를 벗어나면 continue
		if (board[cluster_y][cluster_x] == '.') continue;
		if (cluster_y < 1 || cluster_x < 1 || cluster_y > R || cluster_x > C) continue;

		queue<pair<int, int>> q;
		q.push({ cluster_y, cluster_x });
		cluster.push_back({ cluster_y, cluster_x });
		visited[cluster_y][cluster_x] = true;

		while (!q.empty())
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			// 클러스터가 바닥에 닿아있으면 cluster vector 비워주고 break
			if (cy == R)
			{
				cluster.clear();
				break;
			}

			for (int j = 0; j < 4; ++j)
			{
				int ny = cy + dy[j];
				int nx = cx + dx[j];

				if (ny < 1 || nx < 1 || ny > R || nx > C) continue;
				if (visited[ny][nx]) continue;
				if (board[ny][nx] == '.') continue;

				visited[ny][nx] = true;
				q.push({ ny, nx });
				cluster.push_back({ ny, nx });
			}
		}

		// cluster vector가 비어있지 않으면 공중에 떠있는거니까 Gravity 함수로 가서 클러스터를 떨어뜨릴 거임
		if (!cluster.empty()) Gravity();
	}
}

void Solve()
{
	for (int i = 0; i < N; ++i)
	{
		int y = R - stick[i] + 1;

		// 창영이 차례
		if (i % 2 == 0)
		{
			for (int j = 1; j <= C; ++j)
			{
				if (board[y][j] == 'x')
				{
					board[y][j] = '.';
					FindCluster(y, j);
					break;
				}
			}
		}
		// 상근이 차례
		else
		{
			for (int j = C; j >= 1; --j)
			{
				if (board[y][j] == 'x')
				{
					board[y][j] = '.';
					FindCluster(y, j);
					break;
				}
			}
		}
	}

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
			cout << board[i][j];
		cout << "\n";
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}