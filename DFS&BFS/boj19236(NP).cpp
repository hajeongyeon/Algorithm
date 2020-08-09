// 2020.08.09 19:20~
// 백준 1926 청소년 상어
// 

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct info {
	int x, y, dir;
};

int answer;
info fish[17], tmpfish;
int board[4][4], tmpboard[4][4];
bool visited[4][4];

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void Input()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int a, b; cin >> a >> b;

			fish[a] = { i, j, b - 1 };
			board[i][j] = a;
		}
	}

	for (int i = 1; i <= 16; ++i)
	{
		cout << i << " : " << fish[i].x << " " << fish[i].y << " " << fish[i].dir << endl;
	}
	cout << endl;
}

bool isMoving(int x, int y)
{
	if (x < 0 || y < 0 || x >= 4 || y >= 4) return false;
	return true;
}

void ChangeFish(int x, int y, int num, int dir, int nx, int ny)
{
	int changenum = board[nx][ny];
	int changedir = fish[changenum].dir;

	board[nx][ny] = num;
	board[x][y] = changenum;

	fish[num] = { nx, ny, dir };
	fish[changenum] = { x, y, changedir };
}

void MovingFish()
{
	for (int i = 1; i <= 16; ++i)
	{
		int x = fish[i].x;
		int y = fish[i].y;
		int dir = fish[i].dir;

		cout << x << " " << y << endl;

		if (visited[x][y]) continue;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// 물고기 이동이 가능하면 위치를 서로 바꿈
		if (isMoving(nx, ny) && !visited[nx][ny]) ChangeFish(x, y, i, dir, nx, ny);
		// 불가능하면 45도 반시계 방향으로 돌림
		else
		{
			for (int j = 1; j < 8; ++j)
			{
				dir = (fish[i].dir + j) % 8;

				nx = x + dx[dir];
				ny = y + dy[dir];

				if (isMoving(nx, ny) && !visited[nx][ny])
				{
					ChangeFish(x, y, i, dir, nx, ny);
					break;
				}
			}
		}

		cout << i << " : " << fish[i].x << " " << fish[i].y << " " << fish[i].dir << endl;
	}

	cout << endl;
	for (int i = 1; i <= 16; ++i)
	{
		cout << i << " : " << fish[i].x << " " << fish[i].y << " " << fish[i].dir<< endl;
	}
}

void DFS(int x, int y, int candid)
{
	int dir = fish[board[x][y]].dir;
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (!isMoving(nx, ny) || visited[nx][ny])
	{
		answer = max(answer, candid);
		cout << answer << endl;
		return;
	}

	visited[x][y] = true;
	MovingFish();
	memcpy(tmpboard, board, sizeof(tmpboard));
	memcpy(&tmpfish, &fish, sizeof(tmpfish));

	for (int i = 1; i <= 3; ++i)
	{
		nx = x + dx[dir] * i;
		ny = y + dy[dir] * i;

		if (!isMoving(nx, ny) || visited[nx][ny]) continue;
		else
		{
			cout << nx << " " << ny << endl;

			DFS(nx, ny, candid + board[nx][ny]);

			visited[nx][ny] = false;
			memcpy(board, tmpboard, sizeof(board));
			memcpy(&fish, &tmpfish, sizeof(fish));

			//for (int a = 0; a < 4; ++a)
			//{
			//	for (int b = 0; b < 4; ++b)
			//		cout << board[a][b] << " ";
			//	cout << endl;
			//}
		}
	}
}

void Solve()
{
	int candid = board[0][0];

	DFS(0, 0, candid);

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
