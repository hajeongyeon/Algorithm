// N�� 0, S�� 1
// 12�ù������ �ð���� �������
// ���� 1 �ð�, -1 �ݽð�

// 1�� : 12�� N�� 0 / S�� 1
// 2�� : 12�� N�� 0 / S�� 2
// 3�� : 12�� N�� 0 / S�� 4
// 4�� : 12�� N�� 0 / S�� 8

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
	if (dir == 1)	// �ð� ����
	{
		int tmp = arr[idx][7];

		for (int i = 7; i >= 0; --i)
		{
			arr[idx][i] = arr[idx][i - 1];
		}

		arr[idx][0] = tmp;
	}
	else			// �ݽð� ����
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
	if (idx < 0) return;					// ���ʿ� ��Ϲ����� ������

	if (arr[idx][2] != arr[idx + 1][6])		// �ٸ� ���̸�
	{
		Left(arr, idx - 1, -dir);
		Rotation(arr, idx, dir);
	}
}

void Right(int arr[][8], int idx, int dir)
{
	if (idx > 3) return;					// �����ʿ� ��Ϲ����� ������

	if (arr[idx][6] != arr[idx - 1][2])		// �ٸ� ���̸�
	{
		Right(arr, idx + 1, -dir);
		Rotation(arr, idx, dir);
	}
}

int main(void)
{
	int arr[4][8];		// ��Ϲ��� ����

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