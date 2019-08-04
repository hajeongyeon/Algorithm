#include <iostream>
using namespace std;

int main(void)
{
	int tc;		// test case;
	cin >> tc;

	// °ÅÁÖ¹Î ÀúÀå 2Â÷¿ø ¹è¿­
	int arr[15][15] = { 1, };

	// 0Ãþ
	for (int i = 1; i <= 14; ++i)
	{
		arr[0][i] = i;
	}

	// 1È£
	for (int i = 1; i <= 14; ++i)
	{
		arr[i][1] = 1;
	}

	for (int test_case = 1; test_case <= tc; ++test_case)
	{
		int k, n;			// kÃþ nÈ£
		cin >> k;
		cin >> n;

		for (int i = 1; i <= k; ++i)		// Ãþ
		{
			for (int j = 2; j <= n; ++j)	// È£
			{
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}

		cout << arr[k][n] << endl;
	}
}