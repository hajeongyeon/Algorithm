#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

string str, realstr = " ";
int minDiv[2501];
int dp[2501][2501];

int Palindrome(int s, int e)
{
	if (s >= e) return 1;

	int& ret = dp[s][e];
	if (ret != -1) return ret;

	if (realstr[s] != realstr[e]) return 0;

	return ret = Palindrome(s + 1, e - 1);
}

int FindMin()
{
	minDiv[0] = 0;

	for (int i = 1; i <= str.length(); ++i)
	{
		minDiv[i] = 1e9;

		for (int j = 1; j <= i; ++j)
		{
			if (Palindrome(j, i))
				minDiv[i] = min(minDiv[i], minDiv[j - 1] + 1);
		}
	}

	return minDiv[str.length()];
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> str;
	realstr += str;

	memset(dp, -1, sizeof(dp));
	cout << FindMin();
}