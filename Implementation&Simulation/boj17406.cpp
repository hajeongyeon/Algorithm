#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct rotinfo {
	int r, c, s;
};

int N, M, K;
int board[51][51];
int tmpboard[51][51];
vector<rotinfo> rotInfo;

void Input()
{
	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> board[i][j];

	for (int i = 0; i < K; ++i)
	{
		int r, c, s;
		cin >> r >> c >> s;

		rotInfo.push_back({ r, c, s });
	}
}

int changeDir(int d)
{
	if (d == 0) return 3;
	else if (d == 1) return 2;
	else if (d == 2) return 0;
	else if (d == 3) return 1;
}

void Rotation(rotinfo ri)
{
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	int r = ri.r;
	int c = ri.c;
	int s = ri.s;

	int start[2] = { r - s, c - s };
	int finish[2] = { r + s, c + s };

	int turn = (finish[0] - start[0]) / 2;

	for (int i = 0; i < turn; ++i)
	{
		int x = start[0], y = start[1];
		int tmp = tmpboard[x][y];
		int dir = 2;

		while (1)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx == start[0] && ny == start[1])
			{
				tmpboard[x][y] = tmp;
				break;
			}

			if (start[0] <= nx && nx <= finish[0] - i && start[1] <= ny && ny <= finish[1] - i)
			{
				tmpboard[x][y] = tmpboard[nx][ny];
				x = nx;
				y = ny;
			}
			else
				dir = changeDir(dir);
		}

		start[0]++;
		start[1]++;
	}
}

void Solve()
{
	vector<int> vec;
	for (int i = 0; i < K; ++i)
		vec.push_back(i);

	int answer = 1e9;
	do {
		memcpy(tmpboard, board, sizeof(tmpboard));

		for (int i = 0; i < vec.size(); ++i)
			Rotation(rotInfo[vec[i]]);

		int candidate = 1e9;
		for (int i = 1; i <= N; ++i)
		{
			int rowSum = 0;

			for (int j = 1; j <= M; ++j)
				rowSum += tmpboard[i][j];

			candidate = min(candidate, rowSum);
		}

		answer = min(answer, candidate);
	} while (next_permutation(vec.begin(), vec.end()));

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}