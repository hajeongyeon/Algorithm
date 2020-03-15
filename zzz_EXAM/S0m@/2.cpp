#include <iostream>
#include <cstring>
using namespace std;

int n, m, arr[50][50];
bool visited[50][50];

bool isRange(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	return true;
}

void Solve()
{
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int dd[4][3] = { {0, 1, 3}, {1, 2, 4}, {3, 5, 6}, {4, 6, 7} };

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!arr[i][j]) continue;
			if (visited[i][j]) continue;

			for (int k = 0; k < 4; ++k)
			{
				bool chk = false;
				for (int l = 0; l < 3; ++l)
				{
					if (!isRange(i + dx[dd[k][l]], j + dy[dd[k][l]])) chk = true;
					if (!arr[i + dx[dd[k][l]]][j + dy[dd[k][l]]]) chk = true;

					if (chk) break;
				}

				if (chk) continue;

				visited[i][j] = true;
				visited[i + dx[dd[k][0]]][j + dy[dd[k][0]]] = true;
				visited[i + dx[dd[k][1]]][j + dy[dd[k][1]]] = true;
				visited[i + dx[dd[k][2]]][j + dy[dd[k][2]]] = true;

				break;
			}
		}
	}

	bool chk = false;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visited[i][j] && arr[i][j]) chk = true;
			if (chk) break;
		}

		if (chk) break;
	}

	if (chk) cout << "NO";
	else cout << "YES";
}

int main() 
{
	int t; cin >> t;

	for (int tc = 0; tc < t; ++tc)
	{
		memset(arr, 0, sizeof(arr));

		cin >> n >> m;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> arr[i][j];

		Solve();
	}
}