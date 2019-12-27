#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 5;

int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

struct Coord {
	int x, y, z;	// 3���� ��ǥ
	int dist;		// �Ÿ�
};

// ��, ��, ��
int map[MAX][MAX][MAX];		// ����
int copyMap[MAX][MAX][MAX];	// ���纻

int degree[MAX];						// ���� ���� �迭
int order[MAX] = { 0, 1, 2, 3, 4 };		// �״� ���� ���� �迭

int answer = 1e9;

// �̷� �ʱ�ȭ
void InitMaze()
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			for (int k = 0; k < MAX; ++k)
			{
				copyMap[i][j][k] = 1;
			}
		}
	}
}

// 4. �ִܰŸ� Ž��
void BFS()
{
	queue<Coord> q;
	q.push({0, 0, 0, 0});

	int visited[MAX][MAX][MAX] = { 0, };
	visited[0][0][0] = true;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int dist = q.front().dist;
		q.pop();

		// ����
		if (x == 4 && y == 4 && z == 4)
		{
			answer = min(answer, dist);

			if (answer == 12)
			{
				cout << answer;
				exit(0);
			}

			return;
		}

		// 6����
		for (int i = 0; i < 6; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			// ���� �����
			if (nx < 0 || ny < 0 || nz < 0 || nx >= MAX || ny >= MAX || nz >= MAX) continue;
			// �����ְų�, �̹� �湮�ߴٸ�
			if (copyMap[nz][nx][ny] == 0 || visited[nz][nx][ny]) continue;

			visited[nz][nx][ny] = true;
			q.push({ nx, ny, nz, dist + 1 });
		}
	}
}

// 3. �̷θ� �����.
void MakeMaze()
{
	InitMaze();

	for (int i = 0; i < MAX; ++i)
	{
		int d = degree[i];	// ����
		int o = order[i];	// �״� ����

		if (d == 0)	// 0��
		{
			for (int j = 0; j < MAX; ++j)
			{
				for (int k = 0; k < MAX; ++k)
				{
					copyMap[i][j][k] = map[o][j][k];
				}
			}
		}
		else if (d == 1) // 90��
		{
			for (int j = 0; j < MAX; ++j)
			{
				for (int k = 0; k < MAX; ++k)
				{
					copyMap[i][k][4 - j] = map[o][j][k];
				}
			}
		}
		else if (d == 2) // 180��
		{
			for (int j = 0; j < MAX; ++j)
			{
				for (int k = 0; k < MAX; ++k)
				{
					copyMap[i][4 - j][4 - k] = map[o][j][k];
				}
			}
		}
		else if (d == 3) // 270��
		{
			for (int j = 0; j < MAX; ++j)
			{
				for (int k = 0; k < MAX; ++k)
				{
					copyMap[i][4 - k][j] = map[o][j][k];
				}
			}
		}
	}
}

// 2. ȸ�� : 0��/90��/180��/360�� 4�� �߿� 5���� ����. --> �ߺ�����(4��5)
void RotateBoard(int depth)
{
	if (depth == MAX)
	{
		MakeMaze();

		if (copyMap[0][0][0] == 1 && copyMap[4][4][4] == 1) BFS();

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		degree[depth] = i;
		RotateBoard(depth + 1);
	}
}

// 1. �� 5���� �״µ�, ������ ���Ѵ�. --> ����(5P5)
void StackCube()
{
	do
	{
		RotateBoard(0);
	} while (next_permutation(order, order+5));
}

int main(void)
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			for (int k = 0; k < MAX; ++k)
			{
				cin >> map[i][j][k];
			}
		}
	}

	StackCube();

	if (answer == 1e9) cout << "-1";
	else cout << answer;
}