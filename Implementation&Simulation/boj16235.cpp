#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 11;

typedef struct {
	int x, y;		// 좌표
	int age;		// 나이
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

void season()
{
	vector<treeinfo> deadtrees;		// 죽은 나무 정보 저장 벡터
	vector<treeinfo> alivetrees;	// 살아있는 나무 정보 저장 벡터
	vector<treeinfo> fivetrees;		// 5살 나무 정보 저장 벡터
	vector<treeinfo> birthtrees;	// 태어난 나무 정보 저장 벡터

	// spring
	for (int i = 0; i < trees.size(); ++i)
	{
		// 양분이 부족하면
		if (nur[trees[i].x][trees[i].y] - trees[i].age < 0)
		{
			deadtrees.push_back(trees[i]);	// 죽은 나무의 정보를 넣어줌
		}
		else
		{
			nur[trees[i].x][trees[i].y] -= trees[i].age;
			trees[i].age++;

			alivetrees.push_back(trees[i]);		// 살아있는 나무의 정보를 넣어줌

			if (trees[i].age % 5 == 0)			// 나이가 5의 배수이면
			{
				fivetrees.push_back(trees[i]);	// 5살이 된 나무의 정보를 넣어줌
			}
		}
	}

	// summer
	for (int i = 0; i < deadtrees.size(); ++i)
	{
		nur[deadtrees[i].x][deadtrees[i].y] += (deadtrees[i].age / 2);	// 양분이 됨
	}

	// fall
	for (int i = 0; i < fivetrees.size(); ++i)
	{
		// 8방향으로 1살 나무 생성
		for (int j = 0; j < 8; ++j)
		{
 			int nx = fivetrees[i].x + dx[j];
			int ny = fivetrees[i].y + dy[j];

			if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;

			birthtrees.push_back({ nx, ny, 1 });		// 태어난 나무의 정보 저장
		}
	}

	// winter
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			// s2d2가 양분 추가
			nur[i][j] += s2d2[i][j];
		}
	}

	// 1년이 지난 후
	trees.clear();		// 나무 정보 삭제

	for (int i = 0; i < birthtrees.size(); ++i)
	{
		trees.push_back(birthtrees[i]);		// 태어난 나무 정보 먼저 저장
	}

	for (int i = 0; i < alivetrees.size(); ++i)
	{
		trees.push_back(alivetrees[i]);		// 살아있는 나무 정보 저장
	}

	// 정보 초기화
	deadtrees.clear();
	alivetrees.clear();
	fivetrees.clear();
	birthtrees.clear();
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