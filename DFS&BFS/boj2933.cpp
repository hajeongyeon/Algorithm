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

		// y + 1���� �ٴڱ��� �˻�
		// �ٴڿ� ��� ���� �̳׶��� �����µ� Ŭ�����͸� 1e9�� ��������
		for (int j = y + 1; j <= R; ++j)
		{
			if (board[j][x] == 'x')
			{
				if (visited[j][x]) tmpG = 1e9;
				break;
			}
			else tmpG++;
		}

		// Ŭ�����Ͱ� �ƴ϶�� ���� ���� ���̷� ��������
		if (tmpG != 1e9) g = min(g, tmpG);
	}

	// ���� �ؿ����� ��������ű� ������ ������ ������������ ��������
	sort(cluster.begin(), cluster.end(), cmp);

	// �������
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

	// ���� �̳׶� 4���� Ž��
	for (int i = 0; i < 4; ++i)
	{
		cluster.clear();
		memset(visited, 0, sizeof(visited));

		int cluster_y = y + dy[i];
		int cluster_x = x + dx[i];

		// ������̰ų�, ������ ����� continue
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

			// Ŭ�����Ͱ� �ٴڿ� ��������� cluster vector ����ְ� break
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

		// cluster vector�� ������� ������ ���߿� ���ִ°Ŵϱ� Gravity �Լ��� ���� Ŭ�����͸� ����߸� ����
		if (!cluster.empty()) Gravity();
	}
}

void Solve()
{
	for (int i = 0; i < N; ++i)
	{
		int y = R - stick[i] + 1;

		// â���� ����
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
		// ����� ����
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