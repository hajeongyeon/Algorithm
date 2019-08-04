// 1 L\ 2 ��/ 3 \�� 4 /�� 5 �� 6~10 ��Ȧ -1 ��Ȧ
// �� 1 �� 2 �� 3 �� 4

// ƨ��� ����
// 1 : 2 4 1 3
// 2 : 2 3 4 1
// 3 : 3 1 4 2
// 4 : 4 1 2 3
// 5 : 2 1 4 3

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;				// �ִ� ũ��
int dirX[4] = { 0, 0, 1, -1 };
int dirY[4] = { 1, -1, 0, 0 };

int gamemap[MAX][MAX];				// ������ ���� �迭
vector<pair<int, int>> wormhole[5];	// ��Ȧ ��ġ ���� ��ǥ

int n;								// ������ ũ��
int startX = 0, startY = 0;			// ���� ��ǥ ����
int point = 0;						// ����

int bounceDir(int block, int dir)
{
	if (block == 1)
	{
		if (dir == 0) return 1;
		if (dir == 1) return 3;
		if (dir == 2) return 0;
		if (dir == 3) return 2;
	}
	else if (block == 2)
	{
		if (dir == 0) return 1;
		if (dir == 1) return 2;
		if (dir == 2) return 3;
		if (dir == 3) return 0;
	}
	else if (block == 3)
	{
		if (dir == 0) return 2;
		if (dir == 1) return 0;
		if (dir == 2) return 3;
		if (dir == 3) return 1;
	}
	else if (block == 4)
	{
		if (dir == 0) return 3;
		if (dir == 1) return 0;
		if (dir == 2) return 1;
		if (dir == 3) return 2;
	}
	else if (block == 5)
	{
		if (dir == 0) return 1;
		if (dir == 1) return 0;
		if (dir == 2) return 3;
		if (dir == 3) return 2;
	}
}

void DFS(int a, int b, int dir, int score)
{
	int x = a + dirX[dir];
	int y = b + dirY[dir];

	if (x < 0 || y < 0 || x >= n || y >= n)	// ���� �ε����ٸ�
	{
		int tmp = (score * 2) + 1;
		if (point < tmp) point = tmp;
		return;
	}
	else if (x == startX && y == startY || gamemap[x][y] == -1)	// ���� ����
	{
		if (point < score) point = score;
		return;
	}
	else if (gamemap[x][y] == 0)	// ��� ����
	{
		DFS(x, y, dir, score);
	}
	else if (gamemap[x][y] > 0 && gamemap[x][y] < 6)		// ��Ͽ� �ε����� ��
	{
		dir = bounceDir(gamemap[x][y], dir);
		DFS(x, y, dir, score + 1);
	}
	else if (gamemap[x][y] >= 6 && gamemap[x][y] <= 10)		// ��Ȧ
	{
		int otherX = wormhole[gamemap[x][y] - 6][0].first;
		int otherY = wormhole[gamemap[x][y] - 6][0].second;

		if (otherX == x && otherY == y)
		{
			otherX = wormhole[gamemap[x][y] - 6][1].first;
			otherY = wormhole[gamemap[x][y] - 6][1].second;
		}

		DFS(otherX, otherY, dir, score);
	}
}

int main(void)
{
	int t;		// test case ��
	cin >> t;
	
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		cin >> n;

		// �ʱ�ȭ
		point = 0;
		for (int i = 0; i < 5; i++)
		{
			wormhole[i].clear();
		}

		// ������ �Է�
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> gamemap[i][j];

				if (gamemap[i][j] >= 6 && gamemap[i][j] <= 10)		// ��Ȧ�̸�
				{
					int num = gamemap[i][j] - 6;
					wormhole[num].push_back(make_pair(i, j));
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (gamemap[i][j] == 0)
				{
					for (int k = 0; k < 4; ++k)		// �������� 4�������� 4�� ����
					{
						startX = i, startY = j;

						DFS(startX, startY, k, 0);
					}
				}
			}
		}

		cout << "#" << test_case << " " << point << endl;
	}
}
