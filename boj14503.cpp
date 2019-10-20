// 백준 14503 로봇 청소기
// BFS

#include <iostream>
#include <queue>
using namespace std;

// 좌표, 방향
struct robot {
	int x, y, d;
};

int N, M, r, c, d;
int area[50][50];				// 맵
bool visited[50][50] = { 0, };	// 방문
int answer = 0;

// 범위를 벗어나는지 체크하는 함수
bool isRange(int nx, int ny)
{
	if (nx < 0 || ny < 0 || nx >= N || ny >= M) return false;
	return true;
}

void Solution()
{
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	queue<robot> q;
	q.push({ r, c, d });
	visited[r][c] = true;
	answer++;

	// d 경우 체크하는 boolean 변수
	bool flag = false;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().d;
		q.pop();

		for (int i = 1; i <= 5; ++i)
		{
			// 네 방향 모두 청소가 되어있거나 벽이면
			if (i == 5)
			{
				// 후진을 위한 새로운 좌표
				int nx = x - dx[dir];
				int ny = y - dy[dir];

				// d. 뒤쪽 방향이 벽이라 후진도 할 수 없다면 종료
				if (!isRange(nx, ny) || area[nx][ny])
				{
					flag = true;
					break;
				}

				// c. 후진
				q.push({ nx, ny, dir });
				break;
			}

			// 반시계 방향으로 방향 전환
			int cd = (dir - i + 4) % 4;

			int nx = x + dx[cd];
			int ny = y + dy[cd];

			// b. 왼쪽에 청소할 공간이 없다면 회전
			if (!isRange(nx, ny) || area[nx][ny] || visited[nx][ny]) continue;

			// a. 청소하지 않은 공간이 존재한다면 회전하고 한 칸 전진
			q.push({ nx, ny, cd });
			visited[nx][ny] = true;
			answer++;
			break;
		}

		if (flag) break;
	}

	cout << answer;
}

void Input()
{
	cin >> N >> M >> r >> c >> d;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> area[i][j];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Input();

	Solution();
}
