#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 50;

int map[MAX][MAX];		// �α� �� ���� �迭
int visited[MAX][MAX];	// Ž���ߴ��� �Ǵ�
vector<pair<int, int>> v;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// �� ũ��, �α� ����(l~r)
int n, l, r;
int unppl = 0;		// ���� �α�
int un = 0;			// ���� ����

void DFS(int y, int x)
{
	for (int i = 0; i < 4; ++i)		// �������� 4����
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		int diff = abs(map[y][x] - map[ny][nx]);
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			// �α� �� ���̰� l �̻� r ������ ��
			if (l <= diff && diff <= r && !visited[ny][nx])
			{
				visited[ny][nx] = true;

				v.push_back(make_pair(ny, nx));
				unppl += map[ny][nx];
				un++;

				DFS(ny, nx);
			}
		}
	}
}

int main(void)
{
	cin >> n >> l >> r;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];
		}
	}

	int answer = 0;

	while (1)
	{
		memset(visited, false, sizeof(visited));

		bool move = false;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (visited[i][j]) continue;	// �湮�ߴٸ�

				visited[i][j] = true;
				unppl = map[i][j];
				un = 1;

				v.clear();
				v.push_back(make_pair(i, j));

				DFS(i, j);

				// ������ �����Ѵٸ�
				if (un >= 2)
				{
					move = true;	// �α��̵�
					
					for (int k = 0; k < v.size(); ++k)
					{
						map[v[k].first][v[k].second] = unppl / un;
					}
				}
			}
		}

		if (move) answer++;
		else break;
	}

	cout << answer;
}