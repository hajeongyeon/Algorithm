#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int n, k, l, board[100][100];
queue<pair<int, int>> dir;
deque<pair<int, int>> snake;

void Input()
{
	cin >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		int a, b; cin >> a >> b;
		board[a - 1][b - 1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; ++i)
	{
		int a;
		char b;
		cin >> a >> b;
		
		if (b == 'D') dir.push({ a, 1 });
		else dir.push({ a, 2 });
	}

	snake.push_back({ 0, 0 });
}

void Solve()
{
	bool flag = false;
	int cnt = 0, d = 0;
	// ������ �������� �ð����
	int dx[4] = { 0, 1, 0, -1};
	int dy[4] = { 1, 0, -1, 0 };

	while (1)
	{
		cnt++;

		// ���� �Ӹ�
		int nx = snake.front().first + dx[d];
		int ny = snake.front().second + dy[d];

		// ���� �ε����� break
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
		// ���̶� �ε����� break
		for (int i = 0; i < snake.size(); ++i)
		{
			if (nx == snake[i].first && ny == snake[i].second)
			{
				flag = true;
				break;
			}
		}
		if (flag) break;

		// ����� ������ �Ӹ��� deque�� �߰�
		if (board[nx][ny] == 1)
		{
			snake.push_front({ nx, ny });
			board[nx][ny] = 0;
		}
		// ������ ������ ���
		else
		{
			deque<pair<int, int>> tmp = snake;

			for (int i = 1; i < snake.size(); ++i)
			{
				snake[i].first = tmp[i - 1].first;
				snake[i].second = tmp[i - 1].second;
			}
			snake[0].first += dx[d];
			snake[0].second += dy[d];
		}

		// ���� ��ȯ
		if (!dir.empty() && dir.front().first == cnt)
		{
			if (dir.front().second == 1) // D
				d = (d + 1) % 4;
			else // L
				d = (d - 1 + 4) % 4;

			dir.pop();
		}
	}

	cout << cnt;
}

int main(void)
{
	ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	Input();
	Solve();
}