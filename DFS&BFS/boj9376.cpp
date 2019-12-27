#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

/*
	ó�� BFS ���ο��� queue�� �������� �� 1�� �������� ù��° �׽�Ʈ���̽��� ���
	priority queue�� deque �� �ٷ� ���� �õ�. ����� �����
	���� �ƴϰ�, �湮�� ���� �ʾ��� �� ���̸� 1�� �����ְ�
	1) priority queue
	- dist[nx][ny][num] > nextDist�̸� dist[nx][ny][num]�� nextDist�� �־��ְ�
	- �湮 �迭 true
	- nextDist ���������� ���� nx, ny push
	2) deque
	- ���̸� deque�� back�� push
	- ���� �ƴϸ� deque�� front�� push
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
				if (dist[nx][ny][lv] >= 0) continue;	// �̹� �湮

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

			// ���� �ѹ��� ���� ������ ��ǥ�� ���̸� 2�� ��
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
			// �ܰ��� ��������� �ѷ���
			if (i == 0 || i == h + 1 || j == 0 || j == w + 1) board[i][j] = '.';
			else cin >> board[i][j];

			if (board[i][j] == '$')
			{
				board[i][j] = '.';
				prisoner.push_back({ i, j });
			}
		}
	}

	// ����� ��ǥ
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