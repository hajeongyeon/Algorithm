#include <iostream>
#include <algorithm>
using namespace std;

int N;
int board[101][101];

void Solve()
{
	int maximum[101] = { 0, };
	bool check[101] = { 0, };
	int cnt = 0;
	int committee[101] = { 0, };

	// 플로이드-와샬 알고리즘
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if(board[i][j] < 1e9 && board[i][j] > maximum[i])
				maximum[i] = board[i][j];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!check[i])
		{
			int tmp = i;
			for (int j = i; j <= N; ++j)
			{
				if (board[i][j] < 1e9)
				{
					check[j] = 1;
					if (maximum[tmp] > maximum[j]) tmp = j;
				}
			}
			committee[cnt++] = tmp;
		}
	}

	sort(committee, committee + cnt);
	cout << cnt << "\n";
	for (int i = 0; i < cnt; ++i) cout << committee[i] << "\n";
}

void Input()
{
	int M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j) board[i][j] = 0;
			else board[i][j] = 1e9;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = board[b][a] = 1;
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}