#include <iostream>
using namespace std;

int main(void)
{
	int tc;		// test case;
	cin >> tc;

	// ���ֹ� ���� 2���� �迭
	int arr[15][15] = { 1, };

	// 0��
	for (int i = 1; i <= 14; ++i)
	{
		arr[0][i] = i;
	}

	// 1ȣ
	for (int i = 1; i <= 14; ++i)
	{
		arr[i][1] = 1;
	}

	for (int test_case = 1; test_case <= tc; ++test_case)
	{
		int k, n;			// k�� nȣ
		cin >> k;
		cin >> n;

		for (int i = 1; i <= k; ++i)		// ��
		{
			for (int j = 2; j <= n; ++j)	// ȣ
			{
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}

		cout << arr[k][n] << endl;
	}
}