// 2020.06.13 01:38~02:31
// 백준 15684 사다리 조작
// DFS

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, h, arr[31][11], answer = 1e9;
bool visited[31][11];

bool CheckGame()
{
	for (int i = 1; i <= n; ++i)
	{
		int currX = i;

		for (int j = 1; j <= h; ++j)
		{
			if (visited[j][currX]) currX++;
			else if (visited[j][currX - 1]) currX--;
		}

		if (currX != i) return false;
	}

	return true;
}

void DFS(int idx, int cnt)
{
	if (cnt == 4) return;

	// i번 세로선의 결과가 i번에 나오는지 판단
	if (CheckGame())
	{
		answer = min(answer, cnt);
		return;
	}
	
	// 사다리 선택
	for (int i = idx; i <= h; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;

			visited[i][j] = true;
			DFS(i, cnt + 1);
			visited[i][j] = false;
		}
	}
}

void Solve()
{
	DFS(1, 0);

	if (answer == 1e9) cout << "-1";
	else cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> h;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		visited[a][b] = true;
	}

	Solve();
}
