// 크기 n*m 지도
// 좌표 r, c (r은 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로부터 떨어진 칸의 개수)
// 윗면 1, 동쪽 3, 좌표 (x, y), 가장 처음에는 모든 면에 0
// 주사위를 굴렸을 때 이동한 칸에 쓰여져 있는 수가 0이면 바닥면에 쓰여 있는 수가 칸에 복사
// 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
// 주사위 전개도
//   0
// 0 0 0
//   0
//   0

#include <iostream>
using namespace std;

int main(void)
{
	int n, m;	// 지도 크기
	int x, y;	// 주사위를 놓은 곳의 좌표
	int k;		// 명령의 개수
	int coord[21][21] = { 0, };		// 지도
	int dirX[4] = { 0, 0, -1, 1 };
	int dirY[4] = { 1, -1, 0, 0 };

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> coord[i][j];
		}
	}

	int top = 0, bottom = 0, left = 0, right = 0, front = 0, rear = 0;	// 주사위 6면
	int tmp = 0;				// 저장
	int nx = 0, ny = 0;			// 이동할 위치 
	int currX = x, currY = y;	// 현재 위치
	int dir = 0;				// 방향

	for (int i = 0; i < k; ++i)
	{
		cin >> dir;

		// 현재 위치
		nx = currX + dirX[dir - 1];
		ny = currY + dirY[dir - 1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (dir == 1)		// 동
		{
			tmp = right;
			right = top;
			top = left;
			left = bottom;
			bottom = coord[nx][ny];
		}
		else if (dir == 2)	// 서
		{
			tmp = left;
			left = top;
			top = right;
			right = bottom;
			bottom = coord[nx][ny];
		}
		else if (dir == 3)	// 북
		{
			tmp = rear;
			rear = top;
			top = front;
			front = bottom;
			bottom = coord[nx][ny];
		}
		else if (dir == 4)	// 남
		{
			tmp = front;
			front = top;
			top = rear;
			rear = bottom;
			bottom = coord[nx][ny];
		}

		if (coord[nx][ny] == 0)
		{
			coord[nx][ny] = tmp;
			bottom = tmp;
		}
		else
		{
			coord[nx][ny] = 0;
		}

		currX = nx;
		currY = ny;

		cout << top << endl;
	}
}