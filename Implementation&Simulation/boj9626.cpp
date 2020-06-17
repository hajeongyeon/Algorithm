// 2020.06.17 17:37~17:51
// 백준 9626 크로스워드 퍼즐
// 구현

#include <iostream>
using namespace std;

int n, m, u, l, r, d;
char board[20][20];

void Solve()
{
	cin >> m >> n >> u >> l >> r >> d;

	for (int i = 0; i < m + u + d; ++i)
	{
		for (int j = 0; j < n + l + r; ++j)
		{
			if ((i + j) % 2 == 0) board[i][j] = '#';
			else board[i][j] = '.';
		}
	}

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i + u][j + l];

	for (int i = 0; i < m + u + d; ++i)
	{
		for (int j = 0; j < n + l + r; ++j)
			cout << board[i][j];
		cout << "\n";
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Solve();
}
