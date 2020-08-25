#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct info {
	int sx, sy, dx, dy;
	bool isArrive;
};

struct qinfo {
	int x, y, dist;
};

int n, m, fuel;
int board[21][21];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
pair<int, int> start;
vector<info> customer;

bool comparerowcol(qinfo& a, qinfo& b)
{
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

void Input()
{
	cin >> n >> m >> fuel;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> board[i][j];

	cin >> start.first >> start.second;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		customer.push_back({ a, b, c, d, false });
		board[a][b] = i + 2;
	}

	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < n; ++j)
	//		cout << board[i][j] << " ";
	//	cout << endl;
	//}
}

bool isWall(int x, int y)
{
	if (x <= 0 || y <= 0 || x > n || y > n || board[x][y] == 1) return true;
	return false;
}

// 1. 가장 가까운 손님을 찾음 - 이 때, 가장 가까운 거리 > 연료양이면 -1 출력하고 끝내버림
int FindNear()
{
	int minNum = -1;
	bool check[21][21] = { 0, }, flag = false;
	vector<qinfo> candid;

	queue<qinfo> q;
	q.push({ start.first, start.second, 0 });
	check[start.first][start.second] = true;

	if (board[start.first][start.second] > 1)
	{
		minNum = board[start.first][start.second] - 1;
		return minNum;
	}

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().dist;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isWall(nx, ny) || check[nx][ny]) continue;

			if (board[nx][ny])
			{
				if (customer[board[nx][ny] - 2].isArrive)
				{
					check[nx][ny] = true;
					continue;
				}

				if (d + 1 > fuel)
				{
					flag = true;
					minNum = -1;
					continue;
				}
				else
				{
					flag = true;
					candid.push_back({nx, ny, board[nx][ny] - 1 });
					continue;
				}
			}

			if (!flag)
			{
				q.push({ nx, ny, d + 1 });
				check[nx][ny] = true;
			}
		}
	}

	if (candid.size())
	{
		sort(candid.begin(), candid.end(), comparerowcol);
		minNum = candid[0].dist;
	}

	return minNum;
}

// 2. BFS를 사용하여 이동 - 이동하면서 연료 계산하고, 거리 > 연료양이면 -1 출력하고 끝내버림
void GoDest(int num)
{
	int destX = customer[num - 1].dx;
	int destY = customer[num - 1].dy;
	bool check[21][21] = { 0, };

	queue<qinfo> q;
	q.push({ customer[num - 1].sx, customer[num - 1].sy, 0 });

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().dist;
		q.pop();

		if (x == destX && y == destY)
		{
			if (d > fuel)
			{
				fuel = -1;
				return;
			}
			else
			{
				fuel += d;
				start.first = destX;
				start.second = destY;
				customer[num - 1].isArrive = true;
				return;
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (isWall(nx, ny) || check[nx][ny]) continue;

			q.push({ nx, ny, d + 1 });
			check[nx][ny] = true;
		}
	}
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
		cout << fuel << endl;
		GoDest(cNum);
		if (fuel < 0)
		{
			cout << "-1";
			return;
		}
		cout << fuel << endl;
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
