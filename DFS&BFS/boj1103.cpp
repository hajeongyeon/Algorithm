#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int board[50][50], dp[50][50];
bool visited[50][50];
bool flag;

int DFS(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m) return 0;
	if (visited[x][y] && !dp[x][y]) flag = true;
	if (dp[x][y]) return dp[x][y];
	if (flag) return -1;

	int num = board[x][y];
	if (num == -1) return 0;
	visited[x][y] = true;

	int result = 0;
	result = max(result, DFS(x - num, y));
	result = max(result, DFS(x + num, y));
	result = max(result, DFS(x, y - num));
	result = max(result, DFS(x, y + num));

	if (flag) return -1;

	return dp[x][y] = result + 1;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char tmp; cin >> tmp;
			
			if (tmp == 'H') board[i][j] = -1;
			else board[i][j] = tmp - '0';
		}
	}

	cout << DFS(0, 0);
}