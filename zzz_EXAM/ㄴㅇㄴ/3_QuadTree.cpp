#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int board[64][64];

void Input()
{
	memset(board, 0, sizeof(board));

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}
}

bool FindMinMax(int n, int x, int y)
{
	int MAX[4] = { 0, };

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + (i / 2) * n;
		int ny = y + (i % 2) * n;

		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				MAX[i] = max(MAX[i], board[nx + j][ny + k]);
			}
		}
	}

	int realMax = 0;
	int MIN = 1e9;

	for (int i = 0; i < 4; ++i)
	{
		realMax = max(realMax, MAX[i]);
		MIN = min(MIN, MAX[i]);
	}
	
	double multi = MIN * 1.2;

	if (multi >= realMax)
	{
		cout << "1";
		return true;
	}
	else
	{
		cout << "0";
		return false;
	}
}

void QuadTree(int n, int x, int y)
{
	// 기저 조건
	if (n == 2) return;

	int half = n / 2;

	// 기저 조건
	if (FindMinMax(half, x, y))
	{
		QuadTree(half, x, y);
		QuadTree(half, x, y + half);
		QuadTree(half, x + half, y);
		QuadTree(half, x + half, y + half);

		return;
	}

	return;
}

void Solve(int tc)
{
	cout << "#" << tc << " ";
	QuadTree(N, 0, 0);
	cout << "\n";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc)
	{
		Input();
		Solve(tc);
	}
}