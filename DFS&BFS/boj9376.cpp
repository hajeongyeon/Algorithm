#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

/*
	처음 BFS 내부에서 queue로 접근했을 땐 1번 예제에서 첫번째 테스트케이스만 통과
	priority queue랑 deque 둘 다로 접근 시도. 방식은 비슷함
	벽이 아니고, 방문을 하지 않았을 때 문이면 1을 더해주고
	1) priority queue
	- dist[nx][ny][num] > nextDist이면 dist[nx][ny][num]에 nextDist을 넣어주고
	- 방문 배열 true
	- nextDist 내림차순에 따라 nx, ny push
	2) deque
	- 문이면 deque의 back에 push
	- 문이 아니면 deque의 front에 push
*/

int h, w;

char board[105][105];
int dist[105][105][3];
deque<pair<int, int>> prisoner;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void BFS()
{
	for (int lv = 0; lv < 3; ++lv)
	{
		int px = prisoner.back().first;
		int py = prisoner.back().second;
		prisoner.pop_back();

		deque<pair<int, int>> dq;
		dq.push_back({ px, py });
		dist[px][py][lv] = 0;

		while (!dq.empty())
		{
			int x = dq.front().first;
			int y = dq.front().second;
			dq.pop_front();

			cout << x << " " << y << endl;

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1) continue;
				if (board[nx][ny] == '*') continue;
				if (dist[nx][ny][lv] >= 0) continue;	// 이미 방문

				if (board[nx][ny] == '#')
				{
					dist[nx][ny][lv] = dist[x][y][lv] + 1;
					dq.push_back({ nx, ny });
				}
				else if (board[nx][ny] == '.')
				{
					dist[nx][ny][lv] = dist[x][y][lv];
					dq.push_front({ nx, ny });
				}
			}
		}
	}
}

void Solve()
{
	int answer = 1e9;

	BFS();

	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			if (board[i][j] == '*') continue;

			int tmp = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];

			// 문은 한번만 열기 때문에 좌표가 문이면 2를 뺌
			if (board[i][j] == '#') tmp -= 2;
			if (answer > tmp) answer = tmp;
		}
	}

	cout << answer << "\n";
}

void Input()
{
	memset(dist, -1, sizeof(dist));

	cin >> h >> w;

	for (int i = 0; i <= h + 1; ++i)
	{
		for (int j = 0; j <= w + 1; ++j)
		{
			// 외곽을 빈공간으로 둘러쌈
			if (i == 0 || i == h + 1 || j == 0 || j == w + 1) board[i][j] = '.';
			else cin >> board[i][j];

			if (board[i][j] == '$')
			{
				board[i][j] = '.';
				prisoner.push_back({ i, j });
			}
		}
	}

	// 상근이 좌표
	prisoner.push_back({ 0, 0 });
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		Input();
		Solve();
	}
}