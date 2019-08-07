#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 50;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> virus;		// 바이러스 벡터
queue<pair<int, int>> spreadVirus;	// 뿌릴 바이러스 큐
int selectedVirus[10] = { 0, };		// 선택된 바이러스

// 연구소 크기, 바이러스 개수
int n, m;

int map[MAX][MAX];	// 연구소
int tmp[MAX][MAX];	// 거리 저장 배열

int emptySpace = 0;		// 빈 공간 수

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

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;	// 범위를 나가면

			if (map[nx][ny] != 1 && tmp[nx][ny] == -1)	// 벽이 아니고 바이러스가 활성이 되지 않았다면
			{
				tmp[nx][ny] = tmp[x][y] + 1;			// 시간+1 해서 tmp 배열에 넣어줌

				if (map[nx][ny] == 0)					// 빈 공간이면 바이러스 활성, 추가된 시간 spreadTime에 저장
				{
					active++;
					spreadTime = tmp[nx][ny];
				}
				
				spreadVirus.push(make_pair(nx, ny));	// 활성된 바이러스 큐에 추가
			}
		}
	}

	// 활성된 바이러스 수와 맨 처음의 빈 공간 수가 같으면 answer과 확산시간 중 최소값을 answer에 저장
	if (active == emptySpace) answer = min(answer, spreadTime);
}

// 조합. (virus.size)Combination(m) -> 재귀
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

			// 바이러스를 놓을 수 있으면
			if (map[i][j] == 2)
			{
				// 벡터에 좌표를 넣어줌
				virus.push_back(make_pair(i, j));
			}

			// 빈 공간이면
			if (map[i][j] == 0) emptySpace++;
		}
	}

	Combination(virus.size(), m);

	if (answer == 9999999) cout << "-1" << endl;
	else cout << answer << endl;
}