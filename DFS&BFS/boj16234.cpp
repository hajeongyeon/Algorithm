#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 50;

int map[MAX][MAX];		// 인구 수 저장 배열
int visited[MAX][MAX];	// 탐색했는지 판단
vector<pair<int, int>> v;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// 땅 크기, 인구 차이(l~r)
int n, l, r;
int unppl = 0;		// 연합 인구
int un = 0;			// 연합 나라

void DFS(int y, int x)
{
	for (int i = 0; i < 4; ++i)		// 동서남북 4방향
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		int diff = abs(map[y][x] - map[ny][nx]);
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			// 인구 수 차이가 l 이상 r 이하일 때
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
				if (visited[i][j]) continue;	// 방문했다면

				visited[i][j] = true;
				unppl = map[i][j];
				un = 1;

				v.clear();
				v.push_back(make_pair(i, j));

				DFS(i, j);

				// 연합이 존재한다면
				if (un >= 2)
				{
					move = true;	// 인구이동
					
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