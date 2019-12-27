#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int h, w;
char board[105][105];
bool visited[105][105];
bool key[26];

void BFS()
{
	int document = 0;

	queue<pair<int, int>> q;
	queue<pair<int, int>> door[26];
	q.push({ 0, 0 });
	visited[0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 경계 밖
			if (nx < 0 || ny < 0 || nx >= h + 2 || ny >= w + 2) continue;
			// 벽
			if (board[nx][ny] == '*') continue;
			// 이미 방문
			if (visited[nx][ny]) continue;

			// 문
			if ('A' <= board[nx][ny] && board[nx][ny] <= 'Z')
			{
				// 열쇠 있음
				if (key[board[nx][ny] - 'A']) q.push({ nx, ny });
				// 열쇠 없음
				else door[board[nx][ny] - 'A'].push({ nx, ny });
			}
			// 열쇠
			else if ('a' <= board[nx][ny] && board[nx][ny] <= 'z')
			{
				q.push({ nx, ny });
				if (!key[board[nx][ny] - 'a'])
				{
					key[board[nx][ny] - 'a'] = true;
					while (!door[board[nx][ny] - 'a'].empty())
					{
						q.push({ door[board[nx][ny] - 'a'].front() });
						door[board[nx][ny] - 'a'].pop();
					}
				}
			}
			// 문서
			else if (board[nx][ny] == '$')
			{
				q.push({ nx, ny });
				document++;
				board[nx][ny] = '.';
			}
			// 빈공간
			else q.push({ nx, ny });

			visited[nx][ny] = true;
		}
	}

	cout << document << "\n";
}

void Input()
{
	cin >> h >> w;

	memset(board, '.', sizeof(board));

	// 경계를 .으로 두를 것이기 때문에 1부터 h, w까지
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			cin >> board[i][j];
		}
	}

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '0') break;
		else key[str[i] - 'a'] = true;
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		Input();
		BFS();

		memset(visited, 0, sizeof(visited));
		memset(key, 0, sizeof(key));
	}
}