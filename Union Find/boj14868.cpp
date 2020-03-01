/*
����ϴٰ� https://akim9905.tistory.com/25 �����߽��ϴ�
������ �Ʒ� �ڵ�� ����ϰ� while������ answer �������� �ָ鼭 board�� 0�̸� merge ���ִ� ������ �ߴµ�
�׽�Ʈ���̽����� Ʋ������������.... ����ؼ� �����ؼ� Ǯ�����ϴ� �Ф�
���߿� �ٽ� Ǯ�����...................................
*/

#include <iostream>
#include <queue>
using namespace std;

int n, k, group[100001], board[2001][2001];
queue<pair<int, int>> init, civil;

int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

int Find(int x)
{
	if (x == group[x]) return x;
	return group[x] = Find(group[x]);
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return true;

	group[b] = a;
	return false;
}

void m_BFS()
{
	while (!init.empty())
	{
		int x = init.front().first;
		int y = init.front().second;
		civil.push({ x, y });
		init.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;

			if (board[nx][ny] && board[x][y] != board[nx][ny])
				if (!Union(board[x][y], board[nx][ny])) k--;
		}
	}
}

void s_BFS()
{
	while (!civil.empty())
	{
		int x = civil.front().first;
		int y = civil.front().second;
		civil.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;

			if (!board[nx][ny])
			{
				board[nx][ny] = board[x][y];
				init.push({ nx, ny });
			}
		}
	}
}

void Solve()
{
	int answer = 0;

	while (1)
	{
		m_BFS();

		if (k == 1)
		{
			cout << answer;
			return;
		}

		s_BFS();
		answer++;
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;

	int a, b;
	for (int i = 1; i <= k; ++i)
	{
		cin >> a >> b;
		init.push({ a, b });
		group[i] = i;
		board[a][b] = i;
	}

	Solve();
}