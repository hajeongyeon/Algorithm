#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 50;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> virus;		// ���̷��� ����
queue<pair<int, int>> spreadVirus;	// �Ѹ� ���̷��� ť
int selectedVirus[10] = { 0, };		// ���õ� ���̷���

// ������ ũ��, ���̷��� ����
int n, m;

int map[MAX][MAX];	// ������
int tmp[MAX][MAX];	// �Ÿ� ���� �迭

int emptySpace = 0;		// �� ���� ��

int answer = 9999999;

void BFS()
{	
	int active = 0, spreadTime = 0;

	while (!spreadVirus.empty())
	{
		int x = spreadVirus.front().first, y = spreadVirus.front().second;
		spreadVirus.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;	// ������ ������

			if (map[nx][ny] != 1 && tmp[nx][ny] == -1)	// ���� �ƴϰ� ���̷����� Ȱ���� ���� �ʾҴٸ�
			{
				tmp[nx][ny] = tmp[x][y] + 1;			// �ð�+1 �ؼ� tmp �迭�� �־���

				if (map[nx][ny] == 0)					// �� �����̸� ���̷��� Ȱ��, �߰��� �ð� spreadTime�� ����
				{
					active++;
					spreadTime = tmp[nx][ny];
				}
				
				spreadVirus.push(make_pair(nx, ny));	// Ȱ���� ���̷��� ť�� �߰�
			}
		}
	}

	// Ȱ���� ���̷��� ���� �� ó���� �� ���� ���� ������ answer�� Ȯ��ð� �� �ּҰ��� answer�� ����
	if (active == emptySpace) answer = min(answer, spreadTime);
}

// ����. (virus.size)Combination(m) -> ���
void Combination(int n, int r)
{
	if (n == r)
	{
		for (int i = 0; i < n; ++i)
		{
			selectedVirus[i] = 1;
		}

		memset(tmp, -1, sizeof(tmp));

		for (int i = 0; i < 10; ++i)
		{
			if (selectedVirus[i] == 1)
			{
				spreadVirus.push({ virus[i].first, virus[i].second });
				tmp[virus[i].first][virus[i].second] = 0;
			}
		}

		BFS();

		for (int i = 0; i < n; ++i)
		{
			selectedVirus[i] = 0;
		}
		return;
	}
	if (r == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			selectedVirus[i] = 1;

			memset(tmp, -1, sizeof(tmp));

			for (int j = 0; j < 10; ++j)
			{
				if (selectedVirus[j] == 1)
				{
					spreadVirus.push({ virus[j].first, virus[j].second });
					tmp[virus[j].first][virus[j].second] = 0;
				}
			}

			BFS();

			selectedVirus[i] = 0;
		}
		return;
	}
	
	selectedVirus[n - 1] = 1;
	Combination(n - 1, r - 1);
	selectedVirus[n - 1] = 0;
	Combination(n - 1, r);
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> map[i][j];

			// ���̷����� ���� �� ������
			if (map[i][j] == 2)
			{
				// ���Ϳ� ��ǥ�� �־���
				virus.push_back(make_pair(i, j));
			}

			// �� �����̸�
			if (map[i][j] == 0) emptySpace++;
		}
	}

	Combination(virus.size(), m);

	if (answer == 9999999) cout << "-1" << endl;
	else cout << answer << endl;
}