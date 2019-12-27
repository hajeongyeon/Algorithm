// ��ǥ�� �Ÿ� ����
// �Ÿ��� ª�� �� ����
// �Ÿ��� ������ y�� ���� �� ����
// y�� ���ٸ� x�� ���� �� ����

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// ��� ����ü
struct shark {
	int x, y;	// ��ǥ
	int dist;	// �Ÿ�

	bool operator < (const shark &s) const
	{
		if (dist == s.dist)
		{
			if (y == s.y)
			{
				return x > s.x;
			}
			else
			{
				return y > s.y;
			}
		}
		else
		{
			return dist > s.dist;
		}
	}
};

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int n;							// ���� ũ��
int map[20][20];				// ����
priority_queue<shark> q;		// shark ���� ���� �켱���� ť

int BFS()
{
	bool check[20][20];			// �湮�ߴ���
	memset(check, false, sizeof(check));

	int sharkage = 2;			// ��� ����
	int eat = 0;				// ���� ����� ��
	int answer = 0;

	while (!q.empty())
	{
		int x = q.top().x, y = q.top().y, dist = q.top().dist;
		q.pop();

		// ����� ���� �� ������
		if (map[y][x] > 0 && map[y][x] < sharkage)
		{
			map[y][x] = 0;	// ����� ����
			eat++;

			if (eat == sharkage)	// ���� ������� ���� ���̶� ������
			{
				sharkage++;
				eat = 0;
			}

			answer += dist;

			dist = 0;

			memset(check, false, sizeof(check));
			while (!q.empty()) q.pop();
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;	// ������ �Ѿ��
			if (check[ny][nx]) continue;							// �̹� �湮�ߴٸ�
			if (map[ny][nx] > sharkage) continue;					// ������� ũ�Ⱑ ���� ũ��

			q.push({ nx, ny, dist + 1 });
			check[ny][nx] = true;
		}
	}

	return answer;
}

int main(void)
{
	cin >> n;

	// i�� ����, j�� ����
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];

			// �Ʊ� �� �ִ� ��ġ
			if (map[i][j] == 9)
			{
				q.push({ i, j, 0 });
				map[i][j] = 0;
			}
		}
	}

	cout << BFS() << endl;
}