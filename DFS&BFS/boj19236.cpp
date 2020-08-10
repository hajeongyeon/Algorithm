// 1차 시도 2020.08.09 19:20~
// 2차 시도 2020.08.10 19:10~20:25
// 백준 1926 청소년 상어
// DFS

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct info {
	int x, y, dir;
	bool live;
};

int answer;
info fish[17];
int board[4][4];

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void Input()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int a, b; cin >> a >> b;

			fish[a] = { i, j, b - 1, true };
			board[i][j] = a;
		}
	}
}

bool isMoving(int x, int y)
{
	if (x < 0 || y < 0 || x >= 4 || y >= 4) return false;
	return true;
}

// 물고기가 있는 칸으로 이동 시, 물고기의 좌표를 서로 바꾸는 함수
void ChangeFish(int idx, int newidx)
{
	info tmp = fish[idx];
	fish[idx].x = fish[newidx].x;
	fish[idx].y = fish[newidx].y;
	fish[newidx].x = tmp.x;
	fish[newidx].y = tmp.y;
}

// 물고기 이동 함수
void MovingFish()
{
	for (int i = 1; i <= 16; ++i)
	{
		if (!fish[i].live) continue;

		int x = fish[i].x;
		int y = fish[i].y;
		int dir = fish[i].dir;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		bool isMove = false;

		// 물고기 이동이 가능하면 위치를 서로 바꿈
		if (isMoving(nx, ny))
		{
			// 물고기가 없는 칸으로 물고기 이동
			if (!board[nx][ny])
			{
				isMove = true;
				fish[i].x = nx;
				fish[i].y = ny;
				board[nx][ny] = i;
				board[x][y] = 0;
			}
			// 그게 아니라면 물고기 위치를 서로 바꿈
			else if (board[nx][ny] != -1)
			{
				isMove = true;
				ChangeFish(i, board[nx][ny]);
				swap(board[x][y], board[nx][ny]);
			}
		}

		// 불가능하면 45도 반시계 방향으로 돌림
		if(!isMove)
		{
			for (int j = 1; j < 8; ++j)
			{
				int ndir = (fish[i].dir + j) % 8;
				nx = x + dx[ndir];
				ny = y + dy[ndir];

				// 물고기 이동이 가능하면 위치를 서로 바꿈
				if (isMoving(nx, ny))
				{
					// 물고기가 없는 칸으로 물고기 이동
					if (!board[nx][ny])
					{
						fish[i].x = nx;
						fish[i].y = ny;
						board[nx][ny] = i;
						board[x][y] = 0;
						fish[i].dir = ndir;
						break;
					}
					// 그게 아니라면 물고기 위치를 서로 바꿈
					else if (board[nx][ny] != -1)
					{
						ChangeFish(i, board[nx][ny]);
						swap(board[x][y], board[nx][ny]);
						fish[i].dir = ndir;
						break;
					}
				}
			}
		}
	}
}

void DFS(int x, int y, int dir, int sum)
{
	answer = max(answer, sum);

	// 현재 상태 저장
	int tmpboard[4][4];
	info tmpfish[20];
	memcpy(tmpboard, board, sizeof(tmpboard));
	memcpy(&tmpfish, &fish, sizeof(tmpfish));

	MovingFish();

	for (int i = 1; i <= 3; ++i)
	{
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;

		// 움직이는 것이 불가능하면 다음 칸들도 이동 불가니 break
		if (!isMoving(nx, ny)) break;
		// 단순히 물고기가 없는 칸이라면 continue
		if (!board[nx][ny]) continue;
		
		int newnum = board[nx][ny];
		int newdir = fish[newnum].dir;

		board[x][y] = 0;
		board[nx][ny] = -1;
		fish[newnum].live = false;

		DFS(nx, ny, newdir, sum + newnum);

		board[x][y] = -1;
		board[nx][ny] = newnum;
		fish[newnum].live = true;
	}

	memcpy(board, tmpboard, sizeof(board));
	memcpy(&fish, &tmpfish, sizeof(fish));
}

void Solve()
{
	int num = board[0][0];
	int dir = fish[num].dir;
	fish[num].live = false;
	board[0][0] = -1;

	DFS(0, 0, dir, num);

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();
	Solve();
}
