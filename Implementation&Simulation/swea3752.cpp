#include <iostream>
using namespace std;

int main(void)
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; ++i)
	{
		int n = 0;
		cin >> n;

		int* score = new int[n];
		int result[10000] = { 0, };

		int max = 0;
		result[0] = 1;

		for (int j = 0; j < n; ++j)
		{
			cin >> score[j];
			max += score[j];

			for (int k = max; k >= 0; --k)
			{
				if (result[k] > 0)
				{
					result[k + score[j]]++;
				}
			}
		}

		int answer = 0;
		for (int j = 0; j < 10000; ++j)
		{
			if (result[j] > 0)
			{
				answer++;
			}
		}

		cout << "#" << i << " " << answer << endl;

		delete[] score;
	}
}