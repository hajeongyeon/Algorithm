#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int idx;
int arr[100001];
int dp[100001][5][5];

int DP(const int& cnt, const int& left, const int& right)
{
	if (idx == cnt) return 0;

	int& ret = dp[cnt][left][right];
	if (ret != 0) return ret;

	ret = 1e9;
	int next = arr[cnt];

	// left
	if (next == left)
		ret = min(DP(cnt + 1, next, right) + 1, ret);
	else
	{
		if (left == 0)
			ret = min(DP(cnt + 1, next, right) + 2, ret);
		else
		{
			if (abs(next - left) == 2)
				ret = min(DP(cnt + 1, next, right) + 4, ret);
			else
				ret = min(DP(cnt + 1, next, right) + 3, ret);
		}
	}

	// right
	if (next == right)
		ret = min(DP(cnt + 1, left, next) + 1, ret);
	else
	{
		if (right == 0)
			ret = min(DP(cnt + 1, left, next) + 2, ret);
		else
		{
			if (abs(next - right) == 2)
				ret = min(DP(cnt + 1, left, next) + 4, ret);
			else
				ret = min(DP(cnt + 1, left, next) + 3, ret);
		}
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (1)
	{
		int a;
		cin >> a;

		if (!a) break;

		arr[idx++] = a;
	}

	cout << DP(0, 0, 0);
}
