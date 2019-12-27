#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 101;

struct Shark {
	int speed;	// �ӵ�
	int dir;	// ����
	int size;	// ũ��
};

// ���Ͽ���
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// ������ ũ��
int R, C;

vector<Shark> shark[MAX][MAX];	// ��� ���� ���� ����

bool in_Range(int x, int y)
{
	if (x < 1 || y < 1 || x > R || y > C) return false;

	return true;
}

void moveShark(int x, int y, int speed, int dir, int size)
{
	int nx = 0, ny = 0;

	for (int i = 0; i < speed; ++i)
	{
		nx = x + dx[dir - 1];
		ny = y + dy[dir - 1];

		// ������ ����� �ݴ��������
		if (!in_Range(nx, ny))
		{
			if (dir == 1) dir = 2;
			else if (dir == 2) dir = 1;
			else if (dir == 3) dir = 4;
			else if (dir == 4) dir = 3;
		}

		x += dx[dir - 1];
		y += dy[dir - 1];
	}

	// �̹� ĭ�� �� ������
	if (shark[x][y].size() != 0)
	{
		// ����� ���� ���� �� �� ũ��
		if (shark[x][y].at(0).size < size)
		{
			shark[x][y].clear();
			// ���� ����� ���� ����
			shark[x][y].push_back({ speed, dir, size });
		}
	}
	else
	{
		shark[x][y].push_back({ speed, dir, size });
	}
}

int main(void)
{
	// ��� ������
	int M;
	cin >> R >> C >> M;

	for (int i = 0; i < M; ++i)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		shark[r][c].push_back({ s, d, z });
	}

	int answer = 0;

	// ����
	for (int i = 1; i <= C; ++i)
	{
		// ���ÿ��̶� ���� ����� �� ����
		for (int j = 1; j <= R; ++j)
		{
			if (shark[j][i].size() != 0)
			{
				answer += shark[j][i].at(0).size;
				shark[j][i].clear();
				break;
			}
		}

		queue<pair<vector<Shark>, pair<int, int>>> tmpQ;	// �ӽ� ���� ť

		// �ӽ� ���� Q�� ��� ���Ϳ� ��ǥ ����
		for (int j = 1; j <= R; ++j)
		{
			for (int k = 1; k <= C; ++k)
			{
				if (shark[j][k].size() != 0)
				{
					tmpQ.push(make_pair(shark[j][k], make_pair(j, k)));
					shark[j][k].clear();
				}
			}
		}

		// ��� �̵�
		while (!tmpQ.empty())
		{
			int x = tmpQ.front().second.first;
			int y = tmpQ.front().second.second;
			int speed = tmpQ.front().first.at(0).speed;
			int dir = tmpQ.front().first.at(0).dir;
			int size = tmpQ.front().first.at(0).size;
			tmpQ.pop();

			moveShark(x, y, speed, dir, size);
		}
	}

	cout << answer << endl;
}