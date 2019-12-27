// ũ�� n*m ����
// ��ǥ r, c (r�� �������κ��� ������ ĭ�� ����, c�� �������κ��� ������ ĭ�� ����)
// ���� 1, ���� 3, ��ǥ (x, y), ���� ó������ ��� �鿡 0
// �ֻ����� ������ �� �̵��� ĭ�� ������ �ִ� ���� 0�̸� �ٴڸ鿡 ���� �ִ� ���� ĭ�� ����
// 0�� �ƴ� ��쿡�� ĭ�� ���� �ִ� ���� �ֻ����� �ٴڸ����� ����Ǹ�, ĭ�� ���� �ִ� ���� 0�� �ȴ�.
// �ֻ��� ������
//   0
// 0 0 0
//   0
//   0

#include <iostream>
using namespace std;

int main(void)
{
	int n, m;	// ���� ũ��
	int x, y;	// �ֻ����� ���� ���� ��ǥ
	int k;		// ����� ����
	int coord[21][21] = { 0, };		// ����
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

	int top = 0, bottom = 0, left = 0, right = 0, front = 0, rear = 0;	// �ֻ��� 6��
	int tmp = 0;				// ����
	int nx = 0, ny = 0;			// �̵��� ��ġ 
	int currX = x, currY = y;	// ���� ��ġ
	int dir = 0;				// ����

	for (int i = 0; i < k; ++i)
	{
		cin >> dir;

		// ���� ��ġ
		nx = currX + dirX[dir - 1];
		ny = currY + dirY[dir - 1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (dir == 1)		// ��
		{
			tmp = right;
			right = top;
			top = left;
			left = bottom;
			bottom = coord[nx][ny];
		}
		else if (dir == 2)	// ��
		{
			tmp = left;
			left = top;
			top = right;
			right = bottom;
			bottom = coord[nx][ny];
		}
		else if (dir == 3)	// ��
		{
			tmp = rear;
			rear = top;
			top = front;
			front = bottom;
			bottom = coord[nx][ny];
		}
		else if (dir == 4)	// ��
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