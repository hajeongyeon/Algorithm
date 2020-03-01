/*
고민하다가 https://akim9905.tistory.com/25 참고했습니다
원래는 아래 코드랑 비슷하게 while문에서 answer 증가시켜 주면서 board가 0이면 merge 해주는 식으로 했는데
테스트케이스부터 틀려버리더라고요.... 답답해서 참고해서 풀었습니다 ㅠㅠ
나중에 다시 풀려고요...................................
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