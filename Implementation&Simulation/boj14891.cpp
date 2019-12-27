// N극 0, S극 1
// 12시방향부터 시계방향 순서대로
// 방향 1 시계, -1 반시계

// 1번 : 12시 N극 0 / S극 1
// 2번 : 12시 N극 0 / S극 2
// 3번 : 12시 N극 0 / S극 4
// 4번 : 12시 N극 0 / S극 8

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int twopow(int n)
{
	int result = 1;

	if (n == 0) {
		return 1;
	}	
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			result *= 2;
		}
	}

	return result;
}

void Rotation(int arr[][8], int idx, int dir)
{
	if (dir == 1)	// 시계 방향
	{
		int tmp = arr[idx][7];

		for (int i = 7; i >= 0; --i)
		{
			arr[idx][i] = arr[idx][i - 1];
		}

		arr[idx][0] = tmp;
	}
	else			// 반시계 방향
	{
		int tmp = arr[idx][0];

		for (int i = 0; i < 7; ++i)
		{
			arr[idx][i] = arr[idx][i + 1];
		}

		arr[idx][7] = tmp;
	}
}

void Left(int arr[][8], int idx, int dir)
{
	if (idx < 0) return;					// 왼쪽에 톱니바퀴가 없으면

	if (arr[idx][2] != arr[idx + 1][6])		// 다른 극이면
	{
		Left(arr, idx - 1, -dir);
		Rotation(arr, idx, dir);
	}
}

void Right(int arr[][8], int idx, int dir)
{
	if (idx > 3) return;					// 오른쪽에 톱니바퀴가 없으면

	if (arr[idx][6] != arr[idx - 1][2])		// 다른 극이면
	{
		Right(arr, idx + 1, -dir);
		Rotation(arr, idx, dir);
	}
}

int main(void)
{
	int arr[4][8];		// 톱니바퀴 상태

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int num, dir;
		cin >> num >> dir;

		num--;

		Left(arr, num - 1, -dir);
		Right(arr, num + 1, -dir);
		Rotation(arr, num, dir);
	}

	int answer = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (arr[i][0] == 1)
			answer += twopow(i);
	}

	cout << answer;
}