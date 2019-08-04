#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 11;

typedef struct {
	int x, y;		// ��ǥ
	int age;		// ����
	bool isDead;	// �׾��°�
} treeinfo;

// �ϼ��ʺ��� �ð����
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

// ��� �迭
int nur[MAX][MAX];
// s2d2�� �ִ� ����� ��
int s2d2[MAX][MAX];
// ���� ���� ���� ����
vector<treeinfo> trees;

int n;		// �� ũ��

bool agesort(treeinfo i1, treeinfo i2)
{
	return i1.age < i2.age;
}

void season()
{
	// spring
	for (int i = 0; i < trees.size(); ++i)
	{
		// ����� �����ϸ�
		if (nur[trees[i].y][trees[i].x] - trees[i].age < 0)
		{
			trees[i].isDead = true;		// ����
		}
		else
		{
			nur[trees[i].y][trees[i].x] -= trees[i].age;
			trees[i].age++;
		}
	}

	// summer
	for (int i = 0; i < trees.size(); ++i)
	{
		if (trees[i].isDead)	// ���� ����
		{
			nur[trees[i].y][trees[i].x] += (trees[i].age / 2);	// ����� ��
			trees.erase(trees.begin() + i);						// ���� ����
		}
	}

	// fall
	for (int i = 0; i < trees.size(); ++i)
	{
		if (trees[i].age % 5 == 0)		// ���̰� 5�� ����̸�
		{
			// 8�������� 1�� ���� ����
			for (int j = 0; j < 8; ++j)
			{
				int nx = trees[i].x + dx[j];
				int ny = trees[i].y + dy[j];

				if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
				
				treeinfo t;
				t.x = nx;
				t.y = ny;
				t.age = 1;
				t.isDead = false;

				trees.push_back(t);
			}
		}
	}

	// winter
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// s2d2�� ��� �߰�
			nur[i][j] += s2d2[i][j];
		}
	}
}

int main(void)
{
	// ���� ����, k��
	int m, k;
	cin >> n >> m >> k;

	// s2d2�� �ִ� ����� �� �Է� ����
	// �ʱ� ����� ��� ĭ�� 5
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> s2d2[i][j];

			nur[i][j] = 5;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int x, y, age;
		cin >> x >> y >> age;
		
		treeinfo t;
		t.x = x;
		t.y = y;
		t.age = age;
		t.isDead = false;

		trees.push_back(t);
	}

	int year = 1;
	while (year <= k)
	{
		sort(trees.begin(), trees.end(), agesort);		// ���� ������ ����

		season();

		year++;
	}

	cout << trees.size() << endl;
}