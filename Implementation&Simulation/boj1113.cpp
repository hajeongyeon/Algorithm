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

	// �� �߿� ���� ���� ����
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

			// ��� ��
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			// �̹� �湮
			if (visited[nx][ny]) continue;
			// �ٱ� �׵θ��̰�, �׵θ��� ������ ���� ���̺��� �۰ų� ������ break
			if (!(nx > 0 && ny > 0 && nx < N - 1 && ny < M - 1) && board[nx][ny] <= h)
			{
				minHeight = 1e9;
				while (!q.empty()) q.pop();
				break;
			}

			// ���� ������ ���� ���̺��� ������ break
			if (board[nx][ny] < h)
			{
				minHeight = 1e9;
				while (!q.empty()) q.pop();
				break;
			}
			// ���� ������ ���� ���̶� �����鼭 �׵θ��� �ƴϸ� push
			else if (board[nx][ny] == h)
			{
				if(nx > 0 && ny > 0 && nx < N - 1 && ny < M - 1)
					q.push({ nx, ny });
			}
			// ���� ������ ���� ���̺��� ũ�� �ּ� ���̸� ������
			else
			{
				minHeight = min(minHeight, board[nx][ny]);
			}

			visited[nx][ny] = true;
		}
	}

	// �������� ���� �� ����
	if (minHeight != 1e9)
	{
		while (!pool.empty())
		{
			pair<int, int> p = pool.front();
			pool.pop();

			// �����忡 ���� �� �ִ� ���� ���� answer�� �־���
			answer += minHeight - board[p.first][p.second];
			// ���� �ּ� ���̸�ŭ board�� ä������
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
		���� case ������ i,j for�� 9ȸ �ݺ�
		��, (N-1, M-1)�� 9�� �ɶ����� �ݺ������ ��..
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