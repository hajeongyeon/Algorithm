#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k, arr[100001], tmp[100001], one;

void Solve()
{
	int answer = 1e9, s;

	if (one - k < 0) s = 1;
	else s = one - k + 1;

	for (int i = 0; i < k; ++i)
	{
		int chk = 0;
		memset(tmp, 0, sizeof(tmp));

		if (s + i + k > n + 1) break;

		int left, right;
		left = right = s + i;
	
		for (int j = 0; j < k; ++j)
			tmp[s + i + j] = 1;
		chk++;
		right = right + k - 1;

		// left
		while (1)
		{
			if (left <= 1) break;
			chk++;
			left = left - k + 1;
		}
	
		// right
		while (1)
		{
			if (right >= n) break;
			chk++;
			right = right + k - 1;
		}

		if (answer > chk) answer = chk;
	}

	cout << answer;
}

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];

		if (arr[i] == 1) one = i;
	}

	Solve();

	return 0;
}