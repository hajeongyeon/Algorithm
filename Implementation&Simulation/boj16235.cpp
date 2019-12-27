#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 11;

typedef struct {
	int x, y;		// ��ǥ
	int age;		// ����
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

void season()
{
	vector<treeinfo> deadtrees;		// ���� ���� ���� ���� ����
	vector<treeinfo> alivetrees;	// ����ִ� ���� ���� ���� ����
	vector<treeinfo> fivetrees;		// 5�� ���� ���� ���� ����
	vector<treeinfo> birthtrees;	// �¾ ���� ���� ���� ����

	// spring
	for (int i = 0; i < trees.size(); ++i)
	{
		// ����� �����ϸ�
		if (nur[trees[i].x][trees[i].y] - trees[i].age < 0)
		{
			deadtrees.push_back(trees[i]);	// ���� ������ ������ �־���
		}
		else
		{
			nur[trees[i].x][trees[i].y] -= trees[i].age;
			trees[i].age++;

			alivetrees.push_back(trees[i]);		// ����ִ� ������ ������ �־���

			if (trees[i].age % 5 == 0)			// ���̰� 5�� ����̸�
			{
				fivetrees.push_back(trees[i]);	// 5���� �� ������ ������ �־���
			}
		}
	}

	// summer
	for (int i = 0; i < deadtrees.size(); ++i)
	{
		nur[deadtrees[i].x][deadtrees[i].y] += (deadtrees[i].age / 2);	// ����� ��
	}

	// fall
	for (int i = 0; i < fivetrees.size(); ++i)
	{
		// 8�������� 1�� ���� ����
		for (int j = 0; j < 8; ++j)
		{
 			int nx = fivetrees[i].x + dx[j];
			int ny = fivetrees[i].y + dy[j];

			if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;

			birthtrees.push_back({ nx, ny, 1 });		// �¾ ������ ���� ����
		}
	}

	// winter
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			// s2d2�� ��� �߰�
			nur[i][j] += s2d2[i][j];
		}
	}

	// 1���� ���� ��
	trees.clear();		// ���� ���� ����

	for (int i = 0; i < birthtrees.size(); ++i)
	{
		trees.push_back(birthtrees[i]);		// �¾ ���� ���� ���� ����
	}

	for (int i = 0; i < alivetrees.size(); ++i)
	{
		trees.push_back(alivetrees[i]);		// ����ִ� ���� ���� ����
	}

	// ���� �ʱ�ȭ
	deadtrees.clear();
	alivetrees.clear();
	fivetrees.clear();
	birthtrees.clear();
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
		
		trees.push_back({x, y, age});
	}

	int year = 1;
	while (year <= k)
	{
		season();

		year++;
	}

	cout << trees.size() << endl;
}