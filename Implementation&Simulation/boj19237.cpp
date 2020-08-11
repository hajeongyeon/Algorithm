// 2020.08.11 16:30~19:55
// 백준 19237 어른 상어
// 완전탐색

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shark {
	int x, y, dir;
	bool isLive;
};

struct MapInfo {
	vector<int> vec;
	int sharknum, smelltime;
};

int n, m, k;
MapInfo board[20][20];
int priority[402][5][4];

Shark shark[21];

void Input()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int input; cin >> input;

			if (input)
			{
				board[i][j].vec.push_back(input);
				shark[input].x = i;
				shark[input].y = j;
			}

			board[i][j].smelltime = 0;
			board[i][j].sharknum = 0;
		}
	}
	
	for (int i = 1; i <= m; ++i)
	{
		int input; cin >> input;

		shark[i].dir = input;
		shark[i].isLive = true;
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				cin >> priority[i][j][k];
			}
		}
	}
}

bool checkLive()
{
	for (int i = 2; i <= m; ++i)
		if (shark[i].isLive) return false;
	return true;
}

void SettingSmell(int t)
{
	for (int i = 1; i <= m; ++i)
	{
		if (!shark[i].isLive) continue;

		int x = shark[i].x;
		int y = shark[i].y;

		board[x][y].sharknum = i;
		board[x][y].smelltime = t + k;
	}
}

void MovingShark(int t)
{
	int dx[5] = { 0, -1, 1, 0, 0 };
	int dy[5] = { 0, 0, 0, -1, 1 };

	for (int i = 1; i <= m; ++i)
	{
		if (!shark[i].isLive) continue;
		board[shark[i].x][shark[i].y].vec.clear();
	}

	for (int i = 1; i <= m; ++i)
	{
		if (!shark[i].isLive) continue;

		int x = shark[i].x;
		int y = shark[i].y;
		int currdir = shark[i].dir;

		bool isFind = false;
		Shark saveself = { -1, -1, -1 };

		for (int j = 0; j < 4; ++j)
		{
			int newdir = priority[i][currdir][j];

			int nx = x + dx[newdir];
			int ny = y + dy[newdir];

			// 벽을 넘어서면 continue
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			if (board[nx][ny].smelltime <= t)
			{
				board[nx][ny].vec.push_back(i);
				shark[i].x = nx;
				shark[i].y = ny;
				shark[i].dir = newdir;

				isFind = true;
				break;
			}
			else
			{
				// 우선순위 가장 먼저인 자신의 냄새를 만나면 일단 저장해놓음
				if (board[nx][ny].sharknum == i)
				{
					if (saveself.dir == -1)
						saveself = { nx, ny, newdir };
				}
			}
		}

		if (!isFind)
		{
			// 끝까지 빈공간을 못 찾으면 미리 저장해놨던 saveself를 옮긺
			board[saveself.x][saveself.y].vec.push_back(i);
			shark[i].x = saveself.x;
			shark[i].y = saveself.y;
			shark[i].dir = saveself.dir;
		}
	}
}

void ExpellingShark()
{
	for (int i = 1; i <= m; ++i)
	{
		if (!shark[i].isLive) continue;

		int x = shark[i].x;
		int y = shark[i].y;

		if (board[x][y].vec.size() >= 2)
		{
			sort(board[x][y].vec.begin(), board[x][y].vec.end());
			int liveshark = board[x][y].vec[0];

			for (int j = 1; j < board[x][y].vec.size(); ++j)
				shark[board[x][y].vec[j]].isLive = false;

			board[x][y].vec.clear();
			board[x][y].vec.push_back(liveshark);
			board[x][y].sharknum = liveshark;
		}
	}
}

void Solve()
{
	for (int t = 0; t < 1001; ++t)
	{
		if (checkLive())
		{
			cout << t;
			return;
		}

		// 냄새 뿌림
		SettingSmell(t);
		// 우선순위에 따라 상어 이동
		MovingShark(t);
		// 상어 내쫓기
		ExpellingShark();
	}

	cout << "-1";
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
