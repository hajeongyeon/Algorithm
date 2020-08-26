#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct info {
	int sx, sy, dx, dy;
};

struct qinfo {
	int x, y, dist, num;
};

int n, m, fuel, spare;
int board[21][21];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
pair<int, int> start;
vector<info> customer;

bool comparerowcol(qinfo& a, qinfo& b)
{
	if (a.dist <= b.dist)
	{
		if (a.dist == b.dist)
		{
			if (a.x <= b.x)
			{
				if (a.x == b.x)
				{
					if (a.y < b.y) return true;
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

void Input()
{
	cin >> n >> m >> fuel;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) board[i][j] = -1;
		}
	}

	cin >> start.first >> start.second;

	for (int i = 1; i <= m; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		customer.push_back({ a, b, c, d });
		board[a][b] = i;
	}
}

bool isWall(int x, int y)
{
	if (x <= 0 || y <= 0 || x > n || y > n || board[x][y] == -1) return true;
	return false;
}

// 1. 가장 가까운 손님을 BFS를 이용하여 탐색
int FindNear()
{
	bool check[21][21] = { 0, };
	vector<qinfo> candid;

	queue<qinfo> q;
	q.push({ start.first, start.second, 0, fuel });
	check[start.first][start.second] = true;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().dist;
		int f = q.front().num;
		q.pop();

		if (board[x][y] >= 1) candid.push_back({ x, y, d, board[x][y] });
		if (f == 0) continue;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isWall(nx, ny) || check[nx][ny]) continue;
			
			check[nx][ny] = true;
			q.push({ nx, ny, d + 1, f - 1 });
		}
	}

	if (!candid.size()) return -1;

	sort(candid.begin(), candid.end(), comparerowcol);
	board[candid[0].x][candid[0].y] = 0;
	fuel -= candid[0].dist;

	return candid[0].num;
}

// 2. BFS를 사용하여 이동 - 도착 전에 연료 부족 -> false / 도착 -> 연료 충전하고 true
bool GoDest(int num)
{
	bool check[21][21] = { 0, };

	queue<qinfo> q;
	q.push({ customer[num - 1].sx, customer[num - 1].sy, 0, fuel });

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().dist;
		int f = q.front().num;
		q.pop();

		if (x == customer[num - 1].dx && y == customer[num - 1].dy)
		{
			fuel = fuel + d;
			start.first = x;
			start.second = y;
			return true;
		}

		if (f == 0) return false;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isWall(nx, ny) || check[nx][ny]) continue;

			check[nx][ny] = true;
			q.push({ nx, ny, d + 1, f - 1 });
		}
	}

	return false;
}

void Solve()
{
	int idx = m;
	while (idx > 0)
	{
		int cNum = FindNear();
		if (cNum == -1)
		{
			cout << "-1";
			return;
		}

		bool move = GoDest(cNum);
		if (!move)
		{
			cout << "-1";
			return;
		}

		idx--;
	}

	cout << fuel;
}

int main(void)
{
	ios::sync_with_stdio(false);

	Input();
	Solve();
}
