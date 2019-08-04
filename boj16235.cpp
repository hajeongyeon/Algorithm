#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 11;

typedef struct {
	int x, y;		// 좌표
	int age;		// 나이
	bool isDead;	// 죽었는가
} treeinfo;

// 북서쪽부터 시계방향
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

// 양분 배열
int nur[MAX][MAX];
// s2d2가 주는 양분의 수
int s2d2[MAX][MAX];
// 나무 정보 저장 벡터
vector<treeinfo> trees;

int n;		// 땅 크기

bool agesort(treeinfo i1, treeinfo i2)
{
	return i1.age < i2.age;
}

void season()
{
	// spring
	for (int i = 0; i < trees.size(); ++i)
	{
		// 양분이 부족하면
		if (nur[trees[i].y][trees[i].x] - trees[i].age < 0)
		{
			trees[i].isDead = true;		// 죽음
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
		if (trees[i].isDead)	// 죽은 나무
		{
			nur[trees[i].y][trees[i].x] += (trees[i].age / 2);	// 양분이 됨
			trees.erase(trees.begin() + i);						// 정보 삭제
		}
	}

	// fall
	for (int i = 0; i < trees.size(); ++i)
	{
		if (trees[i].age % 5 == 0)		// 나이가 5의 배수이면
		{
			// 8방향으로 1살 나무 생성
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
			// s2d2가 양분 추가
			nur[i][j] += s2d2[i][j];
		}
	}
}

int main(void)
{
	// 나무 개수, k년
	int m, k;
	cin >> n >> m >> k;

	// s2d2가 주는 양분의 수 입력 받음
	// 초기 양분은 모든 칸이 5
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
		sort(trees.begin(), trees.end(), agesort);		// 나이 순으로 정렬

		season();

		year++;
	}

	cout << trees.size() << endl;
}