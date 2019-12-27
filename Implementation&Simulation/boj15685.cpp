#include <iostream>
#include <math.h>
using namespace std;

void dragonCurve(int curve[][1024])
{
	for (int i = 0; i < 4; ++i)
	{
		// 0����
		curve[i][0] = i;

		// 1���� ~ 10����
		for (int j = 1; j <= 10; ++j)
		{
			// 2^(j-1)���� 2^j��ŭ �ݺ� ����
			int s = pow(2, j - 1);
			int e = pow(2, j);

			for (int k = s, l = 1; k < e; ++k, l += 2)
			{
				curve[i][k] = (curve[i][k - l] + 1) % 4;
			}
		}
	}
}

int main(void)
{
	// �巡�� Ŀ�� ��
	int k;
	cin >> k;

	// ��
	int map[101][101] = { 0, };

	// �巡�� Ŀ�� ���� (2^10)
	int curve[4][1024] = { 0, };
	dragonCurve(curve);

	for (int i = 0; i < k; ++i)
	{
		// ��ǥ, ����, ����
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		// 2^g��ŭ
		int draw = pow(2, g);

		int currX = x;
		int currY = y;
		map[currY][currX] = 1;

		for (int j = 0; j < draw; ++j)
		{
			if (curve[d][j] == 0)
			{
				currX += 1;
			}
			else if (curve[d][j] == 1)
			{
				currY -= 1;
			}
			else if (curve[d][j] == 2)
			{
				currX -= 1;
			}
			else if (curve[d][j] == 3)
			{
				currY += 1;
			}

			map[currY][currX] = 1;
		}
	}

	int answer = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1])
			{
				answer++;
			}
		}
	}

	cout << answer;
}