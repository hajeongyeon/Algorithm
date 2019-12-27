#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int board[51][51];
bool visited[51][51];

int dx[4] = { -1, 1, 0 , 0 };
int dy[4] = { 0, 0 , -1, 1 };

int answer = 0;

void FindPool(int x, int y, int h)
{
	// (x, y) queue
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	// pool queue
	queue<pair<int, int>> pool;

	// 벽 중에 가장 작은 높이
	int minHeight = 1e9;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		pool.push({ x, y });

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 경계 밖
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			// 이미 방문
			if (visited[nx][ny]) continue;
			// 바깥 테두리이고, 테두리가 수영장 안의 높이보다 작거나 같으면 break
			if (!(nx > 0 && ny > 0 && nx < N - 1 && ny < M - 1) && board[nx][ny] <= h)
			{
				minHeight = 1e9;
				while (!q.empty()) q.pop();
				break;
			}

			// 벽이 수영장 안의 높이보다 작으면 break
			if (board[nx][ny] < h)
			{
				minHeight = 1e9;
				while (!q.empty()) q.pop();
				break;
			}
			// 벽과 수영장 안의 높이랑 같으면서 테두리가 아니면 push
			else if (board[nx][ny] == h)
			{
				if(nx > 0 && ny > 0 && nx < N - 1 && ny < M - 1)
					q.push({ nx, ny });
			}
			// 벽이 수영장 안의 높이보다 크면 최소 높이를 구해줌
			else
			{
				minHeight = min(minHeight, board[nx][ny]);
			}

			visited[nx][ny] = true;
		}
	}

	// 수영장을 만들 수 있음
	if (minHeight != 1e9)
	{
		while (!pool.empty())
		{
			pair<int, int> p = pool.front();
			pool.pop();

			// 수영장에 넣을 수 있는 물의 양을 answer에 넣어줌
			answer += minHeight - board[p.first][p.second];
			// 벽의 최소 높이만큼 board에 채워넣음
			board[p.first][p.second] = minHeight;
		}
	}
}

void Solve()
{
	/*
		5 9
		999999999
		999999999
		999999999
		976543219
		999999999
		같은 case 때문에 i,j for문 9회 반복
		즉, (N-1, M-1)가 9가 될때까지 반복해줘야 함..
	*/

	for (int T = 1; T < 10; ++T)
	{
		for (int i = 1; i < N - 1; ++i)
		{
			for (int j = 1; j < M - 1; ++j)
			{
				memset(visited, 0, sizeof(visited));

				FindPool(i, j, board[i][j]);
			}
		}
	}

	cout << answer;
}

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char input;
			cin >> input;

			board[i][j] = input - '0';
		}
	} 
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}